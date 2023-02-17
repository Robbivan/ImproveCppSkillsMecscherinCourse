#include <iostream>
struct Bad_example{
private:
    int x =0;
    std::string s;
    double d = 0.0;
public:
    void print(int& a){
        std::cout<<x+a;
    }
    void print(double& a){
        std::cout<<x+a+1;
    }
};

class C_ex{
private:
    int x =0;
    std::string s;
    double d = 0.0;
    void bit(int& a);
public:
    double print(double& a){
        return x+a+1;
    }
};

//Пример метода вне класса
void C_ex::bit(int &x) {
    //Запрет вызова от int
    std::cout<<this->x+x;
}

struct Granny{
    int a=0;
    Granny(int a):a(a){}

    Granny() {}

//
    void f(){
        cout<<"Granny";
    }
};

struct Mom: public Granny
{
    Mom()=default;
    // чтобы f в Mom не затмевал f из конструктора в Granny, то можно написать
    using Granny::f;
    // примечание: но поля должны быть с разными именами


    using Granny::Granny; // Явное наследование конструктора из Granny С++11


    int a = 1;
    void f(){
        cout<<"Mom";
    }
};

int main(){
    Mom m;
    cout<<m.a;
    cout<<m.Granny::a;

}



