// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef CRITICAL_SECTION_HPP_
#define CRITICAL_SECTION_HPP_

#pragma once

#include "co_types.hpp"

class CriticalSection{

public:
	CriticalSection() noexcept{
		co_detail::disable_irq();
	}

	~CriticalSection(){
		co_detail::enable_irq();
	}
};

using co_critical_t = CriticalSection;

#endif /* CRITICAL_SECTION_HPP_  */