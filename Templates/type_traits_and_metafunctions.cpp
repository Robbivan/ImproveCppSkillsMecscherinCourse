#include <iostream>
//C++11
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <type_traits>
// метафункции

template <typename U, typename V>
struct is_same{
    static const bool value = false;
};

template <typename U>
struct is_same<U,U>{
    static const bool value = true;
};

// Если не конст, то ничего не изменится
template <typename T>
struct remove_const{
    using type = T;
};

// константа станет не константой
template <typename T>
struct remove_const<const T>{
    using type = T;
};

// частичная специализация для remove references
template <typename T>
struct remove_const<T&>{ /// удаление ссылки для move
    using type = T;
};

//std::decay<T>::type; // делает все: меняет [] на *, снимает константность и тд

template <typename U, typename V>
void f(U x, V y){
    //Логика зависит от того равны типы или нет
    //...
    typename remove_const<U>::type a;
    // используются метафункции
    if (is_same<U,V>::value){ // C++17 is_same_v<U,V>
    }else{
        //...
    }
    //...
}

template <typename T>
class C{
        C()=delete;
    };


// since C++14
template <typename T>
using remove_const_t = typename remove_const<T>::type;
// и тд.


// since C++17
template <typename U, typename V>
const bool is_same_v = is_same<U,V>::value;




int main(){
//    C<typename std::decay<int*[10][10]>::type> x;
    int *a[10];
}