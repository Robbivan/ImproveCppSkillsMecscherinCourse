#include <iostream>

namespace detail_is_base_of{
    template <typename B>

    auto f(B*)->std::true_type;

    template<typename ...>
    auto f(...)->std::false_type;


    template<typename B,typename D>
    auto test()-> decltype(f<B>(std::declval<D*>())){}

    template<typename...>
    auto test()->std::true_type;
}


template<typename T, T v>
struct integral_constant{
    static const T value = v;
};

template<typename B, typename D>
struct is_base_of:integral_constant<bool,std::is_class_v<B>
        &&std::is_class_v<D>
        && decltype(detail_is_base_of::test<B,D>(0))::value>
        {

};


struct Base{

};
struct Derived:Base{

};


template<typename B, typename D>
using is_base_of_v = typename is_base_of<B,D>::value;


int main(){

}