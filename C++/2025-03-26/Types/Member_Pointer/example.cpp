#include <stdio.h>

class Time{
public:
    int hour, min, sec;
    void OutTime(){
        printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
    }
};

int main(){
    Time now;
    int Time::*pi;          // Time 클래스의 int에 접근

    pi = &Time::hour;       // hour 접근 가능
    now.*pi = 12;
    pi = &Time::min;        // min 접근 가능
    now.*pi = 34;
    pi = &Time::sec;        // sec 접근 가능
    now.*pi = 56;
    now.OutTime();
    // 현재 시간은 12:34:56입니다.

    return 0;
}