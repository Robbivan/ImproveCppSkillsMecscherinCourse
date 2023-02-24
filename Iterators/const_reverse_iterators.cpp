#include <iostream>
#include <list>
#include <vector>


//const iterators



// "ручная" реализация std::conditional()
template <bool B, typename T, typename F>
struct conditional{
    using type = F;
};

template <typename T, typename F>
struct conditional<true,T,F>{
    using type = T;
};

template <bool B, typename T, typename F>
using conditional_t = typename conditional<B,T,F>::type;

template < typename Iterator>
class reverse_iterator;



template <typename T>
class Vector{
    T* arr;
    size_t sz;
public:

    template<bool IsConst>
    class common_iterator {
        std::conditional<IsConst, const T*,T*> ptr; // метафункция, описывает const T*,T* в зависимости от
        // от IsConst, который true или false

    public:
        friend Vector;

        explicit common_iterator(T* ptr): ptr(ptr){}
        T& operator*(){
            return *ptr;
        }
        // Для стрелочки возвращать сам С указатель
        T* operator->(){
            return ptr;
        }
        common_iterator& operator++(){
            ++ptr;
            return *this;
        }


    };

    using common_it = common_iterator<true>; //объявление ручного создание итератора
    using const_it = common_iterator<false>;


    template<bool IsConst>
    common_iterator<IsConst> begin() const{
        return common_iterator( std::conditional<IsConst, const T*,T*> (arr) );
    }

    template<bool IsConst>
    common_iterator<IsConst> end() const{
        return common_iterator(std::conditional<IsConst, const T*,T*> (arr+sz));
    }
//    using reverse_iterator = std::reverse_iterator<iterator>;
    template < typename Iterator>
    reverse_iterator<Iterator> rbegin() const{
        return reverse_iterator(arr+sz-1);
    }
    template < typename Iterator>
    reverse_iterator<Iterator> rend() const {
        return reverse_iterator(arr - 1);
    }
};

// Reverse iterator
// Если есть bidirectional операторы, то есть и reverse iterator
// делает наоборот для оператора
template < typename Iterator>
class reverse_iterator{
    Iterator iter;
    reverse_iterator(const Iterator& iter):iter(iter){}
    reverse_iterator<Iterator>&operator++(){
        --iter;
        return *this;
    }

    Iterator base() const{ //с помощью base можно вернуть обычный итератор
        return iter;
    }
};


int main(){
    std::list<int> lst = {1,2,3,4};

    std::vector<int> v;
    for (auto it = lst.rbegin(); it!=lst.rend();++it){ //последний элемент
        std::cout<<*it;
    }



//    если const std::list<int> lst = {1,2,3,4};, то lst.begin(); будет автоматически const common_iterator
//    std::list<int>::const_iterator iter = lst.cbegin();
//    *lst =2; --ошибка компиляции
}