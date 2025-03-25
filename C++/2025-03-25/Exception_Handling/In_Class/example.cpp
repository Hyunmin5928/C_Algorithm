#include <stdio.h>

class Int100 {
private:
    int num;
public:
    Int100(int a){
        if(a <= 100){
            num = a;
        }
        else{
            throw a;
        }
    }
    Int100 &operator+=(int b){
        if(num + b <= 100){
            num += b;
        }
        else{
            throw num + b;
        }
        return *this;
    }
    void OutVal(){
        printf("%d\n", num);
    }
};

int main(){
    try {
        Int100 i(85);
        i += 16;
        i.OutVal();
    }
    catch (int n){
        printf("%d(은)는 100보다 큰 정수 이므로 다룰 수 없습니다.\n", n);
    }

    return 0;
}