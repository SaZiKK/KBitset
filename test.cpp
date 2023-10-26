#include <iostream>
#include <chrono>
#include "KBitset.h"
#include <bitset>

using namespace std;
using namespace std::chrono;
const int N = 1e9;
KBitset kBitset(N);
bitset<N> stdBitset;
int main() {

    // 测试自己编写的 KBitset
    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        kBitset.set(i,1);
    }

    auto end = high_resolution_clock::now();
    auto durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset set execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // 测试标准库的 std::bitset
    start = high_resolution_clock::now();

    stdBitset.set();

    end = high_resolution_clock::now();
    auto durationStdBitset = duration_cast<milliseconds>(end - start);
    cout << "std::bitset set() execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    puts("");

    // 测试自己编写的 KBitset
    start = high_resolution_clock::now();

    kBitset.clear();

    end = high_resolution_clock::now();
    durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset set execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // 测试标准库的 std::bitset
    start = high_resolution_clock::now();

    stdBitset.reset();

    end = high_resolution_clock::now();
    durationStdBitset = duration_cast<milliseconds>(end - start);
    cout << "std::bitset reset() execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    puts("");

    kBitset.set(N-5,1);
    stdBitset[N-5]=1;

    // 测试自己编写的 KBitset
    start = high_resolution_clock::now();

    int i=kBitset.find_next(1); cout<<i<<endl;

    end = high_resolution_clock::now();
    durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset find_next execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // 测试标准库的 std::bitset
    start = high_resolution_clock::now();

    i=stdBitset._Find_next(1);

    end = high_resolution_clock::now();
    durationStdBitset = duration_cast<milliseconds>(end - start);
    cout << "std::bitset find_next execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    puts("");

    return 0;
}