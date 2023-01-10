#include <iostream>
#include <algorithm> //sort


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
    using std::cout;
    int a[5]={3,7,1,8,9};
    // указываются начало и конец
    std::sort(a,a+5,cmp); // тут есть 3 параметр компаратор
    // если убрать компаратор, то по умолчаюнию
    for (int i:a){
        cout<<i;
    }
}


int main() {
    def_sort();

    return 0;
}
