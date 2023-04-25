#include <iostream>
enum class TaxiClass:int32_t{ //до 11 стандарта просто enum
    ECONOM = 45678, // 0 по дефолту, но можно установить вручную, тогда все последующие +1
    COMFORT, // 1
    COMFORTPLUS, // 2
    BUSINESS // 3
};


int main(){
    TaxiClass c = TaxiClass::COMFORT;
}