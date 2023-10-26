#include<vector>

class KBitset{
    private:
        std::vector<unsigned long> data;
        size_t bitsize = 0;
        size_t pointer = 0;

    public:
        KBitset();
        KBitset(size_t n);
        size_t size() const;
        bool empty();
        void clear();
        void push_back(size_t value);
        void pop_back();
        void set(size_t index, size_t value);
        bool value(size_t index) const;
        size_t find_first() const;
        size_t find_next(size_t) const;

        // 重载下标访问操作符
        bool operator[](size_t index) const;
};