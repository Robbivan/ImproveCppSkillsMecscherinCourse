#include <iostream>

//template <typename T>
//std::remove_reference_t<T>&& move(T&& ref) noexcept{
//    return static_cast<std::remove_reference_t<T>&&>(ref);
//}
// аналогично написанному сверху
template <typename T>
auto move(T&& ref) noexcept
    ->std::remove_reference_t<T>&&
{
    return static_cast<std::remove_reference_t<T>&&>(ref);
}

int main(){

}
