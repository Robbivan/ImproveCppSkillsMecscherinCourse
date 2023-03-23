#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template <typename Iterator, typename IterCategory>
void my_advance_helper(Iterator& iter, int n, IterCategory){
    for(int i = 0;i<n;++i,++iter){}
}

template <typename Iterator>
void my_advance_helper(Iterator& iter, int n, std::random_access_iterator_tag){
    iter+=n;
}


//advance - продвинуть на какое-то место
//std::advance(iter,3);

//distance - расстояние между итераторами

// можно использовать std::iterator_traits


// Если писать через if else, то будет проблема с не компиляцией операции += для bid operator
// решение, чтобы избежать не компиляции - перегрузка шаблонной функции
template <typename Iterator>
void my_advance(Iterator& iter, int n){
    // если есть зависимый scope, то нужно указывать typename

    my_advance_helper(iter, n, typename std::iterator_traits<Iterator>::iterator_category());

//    since C++17
// решение проблемы компиляции через if constexpr
    if constexpr (std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>){
        iter+=n;
    } else{
        for(int i = 0;i<n;++i,++iter){}
    }


}


int main(){
    std::list<int> lst = {1,2,3,4,5};

    std::list<int>::iterator iter =lst.begin();
    std::advance(iter,3);
    std::cout<<*iter;
    std::list<int>::iterator ite2r =lst.end();
    std::cout<<std::distance(iter,ite2r);

}