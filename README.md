# KBitset
一个基于vector的可扩展的bitset实现

**currently support：**
```c++
- KBitset();
- KBitset(size_t n);
- size_t size() const;
- bool empty();
- void reset()
- void reset(size_t index);
- void push_back(size_t value);
- void pop_back();
- void set();
- void set(size_t index);
- bool value(size_t index) const;
- size_t find_first() const;
- size_t find_next(size_t) const;
- size_t capacity() const;
```
### 效率分析
- **reset和set平均效率与std::bitset相当**（reset略慢，set略快）
- **find_next/first效率与std::bitset同一数量级**（1e9数据量下慢了约一倍）


