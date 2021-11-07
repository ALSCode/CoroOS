// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_EVENT_HPP_
#define INC_CO_EVENT_HPP_

#pragma once

#include "co_proxy.hpp"

template<co_act_t A>
class CoEvent final: public CoProxy<CoEvent<A>>{

    public:

    constexpr co_act_t give_impl() const noexcept{
        return A;
    };

    template<CoPrio P>
    constexpr co_proxy_t<A, P> get_impl() const noexcept{
        return {};
    }

    friend class CoProxy<CoEvent<A>>;
};

#define CO_EVENT(n)   using n = CoProxy<CoEvent<__COUNTER__>>

/*  USER SECTION START  */

CO_EVENT(task1_event_t);

/*  USER SECTION END  */

#endif /* INC_CO_EVENT_HPP_ */
