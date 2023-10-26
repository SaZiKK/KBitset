# KBitset
一个基于vector的可扩展的bitset实现

**currently support：**
- KBitset();
- KBitset(size_t n);
- size_t size() const;
- bool empty();
- void clear();
- void push_back(size_t value);
- void pop_back();
- void set(size_t index, size_t value);
- bool value(size_t index) const;
- size_t find_first() const;
- size_t find_next(size_t) const;
