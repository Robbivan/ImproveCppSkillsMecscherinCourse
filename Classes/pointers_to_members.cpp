#include <iostream>

struct S{
    int x;
    double d;
    void f(char c){}
};

int main(){
    // указатель на поле x структуры S
    int S::*p = &S::x; // тут объект не нужен, сдвиг относительно начала структуры

    S s{5,3.0};
    std::cout<<s.*p;

    void (S::*pf)(char) = &S::f;

    S* ps = &s;
    (s.*pf)('a');

    (ps->*pf)('b');

}
