#include <iostream>
#include <vector>


//          Invalidation rules
//                          iterators   pointers/references
// vector               |     Bad     |         Bad
// deque                |     Bad     |         Good
// list                 |     Good    |         Good
// map/set              |     Good    |         Good
// unordered_map/set    |     Bad     |         Good
//                            ok, if there
//                            was no rehash


int main(){
    std::vector<int> v;
    v.push_back(1);

    std::vector<int>::iterator it =v.begin(); // в случае дека портятся только итераторы
    int *p = &v.front();
    int &r = v.front();
    // все 3 варианта приведут к инвалидации итераторов при
    v.push_back(3);
    // после этого произошло "перекладывание" в новый динамический массив с каким-то capacity
    // а все что указывало на элемент в изначальном векторе стало UB

}
