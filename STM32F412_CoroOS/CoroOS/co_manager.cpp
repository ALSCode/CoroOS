// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#include <coroutine>
#include <limits>

#include "critical_section.hpp"
#include "co_queue_impl.hpp"
#include "co_manager.hpp"

static bool mutex_take (co_sync_t sync);
static void co_resume (co_sync_t sync);

using sync_queue_t = CoQueueImpl<co_sync_t, CoParam::CORO_TASK_NUM, co_critical_t>;

co_sync_t co_repo[CoParam::CORO_TASK_NUM];
sync_queue_t co_queue_repo[CoPrio::num];

co_sync_t current;


void CoManager::set_action(co_act_t act) noexcept{

    for (auto sync : co_repo){

        if (not sync) continue;

        if(act == sync->expected)
            co_queue_repo[sync->prio].push(sync);
    }
};

void CoManager::store_sync(co_sync_t s) noexcept{

        co_assert(s->id < CoParam::CORO_TASK_NUM, __func__);

        co_repo[s->id] = s;
}

void CoManager::run(){

    for (auto& queue : co_queue_repo){

        while ( not queue.is_empty() ) {

            co_sync_t sync = queue.back();

            if ( not current ||
            	 CoState::suspended == current->state ){

            	queue.pop();

                current = sync;
            
                co_resume(current); 

            } else if (CoState::running == current->state   &&
                        sync->prio < current->prio          ){

            	queue.pop();

                current->state = CoState::blocked;

                co_sync_t preemted = current;

                current = sync;

                co_resume(current);

                preemted->state = CoState::running;

                current = preemted;

            } else {
            	return;
            }
        }
    }
}


static void co_resume (co_sync_t sync){

    if( not mutex_take(sync) ) return; 
    
    sync->state = CoState::running;

    sync->expected = std::numeric_limits<co_act_t>::max();

    co_detail::enable_irq();

    std::coroutine_handle<>::from_address(sync->address).resume(); 

    co_detail::disable_irq();
}

static bool mutex_take (co_sync_t sync){
    
    bool *mutex_ptr = sync->mutex.ptr;

    if ( mutex_ptr && (*mutex_ptr) ) return false;

    if (mutex_ptr) *mutex_ptr = true;

    return true;
}
