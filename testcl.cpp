#include <iostream>

struct Base{
    Base()=default;
    int a;
    int b;
    int c;
    Base( const int& a,const int& b,const int& c):a(a),b(b),c(c){

    }
    Base(const Base& base_old):a(base_old.a),b(base_old.b),c(base_old.c){
    }
    Base& operator = (const Base& base_old){
        a = base_old.a;
        b = base_old.b;
        c = base_old.c;
        return *this;
    }


};

template <typename T>
struct S{

};

template<>
struct S<int>{

};

template<typename T>
struct S<T*>{

};

int main(){
    Base base_old(1,2,3);
    Base base_new = base_old;
    Base base_newest(2,3,4);
    base_newest = base_old;
    std::cout<<base_newest.a;



}