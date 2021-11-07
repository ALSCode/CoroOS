// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_PLATFORM_HPP_
#define INC_CO_PLATFORM_HPP_

#pragma once

#include <cstdint>
#include <cstdlib>
#include "co_assert.hpp"

using base_t = std::uint32_t;
using byte_t = std::uint8_t;
using co_act_t = decltype(__COUNTER__);

namespace co_detail{

[[gnu::always_inline]]
static inline void disable_irq() noexcept{

	base_t basePri{0x50};

	__asm volatile(
#if (__ARM_ARCH == 6)
			"CPSID   i				\n"
#else
			"CPSID	 i				\n"
			"MSR basepri, %0 		\n"
			"DSB					\n"
			"ISB					\n"
			"CPSIE	 i				\n"
			: : "r" (basePri) : "memory"
#endif
		);
}

[[gnu::always_inline]]
static inline void enable_irq() noexcept{

	base_t basePri{0};

	__asm volatile
		(
			"MSR basepri, %0		\n"
			: : "r" (basePri) : "memory"
		);
}

} // end of "co_detail"
#endif /* INC_CO_PLATFORM_HPP_ */
