#include <iostream>
#include <algorithm>
#include <vector>

class Complex{
private:
    double im = 0.0;
    double re = 0.0;
public:
    Complex(double a= 0.0, double b=0.0):im(a),re(b){}
    // В начале лучше определить через +=
    Complex& operator+=(const Complex& z){
        re +=z.re;
        im +=z.im;
        return *this;
    }
    Complex operator+(const Complex& z){ //тут не будет работать обратное сложение 1.0 + С, так как неявно double тут
        // не приведет, поэтому opetrator можно вынести, и сделать общим для всех
        Complex copy =*this;
        copy+=z;
        return copy;
    }
    Complex& operator++(){ //Префиксный инкремент
        *this +=1;
        return *this;
    }
//    Complex& operator++(int){ //Костыль Страуструпа, тут еще очень хорошо видно, что возвращается именно копия не увел на 1
//        Complex copy = *this;
//        ++*this;
//        return copy;
//    }
//    bool operator<(const Complex& a,const Complex& b){
//        return a.re*a.re<b.re*b.re;
//    }
//    bool operator>(const Complex& a,const Complex& b){
//        return b<a;
//    }
};

Complex operator+(const Complex& a,const Complex& b){
    Complex copy =a;
    copy+=b; // Оптимизация return vaule optimization (RVO)
    return copy;
}

//функциональный класс, его объект функтор
// Callback
struct GreaterThanZero{
    bool operator()(int x){
        return x>0;
    }
};

void on_operator() {
    Complex c(2.0);
    Complex d(3.0,1.0);
    1.0 + c;
    Complex sum = c + d; // А тут нет копии, так как оптимизация copy elision C++11-17

    std::vector<int>v{1,2,6,3,4};

    std::find(v.begin(),v.end(),4); //впервые встречается 4
    std::find_if(v.begin(),v.end(),GreaterThanZero());

}


