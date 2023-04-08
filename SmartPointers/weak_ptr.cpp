#include <iostream>
#include <memory>
/// weak_ptr

// 1. Спросить не умер ли объект
// 2. Создай shared_ptr на объект, на который ты смотришь
// weak_ptr нельзя разыменовывать

// Если weak_count = 0, то удаляем контрольный блок
// Если shared_count = 0, то удаляем только shared_ptr (или объект под ним, в зависимости от счетчика)
template<typename T, typename ...Args>
struct ControlBlock{
    T object;
    size_t shared_count; // 2 счетчика
    size_t weak_count;
    ControlBlock(size_t count, Args&& ...args){
        //...
    }
};

template <typename T>
class weak_ptr{
private:
    ControlBlock<T>* cptr = nullptr;
public:
    weak_ptr(const std::shared_ptr<T>& p):cptr(p){}

    bool expired()const{ //истекший (проверка)
        return cptr->shared_count == 0;
    }

    std::shared_ptr<T> lock() const{
        return std::shared_ptr<T>(cptr);
    }
    ~weak_ptr(){
        if(!cptr) return;
        --cptr->weak_count;
        if(cptr->weak_count == 0 &&cptr->shared_count== 0){
            delete cptr;
        }
    }

};

int main(){


}