cmake_minimum_required(VERSION 3.12)
project(KBitset)

add_executable(test test.cpp KBitset.cpp
        KBitset_alloc.h
        KBitset_alloc.cpp)