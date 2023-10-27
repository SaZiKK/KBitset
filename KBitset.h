#include<vector>
#define BIT_SIZE_OF_LONG 32
#define MAX_VALUE_OF_LONG 4294967295
#define BYTE_SIZE 8

class KBitset{
    private:
        std::vector<unsigned long> data;
        size_t bitSize = 0;
        size_t pointer = 0;

    public:
        KBitset();
        KBitset(size_t n);
        size_t size() const;
        bool empty();
        void reset();
        void reset(size_t index);
        void push_back(size_t value);
        void pop_back();
        void set();
        void set(size_t index);
        bool value(size_t index) const;
        size_t find_first() const;
        size_t find_next(size_t) const;
        size_t capacity() const;

        // 重载下标访问操作符
        bool operator[](size_t index) const;
};