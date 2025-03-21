#include <stdio.h>

class Time
{
private:
    int hour, min, sec;
public:
    Time() { }
    Time(int h, int m, int s){ hour = h; min = m; sec = s; }
    void OutTime() const {
        printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
    }
    Time operator ++() {    // 전위형
        sec++;
        min += sec / 60;
        sec %= 60;
        hour += min / 60;
        min %= 60;
        hour %= 24;
        return *this;
    }  
    const Time operator ++(int dummy) {     // 후위형
        Time t = *this;
        ++*this;    // 전위형을 피연산자에만 적용
        return t;   // return 값은 그대로 출력
    }

};

int main(void){
    Time t1(12, 34, 56);
    Time t2;

    t2 = ++t1;
    t1.OutTime();   // 현재 시간은 12:34:57입니다.
    t2.OutTime();   // 현재 시간은 12:34:57입니다.

    t2 = t1++;
    t1.OutTime();   // 현재 시간은 12:34:58입니다.
    t2.OutTime();   // 현재 시간은 12:34:57입니다.

    return 0;
}