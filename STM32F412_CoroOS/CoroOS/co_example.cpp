// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#include <cstdio>
#include "main.h"
#include "tim.h"

#include "co_manager.hpp"
#include "co_task.hpp"
#include "co_chrono.hpp"
 
#include "co_event.hpp"
#include "co_queue.hpp"
#include "co_mutex.hpp"
#include "co_timer.hpp"

int counter {0};
bool finish{false};

Coro task_1 () {

	mutex_t mutex;
    task1_event_t event;
    co_payload_t pld{ base_t{10} };

    while(true){

    	co_await mutex.get<CoPrio::task1>();

    	puts("task_1 ready");

    	mutex.give();

        co_await event.get<CoPrio::task1>();

        puts("task_1 started");

        for (base_t i = 0; i != 12; i++){

        	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

        	HAL_Delay(250);

        	if (i == 4) task2_queue_t{}.give(pld);
        }

        puts("task_1 stopped");

        HAL_TIM_Base_Start_IT(&htim14);
    }
}

Coro task_2 () {

    task2_queue_t queue;

    while(true){

        co_await queue.get<CoPrio::task2>();

        puts("task_2 started");

        auto value = queue.unload().base_val();
        value += 10;
        co_payload_t pld{value};

        for (base_t i = 0; i != 12; i++){

        	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);

        	HAL_Delay(250);

        	if (i == 4) task3_queue_t{}.give(pld);
        }

        puts("task_2 stopped");
    }
}

Coro task_3 () {

    task3_queue_t queue;

    while(true){

        co_await queue.get<CoPrio::task3>();

        puts("task_3 started");

        auto value = queue.unload().base_val();

        for (base_t i = 0; i != 12; i++){

        	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);

        	HAL_Delay(250);
        }

        printf("task3_stopped. value: %lu\n", value);
    }
}


extern "C"
void test(){

    mutex_t mutex;

    mutex.get<CoPrio::task1>();

	task_1();
	task_2();
	task_3();

	mutex.give();

	printf("memory allocated: %u\n", CoAlloc::check_memory());
}

extern "C"
void send_event(){
	task1_event_t{}.give();
}

extern "C"
void timer_service(){
	CoChrono::check_if_expired();
}

extern "C"
void Dispatch(){
	CoManager::run();
}

