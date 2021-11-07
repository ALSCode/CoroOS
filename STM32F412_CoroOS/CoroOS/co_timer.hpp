// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_TIMER_HPP_
#define INC_CO_TIMER_HPP_

#pragma once

#include "co_proxy.hpp"
#include "co_chrono.hpp"

template<co_act_t A>
class CoTimer final: public CoChrono, public CoProxy<CoTimer<A>>{

    public:

    template<CoPrio P>
    constexpr co_proxy_t<A, P> get_impl(base_t delay) const noexcept{

        set_timer(A, delay);

        return {};
    }

    friend class CoProxy<CoTimer<A>>;
};

#define CO_TIMER(n)   using n = CoProxy<CoTimer<__COUNTER__>>


/*  USER SECTION START  */

CO_TIMER(task1_timer_t);
CO_TIMER(task2_timer_t);
CO_TIMER(task3_timer_t);

/*  USER SECTION END  */

#endif /* INC_CO_TIMER_HPP_ */
