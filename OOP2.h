class Base{

};


class Derived: public Base{

};

void on_oop_2(){
    Derived d;
    Base& b = d;
}