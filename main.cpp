#include "table.hpp"
int main(){
    size_t m = 0, n = 0;
    std::cin >> m >> n;
    int ** t=ct(m,n);
    
    std::cout << m << " " << n ;
    return 0;
    clean(t,m,n);
}