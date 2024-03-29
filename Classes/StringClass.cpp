#include <iostream>
#include <cstring>
#include <algorithm>

class String{
private:
    mutable size_t sz=0;
    char*str= nullptr;
public:
//    String(){} //Конструктор по умолчанию, не очень хорошо с 11 версии
    // лучше так:
    String()=default;
    String(int n) = delete; // Запрет для int

    String(size_t string_size, char symbol = '\0'):str(new char(sz)), sz(string_size){
//        sz = string_size; чтобы не присваивать в конструкторе нужно инициализировать до
//        str = new char[sz];
        memset(str,symbol,sz); // установка вместо for
    }
    //
    //    конструктор копирования с правильной сигнатурой
//    String (const String &s){
//        sz = s.sz;
//        str = new char[sz];
//        memcpy(str,s.str,sz); //копирование вместо for
//
//    }
    // Предыдущий конструктор можно создать с помощью делегирующего конструктора, начиная с с++11
    String (const String &s): String(s.sz,'\0'){
        //Это предыдущий с new + добавление от текущего
        memcpy(str,s.str,sz);
    }

    // Для str = {'a','b','c'}
    String(std::initializer_list<char> lst){
        sz = lst.size();
        str = new char[sz];
        std::copy(lst.begin(),lst.end(),str);
    }

    // Оператор присваивания
    //    String& operator=(const String& s){
    //        delete[] str;
    //        sz = s.sz;
    //        str = new char[sz];
    //        std::copy(s.str, s.str+sz,str);
    //    }

    //   String& operator=(const String& s){ // Можно упростить через swap_bad and copy
    //        delete[] str;
    //        sz = s.sz;
    //        std::copy(s.str, s.str+sz,str);
    //    }
    String& operator=(String s){
        swap(s);
        return (*this);
    }
    void swap(String& s){
        std::swap(sz,s.sz);
        std::swap(str,s.str);
    };
    size_t get_size() const{
        return sz;
    }
    const char& operator[](size_t index) const{ // перегрузка операторов индексации для const
        return str[index];
    }
    char& operator[](size_t index){ // перегрузка операторов индексации
        return str[index];
    }
    ~String();
//    ~String(){
//        delete[] str;
//    }
};
String::~String(){
    delete[] str;
};

std::ostream& operator<<(std::ostream& out, const String& s){ //Поток не константный
    for (size_t i= 0;i<s.get_size();++i){
        out<<s[i];
    }
    return out;
}

int main(){
//    String(10,'a');
//    String(10);
    {
        String s(10,'a'); // Равносильно   String s = String(10)
        std::cout << s;
        //    Конструктор копирования
        String ss = s; //вот так будет shallow copy

    }
    String s{10,'a'}; //здесь выведет initializer_list
    std::cout << s;

}
