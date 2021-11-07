// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#include <chrono>
#include <tuple>
#include "co_proxy.hpp"
#include "co_queue_impl.hpp"
#include "co_chrono.hpp"

#include "main.h"

using namespace std::chrono;

struct PlatformClock{
  using duration = std::chrono::duration<base_t, std::milli>;
  using rep = duration::rep;
  using period =  duration::period;
  using time_point = std::chrono::time_point<PlatformClock, duration>;

  static constexpr bool is_steady = false;

  static time_point now() {
    // пример к статье будет реализован на stm-ке,
    // поэтому, не мудрствуя лукаво, воспользуемся халовской функцией
    auto millisecond_tick = HAL_GetTick();

    return time_point(duration(millisecond_tick));
  }
};

class CoChronoImpl final : public CoProxy<CoChronoImpl>{

    public:

    constexpr co_act_t give_impl(co_act_t A) const noexcept{

        return A;
    }

    friend class CoProxy<CoChronoImpl>;
};

using co_chrono_t = CoProxy<CoChronoImpl>;
using chrono_entry_t = std::tuple<co_act_t, PlatformClock::time_point, base_t>;
using chrono_queue_t = CoQueueImpl<chrono_entry_t, CoParam::CORO_TIMER_NUM, co_critical_t>;


chrono_queue_t chrono_queue;


void CoChrono::set_timer (co_act_t A, base_t delay) noexcept{

    chrono_queue.push( {A, PlatformClock::now(), delay} );
}

void CoChrono::check_if_expired() noexcept{

    auto& q = chrono_queue.get_instance();
    co_chrono_t chrono;

    for (auto& [act, start_point, delay] : q){

        if (not delay) continue;

        auto res = 
            duration_cast<milliseconds>(PlatformClock::now() - start_point).count();

        if (res > delay){

            chrono.give(act);

            delay = 0;
        }
    }
}
