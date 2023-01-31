#include <iostream>

// RTTI = Run-Time Type Information
// Компилятор сохраняет информацию о типе, соот. не нужно поле type = 1 или type = 2



struct Base{
    virtual ~Base(){}
    virtual void f(){
        std::cout<<'1';
    }
};

struct Derived:public Base{
    void f() override{
        std::cout<<'2';
    }
};

void on_RTTI(){
    int x;
    std::cin>>x;

    Base b;
    Derived d;

    Base& bb = x>0?b:d;
    bb.f();
}