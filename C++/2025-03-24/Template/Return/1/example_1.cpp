#include <stdio.h>

template <typename T>
T cast(int s){
    return (T)s;
}


int main(){
    unsigned u = cast<unsigned>(1234);
    double d = cast<double>(5678);

    printf("a = %d, b = %f\n", u, d);       // a = 1234, b = 5678.000000

    return 0;
}