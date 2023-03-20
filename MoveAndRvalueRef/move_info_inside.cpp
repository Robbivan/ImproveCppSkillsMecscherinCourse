#include <iostream>


/// lvalue and rvalue
// по-простому lvalue, то чему можно присваивать, rvalue чему нельзя
// однако много исключений
// для left: const или объект, у которого не определено присваивание
// для right: временный объект, например в std::swap() или

// Лучшее определение
// lvalue и rvalue всегда зависят от контекста и являются видами выражений, а не объектами или типами

// type&& - rvalue-references,
// type& - lvalue-references

//             expressions
//          /               \
//      lvalue                rvalue
//                          /        \
//                        xvalue   prvalue(pure)

// примеры классификации внутри презентации

int main(){

}