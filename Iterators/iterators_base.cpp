#include <iostream>
#include <vector>
#include <list> // в С++ двусвязный список, в питоне = vector


// Итератор, то что ведет себя как итератор
// 1. Позволять разыменовывать
// 2. Позволять инкрементировать
// например с указатель это тоже итератор


// Виды итераторов:

int main(){
    std::vector<int> v = {1,2,3,4,5};
    std::vector<int>::iterator it =v.begin();
    std::list<int> lit = {1,2,3,4,5};

    *it;
    for(std::vector<int>::iterator iter =v.begin();iter!=v.end();++iter){
        std::cout<<*iter;
    }

    //C++11
    for (int x: lit){  // близко к итератором по логике
        std::cout<<x;
    }
}