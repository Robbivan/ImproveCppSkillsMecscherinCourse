#include <iostream>

// полная жесть...

template<typename T>
auto move_if_noexcept(T& x)->std::conditional_t<std::is_nothrow_constructible_v<T>,T&&, const T>
{
    return std::move(x);
};

template<typename T, T v>
struct integral_constant{
    static const T value = v;
};

struct true_type: integral_constant<bool, true>{};
struct false_type: integral_constant<bool, false>{};

template <typename T>
struct is_nothrow_move_constructible{
private:
    template<typename TT, typename ...AArgs>
    static auto f(int)-> std::conditional_t<noexcept(std::declval<TT>()), true_type, false_type>;
//    decltype(TT(std::declval<const TT&>()), int()){};
    template<typename ...>
    static auto f(...)->false_type{};
public:
    static const bool value = decltype(f<T>(0))::value;
};

template<typename T>
const bool  is_nothrow_move_constructible_v = is_nothrow_move_constructible<T, const T& >::value;


int main(){

}