#ifndef allocator_h
#define allocator_h

template <class T>
struct Allocator
{
    T* allocate(size_t count)
    {
        T* new_data = static_cast<T*>(malloc(sizeof(T) * count));
        if (new_data == nullptr)
        {
            throw std::bad_alloc();
        }
        return new_data;
    }

    void deallocate(T* p, size_t count)
    {
        free(p);
    }

    template <typename... Args>
    void construct(T* np, Args&&... args)
    {
        new (np) T(std::forward<Args>(args)...);
    }

    void destroy(T* np)
    {
        np->~T();
    }
};

#endif

