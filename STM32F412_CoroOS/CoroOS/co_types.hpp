// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_TYPES_HPP_
#define INC_CO_TYPES_HPP_

#pragma once

#include "co_platform.hpp"
#include "co_enum.hpp"

struct CoMutexData{
    bool* ptr;
    bool is_taken;
};

using co_mutex_t = CoMutexData;

struct CoSync{
    co_mutex_t mutex;
    void* address;
	CoState state;
    CoPrio prio;
    base_t id;
	base_t size;
    co_act_t expected;
};

using co_sync_t = CoSync*;

using indexer_t = decltype([]{ static base_t i; return ++i - 1;});

#endif /* INC_CO_TYPES_HPP_ */
