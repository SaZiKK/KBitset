#include"KBitset.h"
#include<iostream>
#include <limits>

KBitset::KBitset() : bitSize(0), pointer(0) {

}

KBitset::KBitset(size_t n) : bitSize(n) ,pointer(n){
    size_t byteCount = (n + BIT_SIZE_OF_LONG - 1) / BIT_SIZE_OF_LONG;
    data.resize(byteCount, 0);
}

size_t KBitset::size() const {
    return bitSize;
}

bool KBitset::empty() {
    return bitSize == 0;
}

void KBitset::reset() {
    std::fill(data.begin(), data.end(), 0);
    pointer = 0;
}

void KBitset::set() {
    std::fill(data.begin(), data.end(), MAX_VALUE_OF_LONG);
}

void KBitset::push_back(size_t value) {
    if (pointer == bitSize) {
        bitSize++;
        if (bitSize > data.size() * BIT_SIZE_OF_LONG) {
            data.reserve(data.size()*2);
            data.insert(data.end(),data.size()*2,0);
        }
    }

    if (value) set(pointer);
    else reset(pointer);

    pointer++;
}

void KBitset::pop_back() {
    pointer--;
    reset(pointer);
}

void KBitset::set(size_t index) {
    if(index>data.size() * BIT_SIZE_OF_LONG){
        data.reserve((index/BIT_SIZE_OF_LONG+1)*2);
        data.insert(data.end(),(index/BIT_SIZE_OF_LONG+1)*2,0);
        bitSize=index;
    }
    if(index>bitSize) bitSize=index;

    size_t byteIndex = index / BIT_SIZE_OF_LONG;
    size_t bitIndex = index % BIT_SIZE_OF_LONG;
    unsigned long mask = 1 << bitIndex;
    data[byteIndex] |= mask;
}

void KBitset::reset(size_t index) {
    if(index>data.size() * BIT_SIZE_OF_LONG){
        data.reserve((index/BIT_SIZE_OF_LONG+1)*2);
        data.insert(data.end(),(index/BIT_SIZE_OF_LONG+1)*2,0);
        bitSize=index;
    }
    if(index>bitSize) bitSize=index;

    size_t byteIndex = index / BIT_SIZE_OF_LONG;
    size_t bitIndex = index % BIT_SIZE_OF_LONG;
    unsigned long mask = ~(1 << bitIndex);
    data[byteIndex] &= mask;
}

bool KBitset::value(size_t index) const {
    size_t byteIndex = index / BIT_SIZE_OF_LONG;
    size_t bitIndex = index % BIT_SIZE_OF_LONG;
    unsigned long mask = 1 << bitIndex;
    return (data[byteIndex] & mask) != 0;
}

bool KBitset::operator[](size_t index) const {
    return value(index);
}

size_t KBitset::find_first() const {
    size_t byteIndex = 0;
    while (byteIndex < data.size()) {
        unsigned long byte = data[byteIndex];
        if (byte > 0) {
            return byteIndex * BIT_SIZE_OF_LONG
                   + __builtin_ctzl(byte);
        }
        byteIndex++;
    }
    return -1;
}

size_t KBitset::find_next(size_t prev) const {
    prev++;
    if(prev>bitSize) return bitSize;
    size_t byteIndex = prev / BIT_SIZE_OF_LONG;
    unsigned long _x = data[byteIndex] >> prev % BIT_SIZE_OF_LONG;
    if (_x) {
        return byteIndex * BIT_SIZE_OF_LONG
               + prev % BIT_SIZE_OF_LONG
               + __builtin_ctzl(_x);
    }
    byteIndex++;
    while (byteIndex < data.size()) {
        if (data[byteIndex] > 0) {
            return byteIndex * BIT_SIZE_OF_LONG
                   + __builtin_ctzl(data[byteIndex]);
        }
        byteIndex++;
    }
    return bitSize;
}

//返回字节数
size_t KBitset::capacity() const {
    return data.size() * BIT_SIZE_OF_LONG / BYTE_SIZE;
}

void KBitset::test() {
    std::fill(data.begin(), data.end(), 1);
}
