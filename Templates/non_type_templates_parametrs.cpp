#include <iostream>
#include <array>
#include <vector>
template <int N>
struct S{

};
// int, long long,size_t
// char, bool

// Зачем это нужно
// массив фиксированного размера
template <typename T, size_t N>
struct array_d{

};

template <size_t M, size_t N, typename Field = int>
struct Matrix{

};

template <size_t M, size_t N,size_t K, typename Field = int>
Matrix<M,K,Field> operator*(const Matrix<M,N,Field>&,const Matrix<N,K,Field>&);

// Шаблонные параметры шаблонов
template<typename T, template<typename> class Container=std::vector>
class Stack{
    Container<T> c;
};

int main(){
//    S<int> s;
//    S<double>ss;
    S<5> s;
    std::array<int,5> arr;
    std::array<int,5> arr_2 = arr;
    // один массив присвоить другой можно через std::array
    // очень дешевый, но хранится на стеке, нету оптимизаций вектора (т.е. нет указателя на кучу, где релоц. данные)
    const int val = 5;
    std::array<int,val> arr_3;
    Stack<int> stack;






};
