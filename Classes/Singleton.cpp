#include <iostream>
class Singleton{
    static Singleton *obj; // выносим за пределы класса инициализацию
    Singleton() = default;
public:
    // Метод (статический) класса Singleton по ссылке
    // return:
    // *obj = &  - ссылку на объект
    static Singleton& GetObject(){
        if(obj) return *obj; //если уже существует, то возвращает то, что существует
        obj = new Singleton();
        return *obj;
    }
    static void destroy(){
        delete obj;
    }
};

Singleton* Singleton::obj = nullptr;

int main(){
    Singleton s = Singleton::GetObject();
    Singleton::destroy();

}