#include <iostream>
#include <vector>
// since C++11
// изменение в vector_with_allocators_and_move

// пример вызова конструктора в placement new или в allocator_traits::construct
// нужно скопировать объект типа T(value) в ячейку памяти и инициализировать там
// то есть используется конструктор копирования

// еще примером может служить reserve vector от нетривиальных объектов, например вектор векторов



/// Плохой пример
template<typename T>
void swap_bad(const T& left, const T& right){
    T tmp = left; // создается копия, плохо когда объекты с другими объектами
    left = right; // тоже копия, так как например перекладываем векторы
    right = tmp; // тоже копия, так как например перекладываем векторы, итого 3 копии
}
/// Хороший пример
template<typename T>
void swap_nice(const T& x, const T& y){
    T tmp = std::move(x);
    x = std::move(y);
    y = std::move(tmp);
}


template<typename T>
T createObject(...){
    // ...
    // ...
    // ...
    return object;
}
template<typename T>
void f(T x){
}

int main(){
    std::vector<std::string> v;
    v.push_back(std::string("abc")); // создается временная строка иниц. const std::string&

//    createObject<int>();
    f(createObject<some_type>()); // вернулось сюда, получилась копия при отправке в f

}