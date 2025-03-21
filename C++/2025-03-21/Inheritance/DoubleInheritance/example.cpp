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
    void intro(){       // method overriding
        printf("%d학번 %s입니다.\n", stunum, name);
    }
};

class Graduate : public Student{
protected:
    char thesis[32];
public:
    Graduate(const char *aname, int aage, int astunum, const char *athesis) : Student(aname, aage, astunum) {
        strcpy(thesis, athesis);
    }
    void research(){
        printf("학번 : %d, 나이 : %d, 이름 : %s\n", stunum, age, name);
        printf("%s을 연구하고 논문을 쓴다.\n", thesis);
    }
};

int main(){
    Graduate moon("문종민", 45, 920629, "게임방 상권 분석");
    moon.research();
    // 학번 : 920629, 나이 : 45, 이름 : 문종민
    // 게임방 상권 분석을 연구하고 논문을 쓴다.

    return 0;
}