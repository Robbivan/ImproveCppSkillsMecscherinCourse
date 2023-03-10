#include <iostream>
#include <vector>



int main(){
    std::vector<int> v;
    v.push_back(1);

    std::vector<int>::iterator it =v.begin();
    int *p = &v.front();
    int &r = v.front();
    // все 3 варианта приведут к инвалидации итераторов при
    v.push_back(3);
    // после этого произошло "перекладывание" в новый динамический массив с каким-то capacity
    // а все что указывало на элемент в изначальном векторе стало UB



}
