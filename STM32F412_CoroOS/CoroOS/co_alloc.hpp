// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_ALLOC_HPP_
#define INC_CO_ALLOC_HPP_


#pragma once

struct CoAlloc{
	static void* allocate (std::size_t size);
	static void deallocate (void *p);
	static std::size_t get_current_size() noexcept;
    static std::size_t check_memory() noexcept;
};


#endif /* INC_CO_ALLOC_HPP_ */
