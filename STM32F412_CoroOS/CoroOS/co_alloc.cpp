// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#include <memory_resource>
#include "co_alloc.hpp"
#include "co_types.hpp"


byte_t raw_buf[CoParam::CORO_STORAGE_SIZE];

std::pmr::monotonic_buffer_resource mbr{raw_buf, CoParam::CORO_STORAGE_SIZE};

std::size_t current_size, max_size;

void* CoAlloc::allocate(std::size_t size){

    co_assert(CoParam::CORO_STORAGE_SIZE - size > max_size, __func__);

	current_size = size;

    max_size += size;

	return mbr.allocate(size);
}

void CoAlloc::deallocate([[maybe_unused]] void *p){
	
	mbr.release();
    std::abort();
}

std::size_t CoAlloc::get_current_size() noexcept{
	return current_size;
}

std::size_t CoAlloc::check_memory() noexcept{
	return max_size;
}

