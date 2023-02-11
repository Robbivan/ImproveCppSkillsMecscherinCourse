#include <iostream>
#include <vector>
// Исключения ловят в runtime
int f(int x, int y){
    if (y==0){
        throw 1;
    }
    return x/y;

}
// Не любая runtime ошибка является исключением

int main(){
//    try{ // try ловит только то, что брошено через throw
//        f(1,0);
//    }
//    catch(int x){ //шаблоны в catch нельзя catch(...)
//        std::cout<<"bad luck";
//    }
//    try{
//        std::vector<int> v(10); // не поймать, так как нет if, как в питоне или java
//        v[10000] =1;
//    }
//    catch (...){
//        std::cout<<"bad vector";
//    };




    // Кроме throw мб dynamic_cast, new, typeid
//    dynamic_cast<Mother&>(f); // Father& f
////    std::bad_cast;
//    int *p = new int[10000];
////    std::bad_allock

//    std::out_of_range; //для at у вектора
    try{
        std::vector<int> v(10); // не поймать, так как нет if, как в питоне или java
        v.at(10000) =1;
    }
    catch (...){
//        std::cout<<"bad vector";
    };

    try{
        std::vector<int> v(10); // не поймать, так как нет if, как в питоне или java
        throw std::out_of_range("message");
        v.at(10000) =1;
    }
    catch (std::exception& ex){
        std::cout<<ex.what();
    };

}
