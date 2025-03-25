#include <stdio.h>

template <typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}


int main(){
    int a = max(1, 2);
    double b = max(1.1, 2.2);

    printf("a = %d\nb = %f\n", a, b);
    /* 
    a = 2
    b = 2.200000
    */

    // 명시적 지정
    int c = max<double>(2, 3.14);
    printf("c = %d\n", c);          // c = 3

    return 0;
}