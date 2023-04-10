#include <iostream>
#include <vector>

//std::is_same_v
/// SFINAE
// Substitution Failure Is NoT An Error!


// Частное лучше общего
template<typename T>
auto f(const T&)-> decltype(T().size()){ // у int нет метода size, но это не ошибка,
    // если не получилось, то ищет лучший вариант кроме этой
    // T x;
    // x.size() - ошибка, так как не будет ошибкой только в сигнатуре

    std::cout<<1;
    return 0;
}

int f(...){
    std::cout<<2;
    return 0;
}


int main(){

    std::vector<int>v{1,2,3};
    f(v);
    f(5); // это не ошибка, а SFINAE

}
