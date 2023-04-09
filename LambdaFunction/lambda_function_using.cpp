#include <iostream>
#include <vector>
#include <algorithm>

/// lambda functions and elements of functional programming
// since C++11

// Старый способ C++03
//struct Comparator{
//    bool operator()(int x, int y) const{
//        return std::abs(x)<std::abs(y);
//    }
//};

auto getCompare(){
    return [](int x, int y)->bool{ // явно указали
        if(x==y){
            return true;
        }
        else{
            return 12;
        }
    };
}

int main(){



    std::vector<int>v{1,6,3,4};
    // Старый способ C++03
    // std::sort(v.begin(),v.end(), Comparator());
    auto t_f = [](int x, int y){return std::abs(x) < std::abs(y);};
    std::sort(v.begin(),v.end(),[](int x, int y){return std::abs(x)<std::abs(y);});

    std::sort(v.begin(), v.end(), t_f);
    for (const auto& item:v){
        std::cout<<item<<' ';
    }



    // сразу вызов лямбда функции
    [](int x){
        std::cout<<x;
    }(5);

    //ыы
    [](){}();


    /// грязный хак
    // чтобы инициализировать в конструкторе до самого тела конструктора, можно вызвать лямбда функцию в ()


}
