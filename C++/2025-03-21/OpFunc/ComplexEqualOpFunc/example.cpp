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
    const Time operator +=(int s) {  
        sec += s;
        
        min += sec / 60;
        sec %= 60;
        hour += min / 60;
        min %= 60;
        hour %= 24;
        return *this;
    }
    const Time operator+(int s) const {
        Time t = *this;
        t += s;
        return t;
    }
};

int main(void){
    Time now(11, 22, 33);
    now.OutTime();          // 현재 시간은 11:22:33입니다.
    now = now + 2;
    now.OutTime();          // 현재 시간은 11:22:35입니다.
    now += 40;
    now.OutTime();          // 현재 시간은 11:23:15입니다.
    return 0;
}