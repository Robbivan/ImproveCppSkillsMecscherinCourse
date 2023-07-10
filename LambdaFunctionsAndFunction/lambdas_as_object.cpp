#include <iostream>

//template<typename T>
//void f() = delete;

// компилятор генерирует под каждую лямбда функцию класс, который олицетворяет эту функцию
int main(){
    int a = 1;
    auto inf = [](int x, int y){
        return x<y;
    };

    std::cout << typeid(inf).name();
    std::cout << sizeof(inf); // 1 байт, так как пустой класс


    // передали a в класс
    auto inf2 = [a](int x, int y){
        return x+a<y;
    };

    std::cout<< sizeof(inf2); // 4 байта, равный одному полю int


    auto inf3 = [&a](int x, int y){
        return x+a<y;
    };
    std::cout<< sizeof(inf3); // 8 байт, равный ссылке

    auto inf4 = inf3; // полная копия

    auto inf5 = std::move(inf4); // будет перемещена в rvalue inf5

//    inf5 = inf4; оператора присваивания для лямбда функций нет

    decltype(inf4) inf6;



}
