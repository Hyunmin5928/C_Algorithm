#include <stdio.h>

void divide(int a, int d){
    if (d == 0) throw "0으로는 나눌 수 없습니다.";
    printf("나누기 결과 = %d입니다.\n", a / d);
}

int main(){
    try {
        divide(10, 0);                  // 0으로는 나눌 수 없습니다.
    }
    catch (const char *message){
        puts(message);                  // 예외 발생 시 동작
    }   
    divide(10, 5);                  // 나누기 결과 = 2입니다.
    return 0;
}