template <typename T>
const T& maximum(const T& a, const T& b){
    return a>b?a:b;
}

void on_template_intro(){
    maximum(1,2);
    maximum<int>(1,2.0); //Приведение к общему int
}