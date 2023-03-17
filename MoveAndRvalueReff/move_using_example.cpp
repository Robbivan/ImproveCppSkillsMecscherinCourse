#include <iostream>

// Magic function std::move and its applications

template<typename T>
void swap_bad(const T& left, const T& right){
    T tmp = std::move(left);
    left = std::move(right);
    right = std::move(tmp);
}

// Move constructor в StringClassMove

int main(){
    std::string str = "abcdef";
    std::cout<<str.size()<<'\n';

    std::string str2 = std::move(str);
    std::cout<<str.size()<<'\n';
}
