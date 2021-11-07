// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_UTIL_HPP_
#define INC_CO_UTIL_HPP_

#pragma once

namespace co_detail{

template <class T>
struct remove_reference {
    using type = T;
    using ref_type = const T;
};

template <class T>
struct remove_reference<T&> {
    using type = T;
    using ref_type = const T&;
};

template <class T>
struct remove_reference<T&&> {
    using type = T;
    using ref_type = const T&&;
};

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

template <class T>
[[nodiscard]] constexpr remove_reference_t<T>&& move(T&& Arg) noexcept {
    return static_cast<remove_reference_t<T>&&>(Arg);
}

template <class T>
[[nodiscard]] constexpr T&& forward( remove_reference_t<T>& Arg) noexcept {
    return static_cast<T&&>(Arg);
}

} // end of namespace co_detail

#endif /* INC_CO_UTIL_HPP_ */
