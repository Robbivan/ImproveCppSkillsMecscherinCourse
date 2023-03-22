#include <iostream>


// Magic function std::move and its applications

// std::move позволяет создать rvalue ссылку на уже существующий объект (т.е. делает объект rvalue)
template<typename T>
void swap(const T& left, const T& right){
    T tmp = std::move(left);
    left = std::move(right);
    right = std::move(tmp);
}

// Move constructor в StringClassMove

int main(){
    std::string str = "abcdef";
    std::cout<<str.size()<<'\n'; // размер строки

    std::string str2 = std::move(str);
    std::cout<<str.size()<<'\n'; // плохое использование, поскольку уже был сделан move, соот. размер будет 0

    // std::move(ss);
    // f(getObject())
}
