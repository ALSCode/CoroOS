// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_TASK_HPP_
#define INC_CO_TASK_HPP_

#pragma once

#include <coroutine>
#include <limits>

#include "co_proxy.hpp"
#include "co_alloc.hpp"

struct Coro {

    using promise_type = Coro;

    CoSync sync {
        .mutex{.ptr = nullptr, .is_taken = false},
        .address{nullptr},
	    .state{CoState::stopped},
        .prio{CoPrio::lowest},
        .id{ indexer_t{}() },
        .size{0},
        .expected{std::numeric_limits<co_act_t>::max()},
    };

	auto get_return_object() const noexcept {

		return Coro{};
	}

	std::suspend_never initial_suspend() noexcept {
            
        sync.state = CoState::ready;
        sync.size = CoAlloc::get_current_size();

        return {};
    }

	std::suspend_never final_suspend() const noexcept { 
        return {};
    }

	void return_void() const noexcept {}

	void unhandled_exception() {
        std::abort();
    }

    template<co_act_t ID, CoPrio P>
    auto yield_value ( co_proxy_t<ID, P> p) const noexcept {

        struct Awaitable{

            co_proxy_t<ID, P> proxy;

			bool await_ready () const noexcept {

                if (nullptr == proxy.mutex.ptr) return false;

                return proxy.mutex.is_taken;
            }

			void await_suspend (std::coroutine_handle<promise_type> coro) noexcept {

                co_sync_t sync = &coro.promise().sync;

                if (CoState::ready == sync->state) [[unlikely]]
                    decltype(proxy)::store_sync(sync);

                sync->address = coro.address();
                sync->mutex = proxy.mutex;
                sync->state = CoState::suspended;
                sync->prio = P;
                sync->expected = ID;
            }

			auto await_resume () noexcept {

				return 0;
			}
		};
            
		return Awaitable{p};
	}

    template<co_act_t ID, CoPrio P>
    auto await_transform(co_proxy_t<ID, P> p) const noexcept {
        return yield_value<ID, P>(p);
    }

    void* operator new(std::size_t sz){
        return CoAlloc::allocate(sz);
	}

	void operator delete( void* p){
        CoAlloc::deallocate(p);
	}
};

#endif /* INC_CO_TASK_HPP_ */
