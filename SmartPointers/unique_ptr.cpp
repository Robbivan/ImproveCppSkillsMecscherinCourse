#include <iostream>
#include <memory>
#include <vector>
/// умные указатели позволяют освобождать автоматически динамически
/// выделенный ресурс

/// позволяют делать move


void f_f(){
    std::unique_ptr<int> p(new int(5));
    // unique_ptr скопировать нельзя, не ведет подсчет ссылок
    // auto pp = p; // Нельзя, CE
    // создавать 2 указателя unique_ptr на одно и тоже = утечка

    std::unique_ptr<int[]>p_array(new int[5]); // unique указатель на массив

    // аналогично и с shared_ptr, можно присвоить это ок, так как подсчет ссылок будет в одном месте,
    // но 2 разных подсчета на двух разных shared_ptr = утечка



    std::vector<std::unique_ptr<int>> v;
    for (int i = 0;i < 10; ++i){
        v.emplace_back(new int(i)); // все хорошо, так как move(forward) разрешен
    }

    // должен уметь разыименововаться
    for (size_t i = 0; i < 10; ++i){
        std::cout<<*v[i];
    }
    for (size_t i = 0; i < 10; ++i){
        std::cout<<++*v[i];// можно вывести то, что рядом через unique_ptr
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
