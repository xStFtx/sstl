#pragma once
#include <type_traits>

//https://en.cppreference.com/w/cpp/utility/move.html
namespace sstl{
    template<typename T>
    constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept {
        return static_cast<typename std::remove_reference<T>::type&&>(t);
    }

    template<typename T>
    constexpr typename std::remove_reference_t<T>&& move(T&& t) noexcept {
        return static_cast<std::remove_reference_t<T>&&>(t);
    }
} // namespace sstl