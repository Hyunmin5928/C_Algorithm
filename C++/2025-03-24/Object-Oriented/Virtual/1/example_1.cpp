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
    virtual void intro(){
        printf("이름 : %s, 나이 : %d\n", name, age);
    }
    void eat(){
        puts("냠냠냠");
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
    // Override
    void intro(){
        printf("%d학번 %s입니다.\n", stunum, name);
    }
};

int main(){
    Human h("김사람", 10);
    Student s("이학생", 15, 12345689);

    Human *pH;

    pH = &h;
    pH->intro();    // 이름 : 김사람, 나이 : 10
    pH->eat();      // 냠냠냠

    pH = &s;
    pH->intro();    // 12345689학번 이학생입니다.
    pH->eat();      // 냠냠냠

    return 0;
}