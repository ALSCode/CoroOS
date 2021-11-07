// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_QUEUE_IMPL_HPP_
#define INC_CO_QUEUE_IMPL_HPP_

#pragma once

#include "critical_section.hpp"
#include "co_types.hpp"

template<typename P, CoParam D, typename CS>
class CoQueueImpl{

    public:

    void push (const P& payload) noexcept {

        CS critical_section;

        queue[head] = payload;

        ++head;

        if (D == head) head = 0;
    }

    P pop () noexcept{

        CS critical_section;

        base_t current = tail;

        ++tail;

        if (D == tail) tail = 0;

        return queue[current];
    }

    P back() noexcept{
    	return queue[tail];
    }

    bool is_empty() const noexcept{
         return head == tail;
    }

    [[gnu::always_inline]] auto& get_instance() noexcept{
        return queue;
    }

    private:

    P queue[D];
    base_t head{0}, tail{0};
};

#endif /* INC_CO_QUEUE_IMPL_HPP_ */
