#include <stdio.h>

class Time{
    friend class Date;
private:
    int hour, min, sec;
public:
    Time(int h, int m, int s) : hour(h), min(m), sec(s) { }
};

class Date{
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) { }
    void OutToday(Time &t) {
        printf("오늘은 %d년 %d월 %d일이며 현재 시간은 %d:%d:%d입니다.\n", year, month, day, t.hour, t.min, t.sec);
    }
};



int main(void){
    Date d(2025, 03, 20);
    Time t(11, 29, 46);

    d.OutToday(t);
    
    return 0;
}