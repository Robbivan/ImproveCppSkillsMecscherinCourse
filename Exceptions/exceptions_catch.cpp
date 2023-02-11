#include <iostream>

// Правила ловли исключения
// 1 не действует приведение тмпов кроме наследника и родителя
// Выведет первую подходящую (как с перегрузкой не работает)
// То есть тут выведет 1

struct Noisy{
    Noisy(){
        std::cout<<"created";
    };
//    Noisy(){
//        std::cout<<"create";
//    }
    Noisy(const Noisy& copy){
        std::cout<<"copy";
    }
    ~Noisy(){
        std::cout<<"destroyed";
    }

};

void f(){
    Noisy x;
    throw x; //x будет скопирован, чтобы быть брошенным (то есть их будет 2)
}

void g(){
    try{
        throw std::out_of_range("message");
    }
    catch (std::exception& ex){ //если Noisy x, то будет 3 копии
        std::cout << "caught";
        throw; // так не будет создаваться копия и будет проброшено дальше
        // throw ex будет новая копия
    }
//    Java, Python
    /*finally{
     *  в любом случае
     *
     * }
     * */
}


int main(){

    try{
        g();
    }
    catch (std::exception &){

    }

    try{
        f();
    }
    catch (const Noisy& x){ //если Noisy x, то будет 3 копии
        std::cout << "caught";

    }




    try{
        throw std::out_of_range("message");
    }
    catch (std::exception& ex){
        std::cout<<1;
//        throw 1; не спасет, так как уже дальше в глубину catch не пойдет
    }
    catch(std::out_of_range& oor){
        std::cout<<2;
    }
    catch(...){
        std::cout<<3;
    }
}