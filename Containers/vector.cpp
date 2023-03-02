#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>


/// Sequence
/// Containers

// vector operation
// в динамике
// O(1) always - indexing []
// O(1) amortization - push_back (front)
// O(n) insert, erase при уже "готовом" итераторе, имеющим нужное значение
// find - нет
// iter category - random access category (continuous random access since C++17, то есть последовательно)

// deque
// O(1) always - indexing []
// O(1) amortization - push_back (push_front)
// O(n) insert, erase при уже "готовом" итераторе, имеющим нужное значение
// find - нет
// iter category - random access category (no continuous random access C++17)

// list и forward_list
// indexing [] - нет
// O(1) always - push_front
// O(1) insert, erase при уже "готовом" итераторе, имеющим нужное значение
// find - нет
// iter category - bidirectional / forward

int main(){
    std::forward_list<int> f_lst = {1,2,3};
    f_lst.push_front(4);
    for (auto iter : f_lst){
        std::cout<<iter<<' ';
    }
    f_lst.pop_front();
}
