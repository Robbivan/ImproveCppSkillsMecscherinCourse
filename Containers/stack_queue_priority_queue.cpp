#include <iostream>
#include <stack>
#include <queue>


/// Адаптеры над контейнерами

// Stack - обертка над контейнером с 3 методами push, top, pop (size, empty берутся из контейнера)
// Queue - обертка над контейнером с 3 методами push, front, pop, (back, size, empty берутся из контейнера)
// Priority queue -  обертка над контейнером std::deque
// итераторов нет для оберток
template<typename T, typename Container = std::deque<T> >
class Stack{
public:
    void push(const T& value){
        container.push_back(value);
    }

    void pop(){
        container.pop_back();
    }

    T& top(){
        return container.back();
    }

private:
    Container container;

};


int main(){
    std::stack<int> st;
    std::queue<int> que;


}
