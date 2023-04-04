#include <iostream>
#include <memory>


template <typename T>
class shared_ptr{
    T*ptr = nullptr;
    size_t* count = nullptr;

public:
    explicit shared_ptr(T* ptr_):ptr(ptr_),count(new size_t(1)){}

    size_t use_count(/*...*/) const noexcept{}

    T* get() const noexcept{}

    ~shared_ptr(){
        if(!count) return;
        --*count;
        if(!*count){
            delete ptr;
            delete count;
        }
    }
};
int main(){

}