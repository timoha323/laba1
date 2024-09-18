# 0 "C:/Users/makar/CLionProjects/smart_pointer/cmake-build-debug/uniquePointer.cpp"
# 1 "C:\\Users\\makar\\CLionProjects\\smart_pointer\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "C:/Users/makar/CLionProjects/smart_pointer/cmake-build-debug/uniquePointer.cpp"
       
template <typename T>
class UniquePtr {
private:
    T* ptr;

public:

    UniquePtr() : ptr(nullptr) {}

    explicit UniquePtr(T* p) : ptr(p) {}

    UniquePtr(const UniquePtr<T>&) = delete;

    UniquePtr& operator=(const UniquePtr<T>&) = delete;

    UniquePtr(UniquePtr<T>&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr<T>&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~UniquePtr() {
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }

    bool isNull() const {
        return ptr == nullptr;
    }
};
