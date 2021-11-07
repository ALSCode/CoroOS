// Copyright © 2021 Aleksandr Sazhin
// Licensed under the Apache License, Version 2.0

#ifndef INC_CO_VARIANT_HPP_
#define INC_CO_VARIANT_HPP_

#pragma once

#include "co_types.hpp"

class CoVariant{

    public:
    constexpr CoVariant() : tag(Tag::NONE), val(0){};
    ~CoVariant() = default;

    constexpr CoVariant(const CoVariant& other) : tag(other.tag){

        switch(tag){

            case Tag::NONE:
            val = 0;
            break;

            case Tag::BASE_T:
            val = other.val;
            break;

            case Tag::VOID_PTR:
            ptr = other.ptr;
            break;

            default:
            assert(0);
            break;
        }
    }
    constexpr CoVariant(CoVariant&& other) : tag(other.tag){

        switch(tag){

            case Tag::NONE:
            val = 0;
            break;

            case Tag::BASE_T:
            val = other.val;
            break;

            case Tag::VOID_PTR:
            ptr = other.ptr;
            break;

            default:
            assert(0);
            break;
        }
        other.tag = Tag::NONE;
    };

    explicit constexpr CoVariant(base_t v) : tag(Tag::BASE_T), val(v){}
    explicit constexpr CoVariant(void* p) : tag(Tag::VOID_PTR), ptr(p){}

    constexpr CoVariant& operator=(const CoVariant& other) noexcept{

        if (&other != this){

            switch (other.tag){

            case Tag::NONE:
                tag = Tag::NONE;
                val = 0;
                break;

            case Tag::BASE_T:
                tag = Tag::BASE_T;
                val = other.val;
                break;

            case Tag::VOID_PTR:
                tag = Tag::VOID_PTR;
                ptr = other.ptr;
                break;

                default:
                assert(0);
                break;
            }
        }
        return *this;
    };
    
    constexpr CoVariant& operator=(CoVariant&& other) noexcept{

        co_assert(&other != this, __func__);

        switch (other.tag){

            case Tag::NONE:
                tag = Tag::NONE;
                val = 0;
                break;

            case Tag::BASE_T:
                tag = Tag::BASE_T;
                val = other.val;
                break;

            case Tag::VOID_PTR:
                tag = Tag::VOID_PTR;
                ptr = other.ptr;
                break;

                default:
                assert(0);
                break;
            }
            other.tag = Tag::NONE;
            return *this;
    };

    constexpr CoVariant& operator=(base_t v) noexcept{
        tag = Tag::BASE_T;
        val = v;
        return *this;
    }

    constexpr CoVariant& operator=(void* p) noexcept{
        tag = Tag::VOID_PTR;
        ptr = p;
        return *this;
    }

    constexpr base_t base_val() const noexcept{
        if (tag != Tag::BASE_T) co_assert(0, __func__);
        return val;
    }

    constexpr void* void_ptr() const noexcept{
        if (tag != Tag::VOID_PTR) co_assert(0, __func__);
        return ptr;
    }

    private:
    enum class Tag{NONE, VOID_PTR, BASE_T};
    Tag tag{Tag::NONE};

    union{
        void* ptr;
        base_t val;
    };
};

static_assert(sizeof(CoVariant) == 8);

#endif /* INC_CO_VARIANT_HPP_ */
