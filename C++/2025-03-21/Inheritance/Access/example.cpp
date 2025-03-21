#include <stdio.h>
#include <string.h>

class Human{
protected:           // 자식에게 허용
    char name[12];
    int age;
public:
    Human(const char *aname, int aage){
        strcpy(name, aname);
        age = aage;
    }
    void intro(){
        printf("이름 = %s, 나이 = %d\n", name, age);
    }
};

class Student : public Human{
protected:
    int stunum;
public:
    Student(const char *aname, int aage, int astunum) : Human(aname, aage) {
        stunum = astunum;
    }
    void study() {
        printf("%s 학생 학습 중.\n", name);
    }
    void report() {
        printf("이름 : %s, 학번 : %d 보고서 제출.\n", name, stunum);
    }
};

int main(){
    Student han("김한결", 15, 123456);
    han.intro();                            // 이름 = 김한결, 나이 = 15
    han.study();                            // 김한결 학생 학습 중.
    han.report();                           // 이름 : 김한결, 학번 : 123456 보고서 제출.

    return 0;
}