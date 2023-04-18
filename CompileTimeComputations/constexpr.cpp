#include <iostream>
#include <array>
#include <vector>
/// constexpr since C++11 (variables and functions)


struct S{
    constexpr S(){
    }
    int x;
    double d;

};


// constexpr function - это такая функция, которая мб вызвана в compile time для расчета compile константы
constexpr int factorial(int n){ // не обязывает ее вычисления
//    нельзя бросать исключения
//    std::vector<int> v{1,2}; // так нельзя, потому что динамическая память

    S s; // создавать объекты можно если есть соот. конструктор с constexpr

    if(n==0){
        return 1;
    }
    return n* factorial(n-1);

}



int main(){

    int x;
    std::cin >> x;
    const int y = x;
    // тут константа высчитывает в RT


    constexpr int n = 5;
    std::array<int, n> a;

    constexpr int f = factorial(12);

    // since C++17
    if constexpr (sizeof(int)==4){
        std::cout<<1;
    }
    // где ложь не будет компилировать


    try{
        factorial(5); // тут уже constexpr не будет работать
    }catch (...){
        std::cout<<"Caught";
    }
    

}