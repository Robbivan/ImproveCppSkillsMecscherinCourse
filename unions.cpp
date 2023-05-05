#include <iostream>

union U{
    int x =1;
    double d;
};

union UU{
    UU(const char*p):s(p){};
    int x = 1;
    double d;
    std::string s; // тут наибольший размер имеет string

    ~UU(){};
};



// Отличие от структуры и класса - можно хранить одну вещь в один момент времени
// sizeof(U) = alignas(max(sizeof(x),sizeof(d),sizeof(s)))(std::max_align_t)
int main(){

    std::string s;
    std::cout<<sizeof(s);

    U u;

    std::cout<<u.x; // по умолчанию 0

    u.d = 4.5;
    std::cout<<u.d;


    UU uu = "abc";
    uu.s.~basic_string();



    // вместо 1 на месте x уже UB






}
