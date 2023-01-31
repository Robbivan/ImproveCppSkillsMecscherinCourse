#include <iostream>

class Shape{
public:
    virtual double area() const=0; // Значит объявление будет только у наследников
};

class Triange:public Shape{
public:
    double area() const override{
        return 0.0;
    }
};

void on_abstract_class(){
    Triange tr;
    Shape& s =tr;
    std::cout<<s.area(); //вызовится для квадратач
}