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

//std::decay<T>::type; // делает все: меняет [] на *, снимает константность и тд

template <typename U, typename V>
void f(U x, V y){
    //Логика зависит от того равны типы или нет
    //...
    typename remove_const<U>::type a;
    // используются метафункции
    if (is_same<U,V>::value){
    }else{
        //...
    }
    //...
}

template <typename T>
class C{
        C()=delete;
    };


int main(){
    C<typename std::decay<int*[10][10]>::type> x;
    int *a[10];
}


