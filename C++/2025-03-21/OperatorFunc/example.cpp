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
    const Time AddTime(const Time &other) const {
        Time t;
        t.sec = sec + other.sec;
        t.min = min + other.min;
        t.hour = hour + other.hour;

        t.min += t.sec / 60;
        t.sec %= 60;
        t.hour += t.min / 60;
        t.min %= 60;
        t.hour %= 24;
        // 시간, 분, 초가 각각 한계를 넘어가지 않도록 조절
        return t;
    }
};


int main(void){
    Time t1(15, 10, 30);
    Time t2(23, 20, 40);
    Time t3;    // 기본 연산자를 필요로 하는 부분
    t3 = t1.AddTime(t2);

    t3.OutTime();    // 현재 시간은 14:31:10입니다.

    t3.SetTime(13,4,12);
    t3.OutTime();

    return 0;
}