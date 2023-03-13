#include <iostream>

// стандартный аллокатор
template<typename T>
struct allocator{
    T* allocate(size_t n){
        return ::operator new(n * sizeof(T));
    }

    void deallocate(T* ptr, size_t n){
        ::operator delete(ptr);
    }

    template<typename ...Args>
    void construct(T*ptr, const Args&... args){
        new(ptr) T(args...);
    }

    void destroy(T*ptr){
        ptr->~T();
    }
};

// нестандартные аллокатор
// PoolAllocator // StackAllocator
// указывает на начало
// затем сдвигается, выводит все, что позади,
// а deallocate не делает, construct, destroy работают, как обычно.
// ТО ЕСТЬ стек, у которого ничего не снимается, пока не destroy
// ___
// дает выигрыш для list, map, unordered_map


int main(){

}
