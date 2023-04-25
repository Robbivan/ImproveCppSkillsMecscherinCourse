#include <iostream>
#include <functional>

/// std::function (since C++11)
struct S{
    int y = 1;
    void goo(int x){
        std::cout<<x+y<<'\n';
    }
    bool operator()(int x, int y)const{
        std::cout<<"hello";
        return x>y;
    }
};

bool g(int x, int y){
    std::cout<<"Blablabla"<<'\n';
}

int main(){
    std::function<bool(int,int)>f;

    f = [](int x, int y){
        std::cout << "Func is" <<'\n';
        return x<y;
    };

    f(1,2);
    f = S();

    f(3,4);
    f = g;

    f(5,6);

    void (S::*ps)(int)=&S::goo;
    S s;
    std::function<void(S&, int)> memfn = &S::goo; // аналог

    memfn(s,5);


}
