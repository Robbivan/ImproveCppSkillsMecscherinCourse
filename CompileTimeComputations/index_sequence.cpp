#include <iostream>

template<size_t...Ints>
struct index_sequence{

};

template<typename T, size_t N>
struct push_back{};


template <size_t N, size_t ...Ints>
struct push_back<index_sequence<Ints...>,N>{
    using type = index_sequence<Ints...,N>;
};

template<size_t N>
struct make_index_sequence_s{
    using type = typename push_back<typename make_index_sequence_s<N-1>::type,N-1>::type;
};

template<>
struct make_index_sequence_s<0>{
    using type = index_sequence<>;
};

template<size_t N>
using make_index_sequence = typename make_index_sequence_s<N>::type;



int main(){

    static_assert(std::is_same_v<make_index_sequence_s<3>, index_sequence<0,1,2>>);

}