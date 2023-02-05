#include <iostream>
#include <vector>
using std::cout;

void f(int&){} // тут по ссылке
void f(int){} // а тут копия

// Функция демонстрации работы с ссылками
void vector_ref_work(){
    using std::vector;
    vector<int> v = {1,2,3,5,6};
    vector <int> vv = v; //дилемма (vv это другой вектор)?
    // в Java, Python, C# это будут ссылки
    // в Плюсах это КОПИЯ!
    // чтобы была ссылка
    vv[0]=0;
    vector <int> &vvv =v;
    vvv[0] =987;
    cout<<vv[0]<<" Новый контейнер\n";
    cout<<vvv[0]<<" Ссылка на v контейнер\n";
    cout<<v[0]<<" Тут не меняли, но из-за vvv получилось = 987\n";
    //  Сделано, чтобы
    // {
    //  Если бы vv был бы указателем, то в таком виде
    // }
    // После выхода из namespace не понятно, что делать с "оригинальной" памятью, поэтому в cpp
    // это сделано для эффективности
    // Пришлось бы смотреть сколько ссылок указывает на объект в режиме runtime (так как в compile time не получится
    // по теореме Успенского-Райса) это называется сборка муссора (Garbage collection)
    // В Java, Python, C# не детерминировано, когда будет происходить удаление
}

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


// Функция swap через ссылки
// Принимает аргументы:
// int& x - первый элемент
// int& y - второй элемент
void swap(int& x, int& y)
{
    int time_temp = x;
    x = y;
    y = time_temp;
    std::cout<<x<<y<<'\n';
}

using std::cout;
void ref_root(){
    cout<<"HELLO\n";
    int x = 2,y = 4;
    std::cout<<x<<y<<'\n';
    swap(x,y);
    std::cout<<x<<y<<'\n';
    vector_ref_work();
}

