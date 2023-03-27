#include <iostream>

class Base{
public:

    virtual void f() = 0;
public:
    int a;
protected:
    explicit Base(const int& in_a):a(in_a){}
};

class Derived:public Base{
public:
    explicit Derived(const int& in_a):Base(in_a){
        // обычный init_list нельзя, так как порядок иначе не будет при инициализации

        /// Из стандарта
        /*
         * In a non-delegating constructor, initialization proceeds in the following order:

        — First, and only for the constructor of the most derived class (1.8), virtual base classes are initialized
         in the order
         they appear on a depth-first left-to-right traversal of the directed acyclic graph
         of base classes, where “left-to-right” is the order of appearance of the base classes in
         the derived class base-specifier-list.

        — Then, direct base classes are initialized in declaration order as they appear in the base-specifier-list
         (regardless of the order of the mem-initializers).

        — Then, non-static data members are initialized in the order they were declared in the class definition
         (again regardless of the order of the mem-initializers).

        — Finally, the compound-statement of the constructor body is executed.

        [ Note: The declaration order is mandated to ensure that base and member
         subobjects are destroyed in the reverse order of initialization. — end note ]
         * */
    }
    void f()override;


};

void Derived::f() {
    std::cout<<a;
}


int main() {
    Derived d(1);
    Base& b = d;
    b.f();

    return 0;
}
