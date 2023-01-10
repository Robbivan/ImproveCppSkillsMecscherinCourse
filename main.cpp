#include <iostream>
#include <algorithm> //sort
#include <vector>
#include "test.h"


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

void vector_work(){
    using std::vector;
    vector<int> v = {1,2,3,5,6};
    vector <int> vv = v; //дилемма (vv это другой вектор)?
    // в Java,Python это будут ссылки
    // в Плюсах это КОПИЯ!
    // чтобы была ссылка
    vv[0]=0;
    vector <int> &vvv =v;
    vvv[0] =987;
    cout<<vv[0]<<" Новый контейнер\n";
    cout<<vvv[0]<<" Ссылка на v контейнер\n";
    cout<<v[0]<<" Тут не меняли, но из-за vvv получилось = 987\n";


}


int main() {
    using std::cout;
    def_sort();
    Hello();
    vector_work();
    return 0;
}
