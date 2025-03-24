#include <stdio.h>
#include <string.h>

class Human{
protected:
    char name[12];
    int age;
public:
    Human(const char *aname, int aage){
        strcpy(name, aname);
        age = aage;
    }
    void intro(){
        printf("name : %s, age : %d\n", name, age);
    }
};

class Student : public Human
{
protected:
    int stunum;
public:
    Student(const char *aname, int aage, int astunum) : Human(aname, aage){
        stunum = astunum;
    }
    void intro(){
        printf("%d학번 %s입니다.\n", stunum, name);
    }
    void study(){
        printf("studying ddd\n");
    }
};

int main(){
    Human h("김공자", 10);
    Student s("학생1", 15, 12345689);

    Human *pH;
    Student *pS;

    pH = &h;        // 가능
    pS = &s;        // 가능
    pH = &s;        // 가능
    // pS = &h;        // 불가능

    pS = (Student*)&h;
    pS->intro();        // -979371472학번 김공자입니다.

    pH->intro();        // name : 학생1, age : 15

    return 0;
}