#include <stdio.h>
#include <string.h>

class Human{
private: 
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
private:
    int stunum;
public:
    Student(const char *aname, int aage, int astunum) : Human(aname, aage) {
        stunum = astunum;
    }
    void study() {
        printf("학번 %d 학생이 공부하고 있습니다.\n", stunum);
    }
};

int main(){
    Human kim("김상형", 29);
    kim.intro();
    Student han("김한결", 15, 123456);
    han.intro();
    han.study();

    return 0;
}