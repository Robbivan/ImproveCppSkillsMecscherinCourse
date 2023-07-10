#include <iostream>
#include <string>


// Пример closure на С++
auto some_func(const std::string& message){
    return [message](const std::string& name){
        std::cout << message << " " << name<<std::endl;
    };
}




int main() {
    auto goodday = some_func("goodday");
    goodday("Elisa");


    auto bye= some_func("bye");
    bye("Alex");


    return 0;
}

