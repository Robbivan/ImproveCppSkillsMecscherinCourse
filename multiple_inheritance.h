#include <iostream>
struct GrannyB{
    int f = 0;
};

struct Mother:public GrannyB{
    int m=1;
    //    int a;
};

struct Father:public GrannyB{
    int f=2;
    //    int a;
};

struct Son:public Mother, public Father{
    int s = 3;
};

void on_miltiple_inheritance(){
    Son s;
    std::cout<<'\n'<<&s<<'\n';
    Father *pf = &s;
    std::cout<<pf<<'\n'; // разница в 4 байта, так как
    //    [mother 4] [father 4] [son 4], т. е. указатель как бы сдвинулся (неявно кастанулся)
    std::cout<< static_cast<Son*>(pf); // так можно вернуться
    //    std::cout<<s.Mother::a;

    // Diamond problem или ромбовидное наследование
    // Появляются 2 копии одной бабушки
    // [g] [m] [g] [f] [s]
    // чтобы обращаться, нужно явно указывать

    std::cout<<s.Mother::f;




}