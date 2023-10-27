#include <iostream>
#include <chrono>
#include "KBitset.h"
#include <bitset>

using namespace std;
using namespace std::chrono;
const int N = 1e9;
KBitset kBitset(N);
KBitset vec;
bitset<N> stdBitset;
int main() {

    // 测试自己编写的 KBitset
    auto start = high_resolution_clock::now();

    kBitset.set();

    auto end = high_resolution_clock::now();
    auto durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset set() execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // 测试标准库的 std::bitset
    start = high_resolution_clock::now();

    stdBitset.set();

    end = high_resolution_clock::now();
    auto durationStdBitset = duration_cast<milliseconds>(end - start);
    cout << "std::bitset set() execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    puts("");

    // 测试自己编写的 KBitset
    start = high_resolution_clock::now();

    kBitset.reset();

    end = high_resolution_clock::now();
    durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset reset execution time: " << durationKBitset.count() << " milliseconds" << endl;

    // 测试标准库的 std::bitset
    start = high_resolution_clock::now();

    stdBitset.reset();

    end = high_resolution_clock::now();
    durationStdBitset = duration_cast<milliseconds>(end - start);
    cout << "std::bitset reset() execution time: " << durationStdBitset.count() << " milliseconds" << endl;

    puts("");

    // 测试自己编写的 KBitset
    start = high_resolution_clock::now();

    for(int i=0;i<N;i++){
        vec.push_back(1);
    }

    end = high_resolution_clock::now();
    durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset push_back execution time: " << durationKBitset.count() << " milliseconds" << endl;
    // 测试自己编写的 KBitset
    start = high_resolution_clock::now();

    for(int i=0;i<N;i++){
        vec.pop_back();
    }

    end = high_resolution_clock::now();
    durationKBitset = duration_cast<milliseconds>(end - start);
    cout << "KBitset pop execution time: " << durationKBitset.count() << " milliseconds" << endl;

    cout<<"vec size = "<<vec.size()<<endl;
    cout<<"kBitset size = "<<kBitset.size()<<endl;
    cout<<"vec capacity = "<<vec.capacity()<<"byte"<<endl;
    cout<<"kBitset capacity = "<<kBitset.capacity()<<"byte"<<endl;

    puts("");

    return 0;
}