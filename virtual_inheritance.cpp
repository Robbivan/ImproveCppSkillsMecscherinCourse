#include <iostream>
struct GrannyBv{
    int g = 0;
};

struct Motherv:public virtual GrannyB{
    int m=1;
};

struct Fatherv:public virtual GrannyB{
    int f=2;
};

struct Sonv:public Mother, public Father{
    int s = 3;
};

// без virtual   [g] [m] [g] [f] [s] 20 байт
// c virtual [m_ptr] [m] [f_ptr] [f] [s] [g]

int main(){
    Sonv s;
    // Если виртуальное наследование, то строго одно копия предка
    // GrannyBv& g =s; так не будет нормально кастоваться при virtual

    // Если сделать отца невиртуальным, а мать виртуальным, то
    // будет снова CE из-за Diamond problem

    // Если struct Sonv:public virtual Mother, public virtual Father{
    //    [s_prt] [s] [g] [m] [g] [f]
    //       |
    //      \|/
    //   m_ptr f_ptr
}