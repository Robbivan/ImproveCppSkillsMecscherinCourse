#include <iostream>

// Magic function std::move and its applications

template<typename T>
void swap(const T& x, const T& y){
    T tmp = std::move(x);
    x = std::move(y);
    y = std::move(tmp);
}

// Move constructor and

int main(){
    std::string str = "abcdef";
    std::cout<<str.size()<<'\n';

    std::string str2 = std::move(str);
    std::cout<<str.size()<<'\n';
}
