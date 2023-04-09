#include <iostream>

int main(){
    int a = 1;
    [a](int x){ //захват переменной извне
        // по умолчанию a становится const
        std::cout<<"s"<<x+a;
        //++a; не получится
    }(5);

    [a](int x)mutable {
        //захват переменной извне
        // по умолчанию a становится const
        std::cout<<"s"<<x+a;
        ++a;
    }(5);

    [&a](int x) { //не надо mutable
        // int& const = int&
        std::cout<<"s"<<x+a;
        ++a;
    }(5);

    // если все хотим локальные переменные, то [=]
}
