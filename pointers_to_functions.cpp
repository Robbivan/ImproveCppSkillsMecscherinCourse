#include <iostream>

// указатели на функции
int foo()
{
    return 5;
}

int foo2(int x){
    return x;
}

int goo()
{
    return 6;
}

int main()
{
    int (*fcnPtr)(){ &foo }; // fcnPtr указывает на функцию foo
    fcnPtr = &goo;    // fcnPtr теперь указывает на функцию goo


    int(*foo2_point)(int){&foo2};
    (*foo2_point)(5);

    return 0;
}
