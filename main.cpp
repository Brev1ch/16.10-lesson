#include "table.hpp"
int main(){
    size_t m = 0, n = 0;
    std::cin >> m >> n;
    if (std::cin.fail()){
        std::cerr << "Input error!\n";
    }
    try{
        int ** t=ct(m,n);
    } catch(const std::exception &e){
        std::cerr << "FAIL!\n"
        return 1;
    }
    out(t);
    clean(t,m,n);
}