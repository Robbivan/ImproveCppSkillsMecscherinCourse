#include <iostream>
#include <vector>
#include <list> // в С++ двусвязный список, в питоне = vector
#include <map>

// Итератор, то что ведет себя как итератор
// 1. Позволять разыменовывать
// 2. Позволять инкрементировать
// например указатель это тоже итератор


// Виды итераторов:
//
// Input Iterator - позволяет один раз пройтись по последовательности, например поток ввода
// std::istream
//
// однонаправленные итераторы оператор Forward, Операции: ++
// например forward_list, unordered_map, unordered_set
//
// двунаправленные Bidirectional, Операции: ++, --
// например list, map, set
//
// Random access common_iterator, Операции: ++, --, it1-it2, it1>it2
// например vector, deque

int main(){
    std::vector<int> v = {1,2,3,4,5};
    std::vector<int>::iterator it =v.begin();
    std::list<int> lit = {1,2,3,4,5};
    std::make_
    *it;
    //since C++11 можно использовать auto для iter
    for(std::vector<int>::iterator iter =v.begin();iter!=v.end();++iter){
        std::cout<<*iter;
    }

    //since C++11
    for (int x: lit){  // близко к итераторам по логике
        std::cout<<x;
    }


    std::map<int,int> m;
    m[3] = 5;
    m[5] = 9;
    m[9] = 8;

    std::map<int,int> ::iterator it1 = m.find(3);
    std::map<int,int> ::iterator it2 = m.find(5);

//    if (it1<it2){ так будет ошибка, так как нет такой операции над bidirectional
//
//    }
//    it1+=1 - тоже нельзя, так как тоже нет такой операции

}