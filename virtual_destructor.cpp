#include <iostream>


// ГЛАВНОЕ: ЕСЛИ ЕСТЬ ВИРТУАЛЬНЫЕ ФУНКЦИИ, ТО ДЕЛАТЬ ЯВНЫЙ ВИРТУАЛЬНЫЙ ДЕСТРУКТОР



// Нужно явно сказать, что он виртуальный
struct GrandBase{
    virtual void f() =0;
    virtual ~GrandBase() = 0;
};
GrandBase::~GrandBase() {}
// Если таким образом выражается базовый класс через наслежника, то необходим виртуальный деструктор
struct Base:public GrandBase{
    int* a = new int();
    void f() override{}
    virtual ~Base(){
       std::cout<<"~Base";
       delete a;
    }
};

struct Derived: public Base{
    int* b = new int();
    ~Derived(){
        std::cout<<"~Derived";
        delete b;
    }
};
int main(){
    Base* b = new Derived(); //создание наследника по родителю
    GrandBase * gb =new Derived;
    delete b;
    delete gb;
};