#include <iostream>
// references qualifiers

struct SS{
    void f() const // если объект const, то попадет сюда
    { //
        std::cout<<1;
    }
    void f() // если объект не const, то попадет сюда
    {

    }
};

// аналогично для lvalue and rvalue
struct S{

    S& operator = (const S& s) & { // нельзя присваивать rvalue
        date = s.date;
    }
    std::string f() const & // если не ставить, то будет годится для всех
    {
        return date;
    }
    std::string f() && {
        return std::move(date);
    }
private:
    std::string date;
};

int main(){
    S s;
    s.f();

    std::move(s).f();
    S().f(); // S() - rvalue

    // для big integer
    // a + b = 5; надо запретить
}


