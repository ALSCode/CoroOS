// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_ASSERT_HPP_
#define INC_CO_ASSERT_HPP_

#pragma once

#include <cassert>

constexpr void co_assert (bool expr, [[maybe_unused]]const char* msg = "") noexcept{

	if (expr) [[likely]] {
		return;
	} else [[unlikely]] {
		assert(expr);
        //or your target specific implementation
	}
}

#endif /* INC_CO_ASSERT_HPP_ */