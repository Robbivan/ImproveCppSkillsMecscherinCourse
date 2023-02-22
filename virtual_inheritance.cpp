#include <iostream>
struct GrannyB{
    int g = 0;
};

struct Mother:public virtual GrannyB{
    int f=1;
};

struct Father:public virtual GrannyB{
    int f=2;
};

struct Sonv:public Mother, public Father{
    int k = 3;
};

// без virtual   [g] [m] [g] [f] [s] 20 байт
// c virtual [m_ptr] [m] [f_ptr] [f] [s] [g]

int main(){
    Sonv s;
    s.Father::f;
    // поле g содержится дважды без virtual
    // Если виртуальное наследование, то строго одно копия предка Бабушки
    // у сына теперь одна копия бабушки

    // GrannyBv& g =s; так не будет нормально кастоваться при virtual

    // Если сделать отца невиртуальным, а мать виртуальным, то
    // будет снова CE из-за Diamond problem

    // Если struct Sonv:public virtual Mother, public virtual Father{
    //    [s_prt] [s] [g] [m] [g] [f]
    //       |
    //      \|/
    //   m_ptr f_ptr
}