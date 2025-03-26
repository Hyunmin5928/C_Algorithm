#include <stdio.h>

namespace A{
    int value;
} 

namespace B{
    int value;
}

int main(){
    A::value = 12.345;
    B::value = 123;

    return 0;
}