#pragma once

namespace sstl{
    template <typename T1, typename T2>
    struct pair {
        T1 first;
        T2 second;

        pair() = default;

        pair(const T1& a, const T2& b) : first(a) , second(b) {}
    };
}// namespace sstl;