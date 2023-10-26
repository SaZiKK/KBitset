#include"KBitset.h"
#include<iostream>

KBitset::KBitset(){

}

KBitset::KBitset(size_t n):bitsize(n){
    size_t byteCount = (n + 31) / 32;
    data.resize(byteCount, 0);
}

size_t KBitset::size() const{
    return bitsize;
}

bool KBitset::empty(){
    return bitsize == 0;
}

void KBitset::clear(){
    std::fill(data.begin(), data.end(), 0);
    bitsize = 0;
    pointer = 0;
    return;
}

void KBitset::push_back(size_t value){
    if(pointer%32>0){
        size_t byteIndex = pointer / 32;
        size_t bitIndex = pointer % 32;
        unsigned long mask = value << bitIndex;
        data[byteIndex] |= mask;
    }
    else{
        unsigned long mask = value;
        data.push_back(mask);
    }
    bitsize++;
    pointer++;
    return;
}

void KBitset::pop_back(){
    pointer--;
    bitsize--;
}

void KBitset::set(size_t index, size_t value){
    if(value == 1){
        size_t byteIndex = index / 32;
        size_t bitIndex = index % 32;
        unsigned long mask = 1 << bitIndex;
        data[byteIndex] |= mask;
    }
    else{
        size_t byteIndex = index / 32;
        size_t bitIndex = index % 32;
        unsigned long mask = ~(1 << bitIndex);
        data[byteIndex] &= mask;
    }
    return;
}

bool KBitset::value(size_t index) const{
    size_t byteIndex = index / 32;
    size_t bitIndex = index % 32;
    unsigned long mask = 1 << bitIndex;
    return (data[byteIndex] & mask) != 0;
}

bool KBitset::operator[](size_t index) const {
    return value(index);
}

size_t KBitset::find_first() const {
    size_t byteIndex = 0;
    size_t bitIndex = 0;
    while (byteIndex < data.size()) {
        unsigned long byte = data[byteIndex];
        while (bitIndex < 32) {
            if (byte & (1 << bitIndex)) {
                return byteIndex * 32 + bitIndex;
            }
            bitIndex++;
        }
        byteIndex++;
        bitIndex = 0;
    }
    return -1;  // 如果没有找到值为 1 的位，则返回 -1 表示未找到
}

size_t KBitset::find_next(size_t index) const {
    size_t byteIndex = index/32;
    size_t bitIndex = index%32;
    std::cout<<"data["<<byteIndex<<"] = "<<data[byteIndex]<<std::endl;
    unsigned long __x = data[byteIndex] >> index%32;
    if(__x){
        return byteIndex*32+index%32+__builtin_ctzl(__x);
    }
    byteIndex++;
    while (byteIndex < data.size()) {
        if(data[byteIndex]>0){
            return byteIndex*32+__builtin_ctzl(data[byteIndex]);
        }
        byteIndex++;
    }
    return -1;  // 如果没有找到值为 1 的位，则返回 -1 表示未找到
}