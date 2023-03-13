#include <iostream>
#include <vector>
// New/delete overloading, allocators

struct  S{
    int x = 3;
    double d =0.5;
    S(){}
    ~S(){};
    static void* operator new(size_t n){ // если n = 0, то все равно будет malloc от 1
        std::cout<< n <<"bytes allocated for struct S\n";
        void* p = malloc(n); // сишная функция выделение памяти
        if(!p){
            throw std::bad_alloc(); // стандартная реализация в библиотеке вызывает еще new handler,
            // где можно как-то обработать помимо просто бросания исключения
        }
        return p;
    }
    static void operator delete(void *p){
        std::cout<<"S deallocated\n";
        free(p); // сишная функция освобождения
    }
};

void* operator new(size_t n){ // если n = 0, то все равно будет malloc от 1
    std::cout<< n <<"bytes allocated\n";
    void* p = malloc(n); // сишная функция выделение памяти
    if(!p){
        throw std::bad_alloc(); // стандартная реализация в библиотеке вызывает еще new handler,
        // где можно как-то обработать помимо просто бросания исключения
    }
    return p;
}

void operator delete(void *p){
    std::cout<<"deallocated\n";
    free(p); // сишная функция освобождения
}


void* operator new[](size_t n){
    std::cout<< "Array of "<< n <<"bytes allocated\n";
    void *p = malloc(n);
    if(!p) throw std::bad_alloc();
    return p;
}

void operator delete[](void *p){
    std::cout<<"Array deallocated\n";
    free(p); // сишная функция освобождения
}
// ------------------------------------------------------------------

// Перегрузка placement new
void*operator new(size_t, S*p){
    return p;
}
// placement delete не существует



// Перегрузка new для своей реализации, теперь все что имеет MyStruct будет использовать данный new
// остальные стандартный new
struct MyStruct{};
MyStruct mys;

void* operator new(size_t n, MyStruct){
    std::cout<<"Custom operator new called\n";
    return malloc(n);
}
void operator delete (void *p, MyStruct){
    std::cout<<"Custom operator delete called\n";
    free(p);
}



int main(){
    S *p = new S(); // помимо выделения памяти в отличие от malloc он еще отправляет каждый конструктор
    // в выделенные ячейки.
    // То есть 2 этапа:
    // 1. Выделение памяти
    // 2. Вызов конструктора
    // действие new можно перегрузить, но только для 1 пункта
    delete p;

    // Для удаление тоже 2 этапа:
    // 1. Сначала вызывает деструктор
    // 2. Затем освобождает память

    S *pp = new S[10];
    delete[] pp;

    std::vector<int> v(10); // теперь и в контейнерах тоже через переопределение new
    v[3] = 5;
    v[5] = 7;


    // placement new
    new(p) S();

    S* tp = new (mys) S();
    // к сожалению, вручную для удаления
    operator delete(p,mys);
    tp->~S();
}
