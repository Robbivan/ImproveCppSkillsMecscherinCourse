#include <iostream>
#include <map>
//template <typename T>
//const T& maximum(const T& a, const T& b){
//    return a>b?a:b;
//}

template <typename T, typename U>
T maximum(const T& a, const U& b){
    return a>b?a:b;
}

// Шаблонный класс
template <typename T> //template <class T> тоже самое
class vector{
    // Шаблонный метод
public:
    template<typename U>
    void push_back(const U&){
    }
};

// Равносильно вне класса:
//template <typename T>
//template <typename U>
//void vector<T>::push_back(const U& x) {};

// Шаблонные псевдонимы
// C++11
template <typename T>
using mymap = std::map<T,T>;


// Шаблонные переменные
// С++14
template <typename T>
const T pi = 3.14;



void on_template_intro() {
    maximum(1,2);
    maximum<int>(1,2.0); //Приведение к общему int
    mymap<int> m;
    int a=0;
//    ++a;
}