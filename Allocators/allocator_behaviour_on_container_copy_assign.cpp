#include <iostream>
#include <vector>

struct PoolAlloc{
    //...
};



int main(){
    // определение копировать/не копировать аллокатор
    // у аллокатор_traits::select_on_container_copy_construction
    // по умолчанию копия,
    // но можно сделать и новый аллокатор
    std::vector<int, PoolAlloc> v1;
    std::vector<int, PoolAlloc> v2 = v1;
    // propagate_on_container_copy_assignment - нужно ли заниматься присваиванием аллокатора,
    // когда контейнер присваивается или нет
    // по умолчанию false_type (внутри const Bool& value = false)

    // Реализация copy assignment для двух векторов в vector

}
