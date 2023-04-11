#include <iostream>
template<typename T>//шаблонная функция нужна для получения нужных констуркторов
T&& declval()noexcept;

template <typename T, typename ...Args>
struct is_constructible{
private:
    template<typename TT, typename ...AArgs>
    static auto f(int)-> decltype(TT(declval<AArgs>()...),int()){}


    template<typename ...>
    static char f(...){}
public:
    static const bool value = std::is_same_v<decltype(f<T, Args...>(0)), int>;

};

template<typename T, typename ...Args>
const bool is_constructible_v = is_constructible<T, Args...>::value;


int main(){

}
