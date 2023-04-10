#include <iostream>
#include <type_traits>

/// implementation

template<bool B,typename T = void>
struct enable_if{

};

template<typename T>
struct enable_if<true, T>{
    using type = T;
};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B,T>::type;


/// using

template<typename T, typename = std::enable_if_t<std::is_class_v<T>> >
void g(const T&){
    std::cout<<1;
}

template<typename T, typename = std::enable_if_t<std::is_class_v<
        std::remove_reference<T> >> >
void g(T&& ){
    std::cout<<2;
}
int main(){

}