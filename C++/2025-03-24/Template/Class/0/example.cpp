#include <stdio.h>
#include <malloc.h>
#include <memory.h>

template <class T>
void swaparray(T *a, T *b, int num){
    void *t;
    t = malloc(num * sizeof(T));
    memcpy(t, a, num * sizeof(T));
    memcpy(a, b, num * sizeof(T));
    memcpy(b, t, num * sizeof(T));
    free(t);
}


int main(){
    int a[] = { 1, 2, 3 }, b[] = { 4, 5, 6 };
    char c[] = "문자열", d[] = "string";

    swaparray(a, b, sizeof(a) / sizeof(a[0]));
    for(int i = 0; i < (sizeof(a)/sizeof(a[0])); i++){
        printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
    }

    printf("before c = %s, d = %s\n", c, d);
    swaparray(c, d, sizeof(c) / sizeof(c[0]));
    printf("after c = %s, d = %s\n", c, d);
    
    /*
    a[0] = 4, b[0] = 1
    a[1] = 5, b[1] = 2
    a[2] = 6, b[2] = 3
    before c = 문자열, d = string
    after c = , d = 문자열
    */

    return 0;
}