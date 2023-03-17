#include <iostream>
#include <cstring>
#include <algorithm>


// Правило 3 (по Маршаллу Клайна):
// Если класс имеет непустой деструктор, ему почти всегда нужен конструктор копирования и оператор присваивания.
// Если класс имеет нетривиальный конструктор копирования или оператор присваивания, ему обычно нужны оба этих члена, а также деструктор

// Правило 3 более общее
// Если вам нужно явно объявить деструктор, конструктор копирования или оператор присваивания
// копирования самостоятельно(т.е. нетривиальный), вам, вероятно, нужно явно объявить все три из них


// Правило 5 + добавилось про нетривиальный конструктор копирования перемещением и оператор присваивания перемещением

class String{
private:
    mutable size_t sz=0;
    char*str= nullptr;
public:

    String()=default;
    String(int n) = delete; // Запрет для int

    String(size_t string_size, char symbol = '\0'):str(new char(sz)), sz(string_size){
        memset(str,symbol,sz); // установка вместо for
    }
    /// move-конструктор
    // String(String&& s) noexcept :sz(s.sz),str(s.str)= default; //
    // Если вы реализовали свой нетривиальные конструктор копирования, то move constructor
    // не будет генерироваться, если явно не попросить (для оператора присваивания аналогично)
    String(String&& s) noexcept :sz(s.sz),str(s.str){
        s.str = nullptr;
        s.sz = 0;
    }
    // для сишного указателя будет работать некорректно
    // для shared_ptr все ок, так как есть конструктор копирования перемещением


    //



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
    String& operator=(const String& s){
        String copy = s;
        swap(copy);
        return *this;
    }
//    String& operator=(String&& s)=default; // умеет генерировать его сам

    /// assignment move operator
    String& operator=(String&& s){
        String new_s = std::move(s); // вызов move-constructor
        swap( new_s);
        return *this;
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
        //    Конструктор копирования
        String ss = s; //вот так будет shallow copy

    }
    String s{10,'a'}; //здесь выведет initializer_list

}

