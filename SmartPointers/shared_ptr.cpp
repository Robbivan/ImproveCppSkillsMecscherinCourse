#include <iostream>
#include <memory>

// Shared_ptr implementation
template <typename T>
class Shared_ptr{
    T*ptr = nullptr;
    size_t* count = nullptr;
    template<typename U, typename ...Args>
    struct ControlBlock{
        T object;
        size_t count;
        ControlBlock(size_t count, Args&& ...args){
            //...
        }
    };

    Shared_ptr(ControlBlock<T>* ptr): ptr(&ptr->object), count(&ptr->count){}

public:
    explicit Shared_ptr(T* ptr_): ptr(ptr_), count(new size_t(1)){
        if constexpr (std::is_base_of_v<std::enable_shared_from_this<T>,T>){
            ptr->wptr = *this;
        }
    }


    size_t use_count(/*...*/) const noexcept{}

    T* get() const noexcept{}
    int value;
    ~Shared_ptr(){
        if(!count) return;
        --*count;
        if(!*count){
            delete ptr;
            delete count;
        }
    }
    template<typename U,typename ...Args>
    friend std::shared_ptr<U> make_shared(Args&&... args);
};

template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args &&... args) {
    auto p = new Shared_ptr<T>::template ControlBlock<T>(1, std::forward<Args>(args)...);
    return std::shared_ptr<T>(p);
}

//template<typename U, typename ...Args>
//std::shared_ptr<U> make_shared(Args&&... args){
//    use_count()
//    auto p =new ControlBlock<U>()
//    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
//
//}


void check_nice(){
    // плохой код, так как промежуточный сишный указатель
//    int* p = new int(5);
//    Shared_ptr<int> sp(p);
//    Shared_ptr<int> sp(new int(5)); // так тоже не очень, так как new вручную

    auto p = std::make_unique<int>(5); // так четко определен порядок
    // как и emplace создают сами объекты в динамической памяти
}


int f(int x){
    return x+1;
}

void g(const std::shared_ptr<int>& sp, int x){

}

void h(){
    g(std::shared_ptr<int>(new int(5)), f(0)); // ПЛОХО, так как неизвестен порядок, f может вторгнуться
    // С++17 поправили эту проблему
}

// используя shared_ptr нужно быть аккуратным с зависимостями
// так как если 1 будет указывать на 2, а 2 на 1, то будет проблема
// в языках типа python, java аналогичная проблема (решается в каждом garbage collector по-своему)
// в С++ решение через weak_ptr


// иногда нужно не удалять в конце, то на что указывает shared_ptr, а например закрыть файл, то есть можно делать свой
// кастомный делитер
int main(){


}