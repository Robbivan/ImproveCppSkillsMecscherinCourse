#include <iostream>

/// has_method_construct

// default construct problem and declval() function

template<typename T>//шаблонная функция нужна для получения нужных констуркторов
T&& declval()noexcept ;

// decval противоположно decltype
// decltype определяет по выражению тип
// decval определяет по типу выражение

template <typename T, typename ...Args>
struct has_method_construct{
private:
    template<typename TT, typename ...AArgs>
    static auto f(int)-> decltype(TT().construct(declval<AArgs>()...),int()){}


    template<typename ...>
    static char f(...){}
public:
    static const bool value = std::is_same_v<decltype(f<T, Args...>(0)), int>;

};


struct NotDefaultConstructible{
    NotDefaultConstructible() = delete;

};



struct S{
    void construct(int){}
    void construct(int, double){}
    void construct(NotDefaultConstructible){}
};

template<typename T, typename ...Args>
const bool has_method_construct_v = has_method_construct<T, Args...>::value;


int main(){



}



