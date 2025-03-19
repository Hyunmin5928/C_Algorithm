#include <stdio.h>
#include <string.h>
//캡슐화
class Time{
private:
    int hour, min, sec;
public:
    Time(int h, int m, int s){
        hour = h;
        min = m;
        sec = s;
    }
    Time(int abssec){
        hour = abssec / 3600;
        min = (abssec / 60) % 60;
        sec = abssec % 60;
    }
    void OutTime(){
        printf("현재 시간은 %d:%d:%d입니다 \n", hour, min, sec);
    }
};


int main(void){
    Time time1(12, 23, 34);
    time1.OutTime();

    Time time2(44000);
    time2.OutTime();

    return 0;
}