#include <iostream>
#include <map>
#include <unordered_map>
#include <tuple>




int main(){

    std::pair<int, std::string> p{5,"abc"};

    // since C++17 pair
    auto [a,b] = p;
    std::cout << a << b << '\n';

    std::map<int, std::string> map;
    map[7] = "abc";
    for (auto& [key, value]:map){
        std::cout << key << value << '\n';
    }
    std::unordered_map<int,std::string> map1;
    map1[4] = "a";
    for (auto& [key, value]:map1){
        std::cout << key << value << '\n';
    }
    // since C++11
    /// tuple
    std::tuple <int, double, std::string> t{1,2.0,"abc"};

    auto& [aa,bb,cc] = t;
    // в tuple можно получить i элемент через функцию get
    auto x = std::get<1>(t); // нумерация с 0
    auto xx = std::get<double>(t); // можно по типу вывести
}