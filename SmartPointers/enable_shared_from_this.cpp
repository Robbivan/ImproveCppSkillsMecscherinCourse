#include <iostream>
#include <memory>

/// enable_shared_ptr_from_this
// CRTP = Curiously Recursive Template Pattern

// implementation
template <typename T>
class enable_shared_from_this{
private:
    std::weak_ptr<T>wptr = nullptr;
    // создание регулируется в shared_ptr
protected:
    std::shared_ptr<T> shared_from_this() const{
        return wptr.lock();
    }


};


struct S: public std::enable_shared_from_this<S>{ // наследник от библиотечной реализации
    std::shared_ptr<S> getPointer() {
        //...
        //return this;
        return shared_from_this();
    }
};

int main(){

}
