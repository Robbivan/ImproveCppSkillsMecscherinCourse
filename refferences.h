#include <iostream>

void f(int&){ }
void f(int){}

//void swap(int x, int y) // Не имеет смысла, так как мы локально только изменили
//{
//    int time_temp = x;
//    x = y;
//    y = time_temp;
//    std::cout<<x<<y<<'\n';
//}

//void swap(int* x, int* y) // Тоже не удобно с указателями, так как постоянно нужно следить, что это указатель или нет
//{
//    int time_temp = *x;
//    *x = *y;
//    *y = time_temp;
//    std::cout<<*x<<*y<<'\n';
//}
void swap(int& x, int& y)
{
    int time_temp = x;
    x = y;
    y = time_temp;
    std::cout<<x<<y<<'\n';
}

using std::cout;
void root(){
    cout<<"HELLO\n";
    int x = 2,y = 4;
    std::cout<<x<<y<<'\n';
    swap(x,y);
    std::cout<<x<<y<<'\n';
}

