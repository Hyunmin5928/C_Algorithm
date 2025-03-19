#include <stdio.h>
#include <string.h>
class Human
{
private:
    char *pname;
    int age;

public:
    Human(const char* apname, int aage){
        pname = new char[strlen(apname) + 1];
        strcpy(pname, apname);
        age = aage;
        printf("%s 객체의 생성자가 호출되었습니다.\n", pname);
    }
    ~Human(){
        printf("%s 객체가 파괴되었습니다.", pname);
        delete[] pname;
    }
    void intro(){
        printf("이름 = %s, 나이 = %d\n", pname, age);
    }
};
int main(void){
    Human boy("김수한무거북이와두루미", 12);

    boy.intro();

    return 0;
}