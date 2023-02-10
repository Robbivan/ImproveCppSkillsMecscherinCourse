#include <iostream>

// Специализация шаблонов
template <typename T>
struct S{
    void f(){
        std::cout<<1;
    }
};
// хотим для bool вектора по-другому

// Полная explicit(явная) специализация
template <>
struct S <int>{
    void f(){
        std::cout<<2;
    }
};

// Частичная специализация
template <typename T>
class S<T*>{
    void f(){
        std::cout<<3;
    }

};

// У функций частичной специализации нет, так как есть перегрузка
template <typename T,typename U>
void f(T,U){
    std::cout<<1;
}

// Полная специализация зависит от того, что написано выше
//template<>
//void f(int,int){
//    std::cout<<3;
//}

template <typename T,typename U=int>
void f(T,T){
    std::cout<<2;
}
// Полная специализация
template<>
void f(int,int){
    std::cout<<3;
}

template <typename Key, typename Value, typename Comparator = std::less<Key>>
class Map{

};
int main(){
    S<double> s;
    S<int*> ss;

};