// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_ENUM_HPP_
#define INC_CO_ENUM_HPP_

#pragma once

enum class CoState {
    none,
    ready,
    suspended,
	running,
    stopped,
    blocked
};

enum CoPrio{
/*  USER SECTION START  */
    task3,
    task2,
	task1,
/*  USER SECTION END  */
    num,
    lowest = num - 1,
};

enum CoParam {
/*  USER SECTION START  */
    CORO_TASK_NUM = 8,
    CORO_TIMER_NUM = 4,
    CORO_QUEUE_SIZE = 16,
    CORO_STACK_SIZE = 256,
/*  USER SECTION END  */
	CORO_STORAGE_SIZE = CORO_TASK_NUM * CORO_STACK_SIZE,
};

#endif /* INC_CO_ENUM_HPP_ */
