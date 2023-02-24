#include <iostream>
#include <list>
#include <vector>
#include <algorithm>


// Output iterator
// set_intersection - пересечение множеств


struct IsEven{
    bool operator()(int x) const{
        return x&1;
    }
};

template <typename Container>
class back_insert_iterator{
    Container& container;
public:
    back_insert_iterator(Container& container):container(container){}
    back_insert_iterator<Container>& operator++(){
        return *this; //ничего не делает при инкрементировании
    }
    back_insert_iterator<Container>& operator*(){
        return *this;
    }
    back_insert_iterator<Container>& operator=(const Container::value_type& value){
        container.push_back(value);
        return *this;
    }
};

template <typename Container>
back_insert_iterator<Container>back_inserter(Container& container){
    return back_insert_iterator<Container>(container);
}

int main(){
    std::list<int> lst = {1,2,3,4};
    std::vector<int> v;
    // стандартные итераторы не являются output
    // поэтому так плохо,
    std::copy_if(lst.begin(),lst.end(),v.begin(),IsEven());
    // так как в любой момент может произойти UB

    // Правильно использовать back_inserter
    std::copy_if(lst.begin(),lst.end(),std::back_inserter(v),IsEven());
    // back_inserter создает back_inserter итератор (выше написан)


}