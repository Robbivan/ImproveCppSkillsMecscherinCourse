struct Bad_example{
private:
    int x =0;
    std::string s;
    double d = 0.0;
public:
    void print(int& a){
        std::cout<<x+a;
    }
    void print(double& a){
        std::cout<<x+a+1;
    }
};

class C_ex{
private:
    int x =0;
    std::string s;
    double d = 0.0;
    void bit(int& a);
public:
    double print(double& a){
        return x+a+1;
    }
};

//Пример метода вне класса
void C_ex::bit(int &x) {
    //Запрет вызова от int
    std::cout<<this->x+x;
}





