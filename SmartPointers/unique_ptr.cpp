#include <iostream>
#include <memory>
#include <vector>
// умные указатели позволяют освобождать автоматически динамически
// выделенный ресурс


void f_f(){
    std::unique_ptr<int> p(new int(5));
    // unique_ptr скопировать нельзя, не ведет подсчет ссылок
    // auto pp = p; // Нельзя, CE
    // создавать 2 указателя unique_ptr на одно и тоже = утечка

    // аналогично и с shared_ptr, можно присвоить это ок, так как подсчет ссылок будет в одном месте,
    // но 2 разных подсчета на двух разных shared_ptr = утечка

    std::vector<std::unique_ptr<int>> v;
    for (int i = 0;i < 10; ++i){
        v.emplace_back(new int(i)); // все хорошо, так как move(forward) разрешен
    }
    for (size_t i = 0; i < 10; ++i){
        std::cout<<*v[i];
    }
}


void f(){
    std::shared_ptr<int> p(new int(5));
    auto pp = p;
}


int main(){
    auto some_val = new int(5);
    std::cout<<*some_val;
}
