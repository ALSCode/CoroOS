// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_CHRONO_HPP_
#define INC_CO_CHRONO_HPP_

#pragma once

#include "co_types.hpp"

struct CoChrono{
    static void set_timer (co_act_t A, base_t delay) noexcept;
    static void check_if_expired() noexcept;
};


#endif /* INC_CO_CHRONO_HPP_ */