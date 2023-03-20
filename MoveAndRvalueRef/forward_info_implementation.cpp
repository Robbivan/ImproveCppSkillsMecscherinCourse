#include <iostream>
// пример perfect forwarding problem and std::forward

// std::forward позволяет делать move только для тех, у кого && ссылки
// явный пример задан в vector, в частности emplace_back()
// std::forward<Args>(args)

// Реализация
template <typename T>
T&& forward(std::remove_reference_t<T>& ref)noexcept{ // тут в форварде будет lvalue
    return static_cast<T&&>(ref); // близкое к move от одного & к &&
}

// arg was a lvalue
// arg = type&
// decltype(arg) = type&
// T = type&
// ref = type&
// T&& = type&

// arg was a rvalue
// arg = type
// decltype(arg) = type&&
// T = type
// ref = type&
// T&& = type&&

int main(){

}
