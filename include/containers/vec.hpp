#pragma once
#include <stdexcept>
#include <algorithm>
#include <cstddef>
namespace sstl{
    template<typename T>
    class vec{
        public:
            vec() : cap_(0) , size_(0) , data(nullptr) {};
            vec(const vec<T>& other) : cap_(other.cap_) , size_(other.size_){
                data = new T[cap_];
                for (size_t i = 0 ; i < size_; ++i)
                    data[i] = other.data[i];
            };
            vec& operator=(const vec<T>& other) {
                if (this != &other){
                    T* new_data = new T[other.cap_];
                    for (size_t i = 0; i < other.size_; ++i)
                        new_data[i] = other.data[i];
                    delete[] data;
                    data = new_data;
                    cap_ = other.cap_;
                    size_ = other.size_;
                }

                return *this;
            }
            T& operator[](size_t index){
                if (index >= size_)
                    throw std::out_of_range("index out of range");
                return data[index];
            };
            ~vec() {
                delete[] data;
            };

            void resize(size_t new_size) {
                if (new_size < size_){
                    size_ = new_size; 
                } else if (new_size <= cap_) {
                    for (size_t i = size_; i < new_size; ++i) 
                        data[i] = T();
                    size_ = new_size;
                } else {
                    size_t new_cap = std::max(new_size, cap_ *2);
                    reserve(new_cap);
                    for (size_t i = size_; i < new_size; ++i)
                        data[i] = T();
                    size_ = new_size;
                }
            };

            void reserve(size_t new_cap) {
                if (new_cap <= cap_){
                    return;
                } else {
                    T* new_data = new T[new_cap];
                    for (size_t i = 0; i < size_; ++i)
                        new_data[i] = data[i];
                    delete[] data;
                    data = new_data;
                    cap_ = new_cap;
                }
            };

            void push_back(const T& value) {
                if (size_ == cap_) {
                    reserve(cap_ == 0 ? 1 : cap_ *2);
                } 
                data[size_] = value;
                size_++;
            }

            size_t size() const {
                return size_;
            }

            size_t capacity() const {
                return cap_;
            }

        private:
            T* data;
            size_t cap_;
            size_t size_;

    };
} //namespace sstl