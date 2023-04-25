#include <iostream>
#include <cstddef>

// since C++11

struct alignas(std::max_align_t) Pool{ //struct alignas(double) так тоже можно
    char arr[100'000];
};


// поля обязаны лежать подряд
struct S{
    char c;// если бы след. int, то размер был бы больше
    char cc;
    int i;

};
// выравнивание
int main(){
    int x = 0; // адрес кратен 4
    double d = 0.0; // адрес кратен 8

    std::cout<<alignof(double);
    // выравнивание полезно для некоторых процессоров с SSE инструкциями


}