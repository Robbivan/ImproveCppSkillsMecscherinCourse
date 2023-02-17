#include <iostream>


// noexcept принято ставить там, где 100% функция выполнится верно
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
//template<typename T>
//int f(int x, const T& y) noexcept {
//    if (y==0) throw 1; //это RE, не отслеживает в compile time
//    return x/y;
//}

template<typename T>
int f(const T& x ) noexcept(noexcept(x.f(1,0))){ // первый noexcept спецификатор(может содержать условие),
    // второй оператов
    return x.f(1,0);
}

int main(){
//    Операторы, которые приводят к исключениям
//  throw
//  new
//  dynamic_cast
// noexcept func call

//    f(0);

}