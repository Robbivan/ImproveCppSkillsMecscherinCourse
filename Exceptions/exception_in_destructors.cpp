#include <iostream>

// Итог, лучше НЕ БРОСАТЬ ИСКЛЮЧЕНИЯ В ДЕСТРУКТОРЕ
// с С++11 все деструкторы по умолчанию noexcept, для того чтобы убрать (если не хакер, то не надо:D)
// noexcept(false)

// C++ не поддерживает несколько исключений одновременно
struct Dangerous{
    int x =0;
    Dangerous(int x):x(x){}
    ~Dangerous()noexcept(false){ //
        if(x==0){
            throw 1;
        }
    }
};

void g(){
    Dangerous dan(0);
    std::cout <<dan.x;

}

void f(){
    Dangerous dan(0);
    std::cout <<dan.x;
    g();
}

int main(){
    f();
}
