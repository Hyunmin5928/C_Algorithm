#include <stdio.h>
#include "cursor.h"
#include <new>

int main(){
    int *pi[1000] = { NULL, };
    int i;
    try {
        for (i = 0;; i++){
            pi[i] = new int[100000000];
            if (pi[i]) {
                printf("%d번째 할당 성공\n", i);
            }
            else {
                printf("%d번째 할당 실패\n", i);
            }
            delay(100);
        }
    }
    catch (std::bad_alloc &b){
        puts("에러 발생");
        b.what();
    
    }
    for(i = 0;; i++){
        delete[] pi[i];
    }

/*
    89번째 할당 성공
    90번째 할당 성공
    91번째 할당 성공
    92번째 할당 성공
    93번째 할당 성공
    94번째 할당 성공
    95번째 할당 성공
    96번째 할당 성공
    97번째 할당 성공
    98번째 할당 성공
    99번째 할당 성공
    에러 발생
*/

    return 0;
}