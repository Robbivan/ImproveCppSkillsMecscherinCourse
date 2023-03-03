#include <iostream>
#include <vector>

// Реализация класса вектор
template<typename T>
class Vector{
    T* arr;
    size_t sz;
    size_t cap; //для reserve
public:
    Vector(size_t n, const T& element=T()){}

    T& operator[](size_t i){
        return arr[i];
    }
    const T& operator[](size_t i) const{
        return arr[i];
    }
    T& at(size_t i){
        if(i>=sz){
            throw std::out_of_range("...");
        }
        return arr[i];
    }
    const T& at(size_t i) const {
        if(i>=sz){
            throw std::out_of_range("...");
        }
        return arr[i];
    }

    const T& some_method(int i){
        return arr[i];
    }

    void resize(size_t n, const T& value = T()){

    }
    size_t size() const{
        return sz;
    }
    size_t capacity() const{
        return cap;
    }
    void reserve(size_t n){
        if(n <= cap){
            return;
        }
        T* newarr = reinterpret_cast<T*>(new int8_t *[n*sizeof(T)]);
        for (size_t i = 0; i < sz; ++i){
            new(newarr+i) T(arr[i]); //вызов конструктора по new, так как еще нет конкретных обхектов
        }
        for (size_t i = 0; i < sz; ++i){
            (arr+i)->~T();
        }
        delete reinterpret_cast<int8_t*>(newarr);
    }
    void push_back(const T& value){
        if (sz ==cap){
            reserve(2*cap);
        }
        new(arr+sz) T(value);
        ++sz;
    }

    void pop_back(){
        // контейнер не проверяет от пустого вектора
        for (size_t i = 0; i < sz;++i){
            (arr+i)->~T();
        }
        --sz;
    }

};

int main(){
    std::vector<int> v;
    for (int i = 0 ;i < 25;++i){
        v.push_back(i);
        std::cout<<v.size()<<' '<<v.capacity();
        // capacity увеличиваются по степени 2, при этом если делать

    }
    for (int i = 0 ;i < 25;++i){
        v.pop_back(); // pop_back в целях экономии времени capacity не изменяется
        // чтобы уменьшать capacity нужно делать  v.shrink_to_fit(); ( C++11)
        std::cout<<v.size()<<' '<<v.capacity();

    }
    v.clear(); // убирает все элементы из вектора, но capacity остается


}