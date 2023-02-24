#include <iostream>
#include <list>


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

};




int main(){
    std::list<int> lst = {1,2,3,4};
    int *y;
    int*x = y;
    int *z;

//    если const std::list<int> lst = {1,2,3,4};, то lst.begin(); будет автоматически const common_iterator
    std::list<int>::const_iterator iter = lst.cbegin();
//    *lst =2; --ошибка компиляции
}