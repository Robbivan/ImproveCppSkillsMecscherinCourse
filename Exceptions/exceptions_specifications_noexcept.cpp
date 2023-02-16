#include <iostream>

struct S{
    int f(int x, int y){
        if (y==0){
            throw 1;
        }
        return x/y;
    }
};
struct F{
    int f(int x, int y) noexcept{
        return x*y;
    }
};
//C++11, функция не кидает исключения
template<typename T>
int f(int x, const T& y) noexcept {
    if (y==0) throw 1; //это RE, не отслеживает в compile time
    return x/y;
}

template<typename T>
int f(const T& x ){
    return f(1,x);
}

int main(){
    f(0);
}