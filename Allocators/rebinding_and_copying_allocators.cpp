#include <iostream>

template <typename T, typename Alloc = std::allocator<T>>
class List_bad{
    // проблема в том, что нужно выделять память от типа Node, а не List<int> !int!
    struct Node{

    };
    std::allocator_traits<Alloc>::template rebind_alloc<Node> alloc;
public:
    List_bad(const Alloc& alloc = Alloc()):alloc(alloc);
};
 // rebind - позволяет заменять аллокатор одного типа на другой в составном классе


// Если аллокаторы равны, то можно выделить что-то на одном ресурсе и освободить через другой ресурк
// alloc1 == alloc2
// T* ptr = alloc1.allocate(1);
// alloc2.deallocate(ptr, 1);
// в данном случае аллокаторы ведут себя как указатели
// чтобы нормально решать проблему делегации по аллокаторам используются shared_prt
// Shared_ptr хранит кол-во ссылок на данную память, (чтобы не было проблемы двойного delete)
// и когда остается 1 ссылка, то вызывает destroygit

int main(){

}
