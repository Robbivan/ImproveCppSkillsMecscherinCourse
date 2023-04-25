#include <iostream>
#include <any>
#include <vector>

class any{
    struct Base{
        virtual Base* clone()=0;
        virtual ~Base()=default;
    };

    template<typename T>
    struct Derived:public Base{
        T object;
        Base* clone() override{
            return new Derived<T>(object);
        }
        Derived(const T& object):object(object){}
    };
    Base* ptr = nullptr;
public:
    template<typename U>
    any(const U& object):ptr(new Derived<U>(object)){

    }
    any(const any& other):ptr(other.ptr->clone()){}

    template<typename U>
    auto& operator=(const U& object){
        delete ptr;
        ptr = new Derived<U>(object);
    }
    ~any(){
        delete ptr;
    };
};

//std::any since С++17
int main(){

    std::any a = 5;
    std::vector<int> v {1,2,3};
    a = v;
    a = 'a';
    std::cout<<std::any_cast<int>(a);
    std::cout<<std::any_cast<auto>(a);

}
