#include <iostream>
#include <chrono>
#include "KBitset.h"
#include <bitset>
#include<string>
#include <cstring>

using namespace std;
using namespace std::chrono;
const int N = 1e9;
KBitset kBitset(1);
KBitset vec;
bitset<N> stdBitset;

int main() {

    // 测试自己编写的 KBitset
    auto start = high_resolution_clock::now();

    kBitset.set(0);
    cout<<kBitset.capacity()<<endl;
    kBitset.set(3);
    cout<<kBitset.capacity()<<endl;
    kBitset.set(6);
    kBitset.set(7);
    kBitset.set(9);
    kBitset.set(10);
    kBitset.set(11);
    kBitset.set(15);
    cout<<kBitset.capacity()<<endl;
    kBitset.set(92);
    cout<<kBitset.capacity()<<endl;

    auto end = high_resolution_clock::now();
    auto durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset set() execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // 测试标准库的 std::bitset
    start = high_resolution_clock::now();

    for(int i=0;i<N;i++)
    stdBitset.set(i);

    end = high_resolution_clock::now();
    auto durationStdBitset = duration_cast<milliseconds>(end - start);
    cout << "std::bitset set() execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    // puts("");

    // // 测试自己编写的 KBitset
    // start = high_resolution_clock::now();

    // kBitset.reset();

    // end = high_resolution_clock::now();
    // durationKBitset = duration_cast<milliseconds>(end - start);
    // cout << "KBitset reset execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // // 测试标准库的 std::bitset
    // start = high_resolution_clock::now();

    // stdBitset.reset();

    // end = high_resolution_clock::now();
    // durationStdBitset = duration_cast<milliseconds>(end - start);
    // cout << "std::bitset reset() execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    // puts("");

    // // 测试自己编写的 KBitset
    // start = high_resolution_clock::now();

    // for (int i = 0; i < N / 2; i++) {
    //     vec.push_back(1);
    // }

    // end = high_resolution_clock::now();
    // durationKBitset = duration_cast<milliseconds>(end - start);
    // cout << "KBitset push_back execution time: " << durationKBitset.count() << " milliseconds" << endl;
    // // 测试自己编写的 KBitset
    // start = high_resolution_clock::now();

    // for (int i = 0; i < N / 2; i++) {
    //     vec.pop_back();
    // }

    // end = high_resolution_clock::now();
    // durationKBitset = duration_cast<milliseconds>(end - start);
    // cout << "KBitset pop execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // cout << "vec size = " << vec.size() << endl;
    // cout << "kBitset size = " << kBitset.size() << endl;
    // cout << "vec capacity = " << vec.capacity() << "byte" << endl;
    // cout << "kBitset capacity = " << kBitset.capacity() << "byte" << endl;

    // puts("");

    // kBitset.test();
    // stdBitset.reset();
    // for (int i = 0; i < N; i += 32) {
    //     stdBitset.set(i);
    // }

    // // 测试自己编写的 KBitset
    // start = high_resolution_clock::now();

    // for (size_t j = kBitset.find_first(); j != kBitset.size(); j = kBitset.find_next(j)) {

    // }

    // end = high_resolution_clock::now();
    // durationKBitset = duration_cast<milliseconds>(end - start);
    // cout << "KBitset find_next execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // // 测试标准库的 std::bitset
    // start = high_resolution_clock::now();

    // for (size_t j = stdBitset._Find_first(); j != stdBitset.size(); j = stdBitset._Find_next(j)) {

    // }

    // end = high_resolution_clock::now();
    // durationStdBitset = duration_cast<milliseconds>(end - start);
    // cout << "std::bitset _Find_next execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    // puts("");

    // KBitset kbitset(100); // 创建一个大小为100的位集合

    // // 设置一些位
    // kbitset.set(1);
    // kbitset.set(3);
    // kbitset.set(5);
    // kbitset.set(50);
    // kbitset.set(70);

    // std::cout << "Set bits: ";
    // for (size_t j = kbitset.find_first(); j != kbitset.size(); j = kbitset.find_next(j)) {
    //     std::cout << j << " ";
    // }
    // std::cout << std::endl;

    // // 重置一些位
    // kbitset.reset(3);
    // kbitset.reset(70);

    // std::cout << "Reset bits: ";
    // for (size_t j = kbitset.find_first(); j != kbitset.size(); j = kbitset.find_next(j)) {
    //     std::cout << j << " ";
    // }
    // std::cout << std::endl;

    // // 测试空位集合
    // KBitset emptyBitset;
    // std::cout << "Empty Bitset: " << (emptyBitset.empty() ? "Empty" : "Not Empty") << std::endl;

    // // 测试位集合的大小和容量
    // std::cout << "Bitset Size: " << kbitset.size() << std::endl;
    // std::cout << "Bitset Capacity: " << kbitset.capacity() << " bytes" << std::endl;

    // // 测试 push_back() 函数
    // kbitset.push_back(1);
    // kbitset.push_back(1);

    // std::cout << "After push_back(): ";
    // for (size_t j = kbitset.find_first(); j != kbitset.size(); j = kbitset.find_next(j)) {
    //     std::cout << j << " ";
    // }
    // std::cout << std::endl;

    return 0;
}