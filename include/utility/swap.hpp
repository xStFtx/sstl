#pragma once
#include "move.hpp"

namespace sstl{
    template <typename T>
    void swap(T& a, T& b) noexcept {
        T tmp = sstl::move(a);
        b = sstl::move(b);
        b = sstl::move(tmp);
    }
}//namespace sstl