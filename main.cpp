#include <iostream>
#include <algorithm> //sort
#include "references.h" // файл с ссылками
#include "consts.h" // файл с константами
#include "OOP.h"
#include "OOP2.h"
#include "StringClass.h"
#include "operators.h"
#include "static_fields.h"
#include "explicit-methods.h"
#include "callback_functors_comparators.h"
#include "multiple_inheritance.h"

// Функция компаратор по умолчанию
// Принимает аргументы:
// int a - число слева
// int b - число справа
// return:
// a>b - неравенство для сортировки по убыванию
bool cmp(int a, int b){
    return a>b;
}

// Функция сортировки массива из библиотеки algorithm
void def_sort(){

    int a[5]={3,7,1,8,9};
    // указываются начало и конец
    std::sort(a,a+5,cmp); // тут есть 3 параметр компаратор
    // если убрать компаратор, то по умолчаюнию
    for (int i:a){
        cout<<i;
    }


}

// Функция приведения типов
void Casts(){
    int x = 0;
    double d = static_cast<double>(x); // Static cast, когда не знаете к какому типу, работает на этапе компиляции


    // Запретные заклинания:
    // Reinterpret cast
    double dd = 3.14;
    cout<<std::hex<<reinterpret_cast<int&>(dd); // Берет старый (плохой вариант) - к ссылке
    // Const cast
    {
        const int cx=1;
    //  int& x = cx; не заработает, так как нельзя приводить копию на константный тип
        int& x = const_cast<int&>(cx);
    }
    // С-style cast
    // сразу все 3, что выше
    // Сначала const cast, затем static cast, затем const+static cast, затем reinerpret cast, затем
    // reinerpret+const cast, затем CE
    {
        int x =0;
        double d = (double) x;
    }
    // dynamic cast - RunTime Error
}


int main() {
    using std::cout;

    def_sort(); // из algorithm
//
    ref_root(); // из файла references


    Bad_example example;
    int some_value = 0;
    example.print( some_value);


    on_string(); // Класс String
    on_operator(); //Класс с комплексными числами и операторами
    on_explicit();
    on_func();
    on_miltiple_inheritance();

    return 0;
}
