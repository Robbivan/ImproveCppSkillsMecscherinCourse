#include <iostream>

template <typename T,typename U>
void foo(T x, U y){
    std::cout<<1;
}

//1. Лучше частное, чем полное
//2. Лучше найти полное соответствие, чем приводить тип
template <typename T>
void foo(T x, T y){
    std::cout<<3;
}

void foo(int x, double y){
    std::cout<<3;
}

// Неоднозначность вызова
//template <typename T>
//void foo(T x, int y){
//    std::cout<<3;
//}
//template <typename T>
//void foo(int x, T y){
//    std::cout<<3;
//}


int main(){
    foo(5,6);
    //выберет частное
    foo(6,8);
}