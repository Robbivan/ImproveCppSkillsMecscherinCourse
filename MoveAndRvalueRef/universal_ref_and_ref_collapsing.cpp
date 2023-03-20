#include <iostream>

/// universal references
/// или forward ref

// f(const type& x) // умеет принимать и rvalue, и lvalue, но только константные
// f(type& x) // только lvalue
// f(type&& x) // только rvalue

// для move нужна неконстантная ссылка

// шаблонная функция умеет принимать и rvalue, и lvalue
// считаются более хорошими при перегрузке, т.е. отдаются предпочтения им
// и не работает правило частное лучше общего
template<typename T> // именно шаблонный параметр функции!!!
void f(T&& x){ // тут не будет работать, если что-то другое
    // ...
}
int main(){
    f(5); // rvalue, T = int, decltype(x) = int&&
    int y = 5; // lvalue
    f(y); // T = int&(!!!), decltype(x) = int&

    // Правила ref collapsing:
    // & + & = &
    // & + && = &
    // && + & = &
    // && + && = &&

}