#include <iostream>

struct UserId{
private:
    int id = 0;
public:
    explicit UserId(int id):id(id){}

    explicit operator int(){ //с++11
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

// c++11 перегрузка нижнего литерала
UserId operator ""_uid(unsigned long long x){
    return UserId(x);
};


int main(){
    UserId id(5);// UserId id = 5 уже не прокатит
    UserId uid = 5_uid;


    //    std::cout<<'\n'<<id+5; из-за запрета на неявное приведение типов explicit
    // в if (){ } не работает explicit
}
