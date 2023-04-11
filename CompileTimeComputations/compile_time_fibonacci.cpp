#include <iostream>

// Вычисления на этапе компиляции с помощью шаблонов

template<size_t N>
struct Fibonacci{
    static const size_t value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0>{
    static const size_t value = 0;
};

template<>
struct Fibonacci<1>{
    static const size_t value = 1;
};

int main(){
    std::cout<< Fibonacci<15>::value;

}
