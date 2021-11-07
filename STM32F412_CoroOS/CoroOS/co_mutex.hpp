// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_MUTEX_HPP_
#define INC_CO_MUTEX_HPP_

#pragma once

#include "critical_section.hpp"
#include "co_proxy.hpp"

template<typename CS>
class CoMutexImpl{

    public:

    co_mutex_t get_mutex() noexcept{

        CS critical_section;

        bool is_taken = !mutex;

        if (is_taken) mutex = true;

        return {&mutex, is_taken};
    }

    void give_mutex() noexcept{

        mutex = false;
    }

    private:

    bool mutex{false};
};

template<co_act_t A>
class CoMutex final: public CoProxy<CoMutex<A>>{

    public:

    constexpr co_act_t give_impl() const noexcept{

        instance().give_mutex();

        return A;
    };

    template<CoPrio P>
    constexpr co_proxy_t<A, P> get_impl() const noexcept{

        return {.mutex = instance().get_mutex(),};
    }

    friend class CoProxy<CoMutex<A>>;

    private:

    using mutex_impl_t = CoMutexImpl<co_critical_t>;

    [[gnu::always_inline]] mutex_impl_t& instance() const noexcept{
        static mutex_impl_t mutex_impl;
        return mutex_impl;
    }
};

#define CO_MUTEX(n)   using n = CoProxy<CoMutex<__COUNTER__>>

/*  USER SECTION START  */
CO_MUTEX(mutex_t);
/*  USER SECTION END  */



#endif /* INC_CO_MUTEX_HPP_ */
