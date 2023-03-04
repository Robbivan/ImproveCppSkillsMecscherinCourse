#include <iostream>

//В С++ не принято использовать функции с множеством параметров, с этой целью используются вариативные шаблоны
void print(){}//перегрузка от 0 аргументов
template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail ){
    std::cout<<head<<'\n';
    std::cout<<sizeof...(tail); //размер пакета
    print(tail...);
}


template <typename First, typename Second, typename ...Types>
struct is_homogeneous;

template <typename ...Args>
const bool is_homogeneous_v = is_homogeneous<Args...>::value;


template <typename First, typename Second, typename ...Types>
struct is_homogeneous{
    static const bool value = std::is_same_v<First, Second> && is_homogeneous_v<Second,Types...>;

};


template <typename First, typename Second>
struct is_homogeneous<First,Second>{
    static const bool value = std::is_same_v<First, Second>;

};



int main(){
    print(1,"abs",2.0);
}