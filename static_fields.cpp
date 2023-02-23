#include <iostream>

//Статическое поле общее для всего класса
struct ex{
    static int val;
};
int ex::val =1; //чтобы к нему обратиться не нужно иметь объект класса
// аналогично со статическими методам

int main(){
    using std::cout;
    cout<<ex::val;
}
