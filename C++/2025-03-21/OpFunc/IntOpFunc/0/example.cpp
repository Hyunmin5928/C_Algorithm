#include <stdio.h>

class Time
{
private:
    int hour, min, sec;
public:
    Time() { }
    Time(int h, int m, int s){
        hour = h; min = m; sec = s;
    }
    void SetTime(int h, int m, int s) {
        hour = h; min = m; sec = s;
    }
    void OutTime() const {
        printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
    }
    const Time operator +(int s) const {
        Time t = *this;
        t.sec += s;
        
        t.min += t.sec / 60;
        t.sec %= 60;
        t.hour += t.min / 60;
        t.min %= 60;
        t.hour %= 24;
    
        return t;
    }
};

int main(void){
    Time now(11, 22, 33);
    Time now2(22,33,44);
    now.OutTime();   // 현재 시간은 11:22:33입니다.
    now = now + 1;
    now2 = now + 1;
    now.OutTime();   // 현재 시간은 11:22:34입니다.
    now2.OutTime();
    return 0;
}