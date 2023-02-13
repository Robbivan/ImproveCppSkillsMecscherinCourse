#include <iostream>

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