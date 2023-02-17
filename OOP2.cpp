#include <iostream>
class Base{

};


class Derived: public Base{ // private, то запретить cast от родителя

};

int main(){
    Derived d;
    Base& b = d;

    // slicing (срезка)
    Base bb = d; // копируется часть Base из d типа Derived

    Base& g = static_cast<Base&>(d); // явный каст, новая копия из derived
    // если приватное наследование, то нельзя
//    static_cast<Derived&>(b); // nак можно кастовать и вниз
    // но нужно быть уверенным в том, что там Base, а не Derived
    // static_cast может только вверх и вниз

    // reinterpret_cast может также вправо и влево (кроме вверх и вниз)



}