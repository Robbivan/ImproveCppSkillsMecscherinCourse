#include <iostream>
#include <vector>
// RAII
// Resource acquisition is initialization:
// Захват ресурса через создание объекта владельца-ресурса




// Решение через smart pointers
template <typename T>
class Smartptr{
private:
    T*ptr;
public:
    Smartptr(T* _ptr):ptr(_ptr){}
    ~Smartptr(){
        delete ptr;
    }
};

struct SS{
    int x =0;
    SS(int x):x(x){};
    SS(const SS& s):x(s.x){
        if (x==8){
            throw 1;
        }
    }
};

struct S{
//    int *p = nullptr;
    Smartptr<int>p= nullptr;
    S():p(new int (5)){
        throw 1; // так нельзя
    }
//    ~S(){ // не будет вызываться деструктор
//        delete p;
//    }
};
void f(){
//    int* p = new int;
    Smartptr<int> p = new int(5);
    Smartptr<int> pp = p; // так будет SF, так как потеря памяти
    // решение через move-семантику и подсчет ссылок
    throw 1;
//    delete p; //так как сработает throw, то будет утечка памяти
}
int main(){
    std::vector<SS> v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(SS(i)); // вектор умеет доопределять память
    }



    try{
//        f();
        S s;
    }
    catch (...){
        std::cout<<"catch it";
    }
}