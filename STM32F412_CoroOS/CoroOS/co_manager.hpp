// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_REPO_HPP_
#define INC_CO_REPO_HPP_

#pragma once

#include "co_types.hpp"

struct CoManager{
    static void set_action(co_act_t act) noexcept;
    static void store_sync(co_sync_t s) noexcept;
    static void run();
};

#endif /* INC_CO_REPO_HPP_ */
