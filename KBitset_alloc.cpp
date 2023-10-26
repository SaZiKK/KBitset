//
// Created by ck_lo on 2023/10/26.
//
#include "KBitset_alloc.h"

void KBitset_alloc::resize(size_t numBits) {
    size_t numBytes = (numBits + 7) / 8;
    unsigned long *newData = allocator_.allocate(numBytes);

    if (data_) {
        size_t copySize = std::min(numBytes, (size_ + 7) / 8);
        std::copy(data_, data_ + copySize, newData);
        allocator_.deallocate(data_, (size_ + 7) / 8);
    } else {
        std::fill_n(newData, numBytes, 0);
    }

    data_ = newData;
    size_ = numBits;
    capacity_ = numBits;
}

void KBitset_alloc::set(size_t index) {
    if (index >= size_) {
        return;
    }

    size_t byteIndex = index / 8;
    size_t bitIndex = index % 8;
    data_[byteIndex] |= (1 << bitIndex);
}

void KBitset_alloc::reset(size_t index) {
    if (index >= size_) {
        return;
    }

    size_t byteIndex = index / 8;
    size_t bitIndex = index % 8;
    data_[byteIndex] &= ~(1 << bitIndex);
}

void KBitset_alloc::push_back(bool bit) {
    if(pointer_>=size_) resize(size_*2);
    if(bit){
        set(pointer_);
        pointer_++;
    }
    else{
        reset(pointer_);
        pointer_++;
    }
}

void KBitset_alloc::pop_back() {}

size_t KBitset_alloc::find_first(size_t) const { return 0; }

size_t KBitset_alloc::size() const {
    return size_;
}

size_t KBitset_alloc::capacity() const {
    return capacity_;
}

bool KBitset_alloc::value(size_t) { return false; }

bool KBitset_alloc::operator[](size_t) const { return false; }
