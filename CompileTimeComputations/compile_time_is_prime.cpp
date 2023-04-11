#include <iostream>

/// есть массив в compile: integer sequence

template<size_t N, size_t D>
struct IsPrimeHelper{
    static const bool value = N % D != 0 && IsPrimeHelper<N, D - 1>::value;

};

template<size_t N>
struct IsPrimeHelper<N,1>{
    static const bool value = true;
};

template<size_t N>
struct IsPrime{
    static const bool value = IsPrimeHelper<N,N-1>::value;
};

template<>
struct IsPrime<1>{
    static const bool value = false;
};

int main(){
    std::cout<<IsPrime<37>::value;

}
