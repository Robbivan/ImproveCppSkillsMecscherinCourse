#include <iostream>
#include <string>

// захват полей класса
struct S{

    int a = 1;
    // auto& ref = *this;
    auto foo(){
        auto f = [this](int x){ //поля нельзя захватывать, можно только this
            std::cout<<"Some "<<a+x; // тут неявно вызывается
        };
        return f;
    }
};

// since C++14
// Capture with init

struct SS{

    int a = 1;
    auto foo(){

        std::string str= "abced";

        auto f = [b = a, s = std::move(str)](auto x){ // auto и std::move
            std::cout<<"Some "<<b+x; // тут неявно вызывается
        };
        return f;
    }
};


int main(){
    auto f = S().foo();

    auto ff = S().foo(); // UB

    // Хотим нормально вернуть и не получить UB

}
