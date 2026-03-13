#pragma once
#include <cstdint>
#include <cstddef>
#include <stdexcept>
#include <algorithm>

namespace sstl{
    template<typename T, size_t B = 64>
    class deque{
        public:
            deque() {
                map_size_ = 8;
                map_ = new T*[map_size_] {};

                size_t mid = map_size_ /2;
                map_[mid] = new T[B];

                start_block_ = mid;
                end_block_ = mid;

                start_index_ = 0;
                end_index_ = 0;
            };
            ~deque() {
                for(size_t i = 0; i < map_size_; ++i)
                    delete[] map_[i];
                delete[] map_;
            };

            void push_back(const T& value) {
                if (end_index_ == B){
                    end_block_++;

                    if (!map_[end_block_])
                        map_[end_block_] = new T[B];
                    end_index_ = 0;
                }

                map_[end_block_][end_index_++] = value;
            };
            void push_front(const T& value){
                if (start_index_ == 0){
                    start_block_--;

                    if (!map_[start_block_])
                        map_[start_block_] = new T[B];
                    start_index_ = B;
                }

                map_[start_block_][--start_index_] = value;
            };
            
            void pop_back() {
                if (end_index_ == 0) {
                    end_block_--;
                    end_index_ = B;
                }

                --end_index_;

            };
            void pop_front() {
                ++start_index_;

                if (start_index_ == B) {
                    start_index_ = 0;
                    start_block_++;
                }
            };

            T& operator[](size_t i) {
                size_t offset = start_index_ + i;

                size_t block = start_block_ + offset/ B;
                size_t index = offset % B;

                return map_[block][index];
            };

            size_t size() const {
                return (end_block_ * B + end_index_) - (start_block_ * B + start_index_);
            }
        private:
            T** map_;
            size_t map_size_;

            size_t start_block_;
            size_t start_index_;

            size_t end_block_;
            size_t end_index_;
    };
}//namespace sstl