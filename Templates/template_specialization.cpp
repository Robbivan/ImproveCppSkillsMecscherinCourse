#include <iostream>

// Специализация шаблонов
template <typename T>
struct S{
    void f(){
        std::cout<<1;
    }
};
// хотим для bool вектора по-другому

// Полная explicit(явная) специализация
template <>
struct S <int>{
    void f(){
        std::cout<<2;
    }
};

// Частичная специализация
template <typename T>
class S<T*>{
    void f(){
        std::cout<<3;
    }

};

// У функций частичной специализации нет, так как есть

int main(){
    S<double> s;
    S<int*> ss;

};