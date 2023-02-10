#include <iostream>
template <typename T>
struct S{
    using X = T;
};

template<>
struct S<int>{
    static int X;
};

int a =0;
template <typename T>
void f(){
//    S<T>::X * a; // тут компилятор не поймет что это умножение или указатель
//    // если int, то умножение, а уже например double это указатель
//    решение написать явно, что это typename
    S<T>::X * a;
}

template<typename T>
struct SS{
    template<int M, int N>
    struct A{};
};

template <>
struct SS<int>{
    static const int A;
};

template <typename T>
void g(){
    typename SS<T>::template A<1,2> a; // чтобы убрать A< 1 и 2>a (одного typename недостаточно, тк все равно идет сравн)
}

int main(){
    f<int>();
//    f<double>();
}