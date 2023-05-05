#include <iostream>
#include <variant> // since C++17

template<typename ...Types>
union VariadicUnion{

};

template<typename Head, typename ...Tail>
union VariadicUnion<Head,Tail...>{
    Head head;
    VariadicUnion<Tail...>tail;

};

template<typename ... Types>
class Variant{
private:
    VariadicUnion<Types...> storage;
    size_t index = 0;

};

template<size_t N, typename... Types>
auto& get(Variant<Types...>& v){
    if(v.index == N){
        return v.storage.get<N>();
    }
    throw std::bad_variant_access();

}

int main(){
    std::variant<int, double, std::string> v;
    v = 1;
    v = "avc";
    std::cout<<std::get<std::string>(v);

    std::cout<<std::holds_alternative<int>(v);//true или false в зависимости от типа, здесь v - string, поэтому false

}
