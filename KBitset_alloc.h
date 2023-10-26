#include<memory>

class KBitset_alloc{
private:
    std::allocator<unsigned long> allocator_;
    unsigned long *data_;
    size_t size_;
    size_t capacity_;
    size_t pointer_;

public:
    KBitset_alloc():size_(0),capacity_(0),pointer_(0),data_(nullptr){}

    explicit KBitset_alloc(size_t numBits) : size_(numBits), capacity_(numBits),pointer_(0) {
        size_t numBytes = (numBits + 31) / 32;
        data_ = allocator_.allocate(numBytes);
        std::fill_n(data_, numBytes, 0);
    }

    ~KBitset_alloc(){
        if(data_){
            size_t numBytes=(size_ + 31) / 32;
            allocator_.deallocate(data_,numBytes);
        }
    }

    void resize(size_t);
    void set(size_t);
    void reset(size_t);
    void push_back(bool);
    void pop_back();
    [[nodiscard]] size_t find_first(size_t) const;
    size_t size() const;
    size_t capacity() const;
    bool value(size_t);
    // 重载下标访问操作符
    bool operator[](size_t) const;
};