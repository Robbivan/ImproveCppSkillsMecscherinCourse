#include <iostream>
#include <vector>

// RVO (return value optimization)
std::vector<int> f(int n){
    return std::vector<int>(n, 1); // return value optimization
}




struct S{
    int x_;
    S(int x):x_(x){};
    S(const S&){
        std::cout<<1;
    };
    S(S&&){
        std::cout << 2;
    }

};
S&& ff(int n){
    // это уже xvalue и copy elision не сработает
    // Temporary materializatio
}

// NRVO
struct BigInteger{

};
// тут тоже сможет быть copy elision
BigInteger operator+(const BigInteger& a, const BigInteger& b){
    BigInteger copy = a;
    copy+=b;
    return copy;
}


// так не получится copy elision, но в return все равно move
// BigInteger operator+(BigInteger a, const BigInteger& b){
//    a+=b;
//    return a;
//}

int main() {
    // Сколько раз будет вызван конструктор вектора, так как std::move неявно, то copy elision
    std::vector<int> v = std::vector<int>(10, 1);
    std::vector<int> v2 = f(10); // тоже сработает copy elision

    // работает за счет prvalue
    // S s = S(S(S(5)));
    // тут будет 0 копирований

    S s = ff(10);


    // материализация временного
    int check = ff(10).x_; // xvalue
}