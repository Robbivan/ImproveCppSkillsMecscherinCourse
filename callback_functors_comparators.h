#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

//функциональный класс, его объект функтор
// Callback
struct GreaterThanZero{
    bool operator()(int x){
        return x>0;
    }
};

struct Compare{
    bool operator()(int x,int y){
        return abs(x)<abs(y);
    }
};


void on_func(){
    std::vector<int>v{-1,2,6,3,4};

    std::find(v.begin(),v.end(),4); //впервые встречается 4
    std::find_if(v.begin(),v.end(),GreaterThanZero());
    std::sort(v.begin(),v.end(),Compare());

    std::set<int> s;
    std::set<int,Compare> ss; //Можно передать дополнительным параметром способ сортировки для set
    s.insert(4);

    for (int x:v){
        std::cout<<x;
    }
    // Существуют различные компараторы для sort
    // По умолчанию std::less
    // Может быть std::greater<int> (от большего к меньшему)



}