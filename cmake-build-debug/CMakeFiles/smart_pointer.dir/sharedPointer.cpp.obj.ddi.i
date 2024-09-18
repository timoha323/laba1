# 0 "C:/Users/makar/CLionProjects/smart_pointer/cmake-build-debug/sharedPointer.cpp"
# 1 "C:\\Users\\makar\\CLionProjects\\smart_pointer\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "C:/Users/makar/CLionProjects/smart_pointer/cmake-build-debug/sharedPointer.cpp"
       

template <typename T>
class SharedPointer {
private:
    T* ptr;
    int* refCount;

    void release() {
        if (refCount) {
            (*refCount)--;
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
                ptr = nullptr;
                refCount = nullptr;
            }
        }
    }

public:
    SharedPointer() : ptr(nullptr), refCount(nullptr) {}

    explicit SharedPointer(T* p) : ptr(p), refCount(new int(1)) {}

    SharedPointer(const SharedPointer<T>& other) : ptr(other.ptr), refCount(other.refCount) {
        if (refCount) {
            (*refCount)++;
        }
    }

    SharedPointer& operator=(const SharedPointer<T>& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            if (refCount) {
                (*refCount)++;
            }
        }
        return *this;
    }

    SharedPointer(SharedPointer<T>&& other) noexcept : ptr(other.ptr), refCount(other.refCount) {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    SharedPointer& operator=(SharedPointer<T>&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    ~SharedPointer() {
        release();
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    int use_count() const {
        return refCount ? *refCount : 0;
    }

    bool unique() const {
        return use_count() == 1;
    }

    bool operator !(){
      return !ptr;
    }
};
