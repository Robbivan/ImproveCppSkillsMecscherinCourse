#include <iostream>
#include "unordered_map"

/// type deduction (since C++11)

int&f (int& x){
    return x;
}

int main(){
//    std::unordered_map<std::string, int, std::hash<std::string>,std::equal_to<std::string>, FastAllocator<std::pair<const std::string, int>> map;
//    std::unordered_map<std::string, int, std::hash<std::string>,std::equal_to<std::string>,
//    FastAllocator<std::pair<const std::string, int>>::iterator it = m.begin();// боль

    std::unordered_map<std::string, int> map;
    // auto

    for (const std::pair<const std::string, int>& item:map ){

    }
    for (const auto& item:map ){

    }
    for (auto item:map ){ // тут будет копирование так как не по ссылке

    }

    for( const auto& [key, value] : map ){
        std::cout<<key<<value;
    }
//        print_key_value(key, value);
    int x = 1;
    auto& y = f(x);
    std::cout<<x<<' '<<y;


    // universal_ref
    auto &&yy = f(x);






}
