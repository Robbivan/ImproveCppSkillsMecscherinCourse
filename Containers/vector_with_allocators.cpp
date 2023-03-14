#include <iostream>
#include <vector>

// Реализация класса вектор
template<typename T,typename Alloc=std::allocator<T>>
class Vector{
    T* arr;
    size_t sz;
    size_t cap; //для reserve
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;
public:
    Vector(size_t n, const T& element=T(), const Alloc& alloc = Alloc()){}

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
        if(n < cap){
            reserve(cap);
        }
    }

    size_t size() const{
        return sz;
    }

    size_t capacity() const{
        return cap;
    }

    void reserve(size_t n){
        if(n < cap){
            return;
        }
        if (n==cap){
            //
        }
        //T* newarr = new T[n];
        // T* newarr = reinterpret_cast<T*>(new int8_t *[n*sizeof(T)]);
        //T* newarr=alloc.allocate(n);
        T* newarr = AllocTraits::allocate(alloc, n);

        // В стандартной библиотеке это
//        try{
//            std::uninitialized_copy(arr,arr+sz, newarr);
//        }
//        catch (...){
//            // delete reinterpret_cast<int8_t*>(newarr);
//            AllocTraits::deallocate(newarr,n);
//            throw;
//        }
        size_t i = 0;
        try{
            for (; i < sz; ++i){
                AllocTraits::construct(alloc, newarr+i,arr[i]);
                // new(newarr+i) T(arr[i]);
            }
        }
        catch (...){
            for (size_t j = 0;j < i; ++j){
                AllocTraits::destroy(alloc,newarr+j);
                //(newarr+j)->~T();
            }
            AllocTraits::deallocate(newarr,n);
//            delete reinterpret_cast<int8_t*>(newarr);
            throw;
        }

        for (size_t i = 0; i < sz; ++i){
            AllocTraits::destroy(alloc,arr+i);;
        }
        AllocTraits::deallocate(arr,n);
        //delete reinterpret_cast<int8_t*>(arr);
        arr = newarr;
    }

    void push_back(const T& value){
        if (sz ==cap){
            reserve(2*cap);
        }
        AllocTraits::construct(alloc,arr+sz, value);

        // new(arr+sz) T(value);
        ++sz;
    }

    void pop_back(){
        // контейнер не проверяет от пустого вектора
        AllocTraits::destroy(alloc,arr+sz-1);
        //   (arr+sz-1)->~T();
        --sz;
    }

};





//////////////////////////////////////////////////////////////////////////////////////
//// Vector <bool>
//// bool - это 1 байт,
//// а можно сделать, чтобы в vector это был 1 бит, то есть хранить по 8 бит bool равных 1 байту
//template <>
//class Vector<bool>{
//    int8_t* arr;
//    size_t sz;
//    size_t cap;
//    struct BitReference{
//        int8_t *cell;
//        uint8_t num;
////        BitReference(int8_t *cell,const uint8_t num):cell(cell), num(num){}
//        BitReference& operator=(bool b){
//            if(b){
//                *cell |=(1u<<num);
//            }else{
//                *cell &=~(1u<<num);
//            }
//            return *this;
//        }
//    };
//public:
//    BitReference operator[](size_t i){
//        return BitReference{arr+i/8,static_cast<uint8_t>(i%8)};
////        about init list initialization
////        https://stackoverflow.com/questions/21150067/initialization-difference-with-or-without-curly-braces-in-c
//    }
//
//};

template <typename U>
void f(const U&) = delete;





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

    std::vector<bool> vb(10,false);
    vb[5] = true;


}
