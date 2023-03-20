#include <iostream>

template <typename T>
std::remove_reference_t<T>&& move(T&& ref) noexcept{
    return static_cast<std::remove_reference_t<T>&&>(ref);
}

int main(){

}
