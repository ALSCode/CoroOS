// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef CO_PROXY_HPP_
#define CO_PROXY_HPP_

#pragma once

#include "co_util.hpp"
#include "co_manager.hpp"

template<typename T>
class CoProxy : public CoManager {

public:

	using derived_ptr = T*;

    template<typename ...Args>
	constexpr void give(Args&& ...args) noexcept {

        co_act_t action = 
            derived()->give_impl(co_detail::forward<Args>(args) ...);

        set_action(action);
	}

    template<CoPrio P, typename ...Args>
    constexpr auto get (Args&& ...args) noexcept {
        
        return derived()->template get_impl<P>(co_detail::forward<Args>(args) ...);
	}

    constexpr bool ready() noexcept {
       
        return derived()->ready_impl();
	}

    constexpr auto unload() noexcept {

        return derived()->unload_impl();
	}

private:

	constexpr derived_ptr derived() noexcept{
        
		return static_cast<derived_ptr>(this);
	}
};

template<co_act_t ID, CoPrio P>
struct CoProxyData : public CoManager {

    co_mutex_t mutex{
        .ptr = nullptr,
        .is_taken = false
    };
};

template<co_act_t ID, CoPrio P>
using co_proxy_t = CoProxyData<ID, P>;

#endif /* CO_PROXY_HPP_ */
