#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

// istream - пример input iterator, который не forward operator, так как не сможет пройти 2 раз по тому, что уже считано
template<typename T>
class istream_iterator{
    std::istream& in;
    T value;
public:
    istream_iterator(std::istream& in):in(in),value(0){
        // нужно чтобы уже что-то лежало под value
        // (условно первый символ)
    }

    // просто считывает следующий
    istream_iterator<T>& operator++(){
        in>>value;
    }
    T& operator*(){
        return value;
    }
};

// std::ifstream in("input.txt")

// из строки создавать поток
// std::istringstream iss(s)


int main(){

    std::ifstream file;
    std::ofstream file2;
    file.open("input.txt",std::istream::in);
    int numb;
    if (file){
        file>>numb;
    }

    std::vector<int> v;
    std::istream_iterator<int> it(std::cin);
    for (int i = 0;i<5;++i,++it){
        v.push_back(*it);
    }
//    for (int i = 0;i<5;++i,++i){
//        std::cout<<v[i];
//    }
    std::copy(v.begin(),v.end(), std::ostream_iterator<int>(std::cout, " "));
    // аналог вывода с копированием результата в ostream поток
//    std::ostream_iterator;
}
