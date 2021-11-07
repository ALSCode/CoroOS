// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_QUEUE_HPP_
#define INC_CO_QUEUE_HPP_

#pragma once

#include "co_proxy.hpp"
#include "co_variant.hpp"
#include "co_queue_impl.hpp"

/*  USER SECTION START  */
using co_payload_t = CoVariant;

/*  USER SECTION END  */

template<co_act_t A>
class CoQueue final: public CoProxy<CoQueue<A>>{

    public:

    using co_queue_t = CoQueueImpl<co_payload_t, CoParam::CORO_QUEUE_SIZE, co_critical_t>;

    constexpr co_act_t give_impl(const co_payload_t& payload) const noexcept{

        instance().push(payload);

        return A;
    }

    template<CoPrio P>
    constexpr co_proxy_t<A, P> get_impl() const noexcept{
        return {};
    }

    constexpr bool ready_impl() const noexcept{
         return !instance().is_empty();
    }

    constexpr co_payload_t unload_impl() const noexcept {
        return instance().pop();
    }

    friend class CoProxy<CoQueue<A>>;

    private:

    [[gnu::always_inline]] co_queue_t& instance() const noexcept{
        static  co_queue_t queue_impl;
        return queue_impl;
    }
};

#define CO_QUEUE(q)   using q = CoProxy<CoQueue<__COUNTER__>>

/*  USER SECTION START  */

CO_QUEUE(task2_queue_t);
CO_QUEUE(task3_queue_t);

/*  USER SECTION end  */

#endif /* INC_CO_QUEUE_HPP_ */
