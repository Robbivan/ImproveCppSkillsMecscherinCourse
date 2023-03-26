#include <iostream>
#include "unordered_map"

/// type deduction (since C++11)

int&f (int& x){
    return x;
}

template<typename T> // классический трюк Скотта-Майерса не поможет для && и &, будет виден только int
void foo(T) = delete; // так как отбрасываются & и &&

template<typename T>
void foo_s() = delete;


auto ff(int&x){
    if(x>5){
        return x;
    }
//    return 0.5;

}

// since C++11
template <typename T>
auto h(const T& x)-> decltype(f(x))
{
    std::cout<<"some text";
    return f(x); // не знаем что тут ссылка или не ссылка
}

// Пример из Скотта-Мейерса
template <typename Container>
auto get(const Container& container, size_t index)-> decltype(container[index])
{
    std::cout<<"some text";
    return container[index]; // обычно возвращает ссылку кроме vector<bool>, тут будет rvalue
}


// since C++14
template <typename T>
decltype(auto) h(const T& x){
    std::cout<<"some text";
    return f(x);
}

int main(){
//    std::unordered_map<std::string, int, std::hash<std::string>,std::equal_to<std::string>, FastAllocator<std::pair<const std::string, int>> map;
//    std::unordered_map<std::string, int, std::hash<std::string>,std::equal_to<std::string>,
//    FastAllocator<std::pair<const std::string, int>>::iterator it = m.begin();// боль

    std::unordered_map<std::string, int> map;
    // auto

    for (const std::pair<const std::string, int>& item:map ){

    }
    for (auto item:map ){ // тут будет копирование так как не по ссылке

    }
    for (const auto& item:map ){

    }

    for( const auto& [key, value] : map ){
        std::cout<<key<<value;
    }
//        print_key_value(key, value);
    int x = 1;
    auto& y = f(x);
    std::cout<<x<<' '<<y;


    // universal_ref
    auto &&yy = f(x); // lvalue

    auto &&yy2 = std::move(f(x));



    ///decltype


    foo_s<decltype(x)>(); // будет compile error, которая даст увидеть тип, в данном простом случае int
    /// decltype не отбрасывает & и &&, то есть с помощью него можно определить ссылка или нет
    foo_s<decltype(yy)>(); // тут будет &
    foo_s<decltype(yy2)>(); // тут будет &&


    decltype(yy) t = x; // по сути int& t, так как decltype(yy) вернет lvalue = int&
    ++t;
    decltype(yy)& tt = x; // можно сверху навесить еще &, тогда будет сворачивание ссылок
//    foo(yy2);
    decltype(x++) u = x; // тут ничего не произойдет, так как в compile time подставляется тип

    ///НО!
    // есть правила для decltype:
    // если выражение не индефикатор:
    // - если expr is prvalue типа T, тогда decltype(expr) is T (например x++)
    // - если expr is lvalue типа T, тогда decltype(expr) is T& (например ++x)
    // - если expr is xvalue типа T, тогда decltype(expr) is T&& (например std::move(++x))


    decltype(throw 1)* p = nullptr; // это void*, так как у throw void
    // так нельзя)


    decltype(auto) t2 = yy;
}
