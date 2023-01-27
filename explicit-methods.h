#include <iostream>

struct UserId{
private:
    int id = 0;
public:
    explicit UserId(int id):id(id){}

    explicit operator int(){
        return id;
    }
};
struct GroupId{
private:
    int id =0;
public:
    GroupId(int id):id(id){}

    operator int(){
        return id;
    }
};



void on_explicit(){
    UserId id(5);// UserId id = 5 уже не прокатит

    //    std::cout<<'\n'<<id+5; из-за запрета на неявное приведение типов explicit
    // в if (){ } не работает explicit
}
