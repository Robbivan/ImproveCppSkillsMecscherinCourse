#include <vector>

//size_t find(std::string text, std::string str){
//    // ... плохо, так как локальные копии
//    // если функция не собирается изменять объекты, то правильно принимать константные ссылки
//    return 0;
//}
size_t find(const std::string& text, const std::string& str){
    // ...
    //
    return 0;
}
void consts(){
    const int x =0;
    const std::vector<int> v = {1,2,3,4,5}; // сортировать тоже нельзя
    // для констант нельзя выполнять неконстантные операции
    // неконстантная присваивание для int: =, ++, --
    // const* int p = &x можно ++, но нельзя *p
    find("abcde","abc"); // можно от литералов (исключительно для константных ссылок)
    {
        //lifetime expansion
        const std::vector<int>& v ={1,2,3}; //Продление жизни ссылок, соот. объект не будет уничтожен
    }
    // не константые ссылки нельзя
    const int& mad=0;
}
