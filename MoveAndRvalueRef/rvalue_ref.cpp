#include <iostream>

/// чем можно и нельзя инициализировать rvalue ссылки

// move_if_noexcept в vector_allocators_move

int main(){
    int x = 0;
    int& rx = x;
    // int& rx = 1;// так нельзя, так как неконстантную ссылку нельзя проинициализировать rvalue
    // (т.е. в данном случае числом)
    const int& crx = 2;

    // int&& rrx = x; // ошибка, т.к. rvalue ref можно проинициализировать только rvalue
    int&& rrx = 0;
    rrx = x; // нет проблем, так как тут уже не ссылка, а просто память под переменной
    int& drx = rrx;

    // std::move позволяет создать rvalue ссылку на уже существующий объект (т.е. делает объект rvalue)
    int&& rrx2 = std::move(rx); // по идее до С++20, там уже можно не писать

}
