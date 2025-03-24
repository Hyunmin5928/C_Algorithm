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

    pH = &h;        
    pH->intro();    // name : 김공자, age : 10
    pH = &s;
    pH->intro();    // name : 학생1, age : 15

    return 0;
}