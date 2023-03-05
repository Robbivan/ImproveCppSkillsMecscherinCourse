#include <iostream>
#include <functional>
template <typename T>
class C{
    C()=delete;
};


template <typename T>
void f(T x){
    C<T> c; //трюк Скотта Мейерса
    // здесь специально ошибка, чтобы понять, что на этапе компиляции подставил компилятор внутрь с
}


//  Облегченная версия трюка Скотта Мейерса
template <typename U>
void ff(const U&) = delete;


int main(){
    int x =0;

    int& y = x;

    const int& z=x;

    f(std::ref(x)); //references wrapper (отличие от обычной ссылки - если ее переприсваивать, то слетит)
    // легковесная ссылка std::cref константная ссылка
    ff(34);
}