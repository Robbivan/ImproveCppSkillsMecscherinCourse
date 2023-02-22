#include <iostream>
#include <vector>
#include <list>


//advance - продвинуть на какое-то место
//std::advance(iter,3);

//distance - расстояние между итераторами

// можно использовать std::iterator_traits
template <typename Iterator>
void my_advance(Iterator& iter, int n){
//TODO
}


int main(){
    std::list<int> lst = {1,2,3,4,5};

    std::list<int>::iterator iter =lst.begin();
    std::advance(iter,3);
    std::cout<<*iter;
    std::list<int>::iterator ite2r =lst.end();
    std::cout<<std::distance(iter,ite2r);

}