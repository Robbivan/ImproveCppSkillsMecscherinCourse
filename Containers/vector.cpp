#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>


/// Sequence
/// Containers

// vector operation
// в динамике
// indexing [] - O(1) always
// push_back (front) - O(1) amortization
// insert, erase - O(n) (при уже "готовом" итераторе, имеющим нужное значение)
// find - нет
// iter category - random access category (continuous random access since C++17, то есть последовательно)

// deque
// indexing [] - O(1) always
// push_back (push_front) - O(1) amortization
// insert, erase - O(n) (при уже "готовом" итераторе, имеющим нужное значение)
// find - нет
// iter category - random access category (no continuous random access C++17)

// list и forward_list
// indexing [] - нет
// push_front - O(1) always
// insert, erase - O(1)  (при уже "готовом" итераторе, имеющим нужное значение)
// find - нет
// iter category - bidirectional / forward


/// Associative
/// containers

// set, map (разница лишь в том, что один хранит только keys, второй keys:value)
// indexing [] - log(n) always (Сбалансированное бинарное дерево поиска, реализуемое через Red-Black Tree)
// push_back (push_front) - нет
// insert, erase - log(n) always (Сбалансированное бинарное дерево поиска, реализуемое через Red-Black Tree)
// find - log(n) always
// iter category - bidirectional (если проходить по ключам, то последовательность в порядке возрастания)

// unordered_map, unordered_set - хэш
// indexing [] - O(1) mean (так как могут быть коллизии, то есть нужна защита - перебор до нужного места)
// push_back (push_front) - нет
// insert, erase - O(1) mean
// find - O(1) mean
// iter category - forward iterator

int main(){
    std::forward_list<int> f_lst = {1,2,3};
    f_lst.push_front(4);
    for (auto iter : f_lst){
        std::cout<<iter<<' ';
    }
    f_lst.pop_front();
}
