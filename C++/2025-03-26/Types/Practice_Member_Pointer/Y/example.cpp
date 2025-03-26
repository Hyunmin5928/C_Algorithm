#include <stdio.h>

class Calc{
public:
    void Op1(int a, int b) { printf("%d\n", a + b); }
    void Op2(int a, int b) { printf("%d\n", a - b); }
    void Op3(int a, int b) { printf("%d\n", a * b); }
};

int main(){
    int ch;
    Calc c;
    int a = 3, b = 4;
    // 멤버 포인터 함수(배열로 선언) 
    // { } 구간은 초기화로 이해하면 됨.
    void (Calc::*arop[3])(int, int) = { &Calc::Op1, &Calc::Op2, &Calc::Op3 };

    printf("연산 방법을 선택하시오. 0->더하기, 1->뺴기, 2->곱하기 : ");
    scanf("%d", &ch);

    if (ch >= 0 && ch <= 2){
        (c.*arop[ch])(a, b);
    }
    else{
        printf("잘못 된 숫자를 입력하였습니다.\n");
    }

    return 0;
}