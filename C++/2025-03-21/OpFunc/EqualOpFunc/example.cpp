#include <stdio.h>
#include <string.h>

class Human
{
private:
    char *pname;
    int age;
public:
    Human(){
        pname = new char[1];
        pname[0] = NULL;
        age = 0;
    }
    Human(const char *aname, int aage){
        pname = new char[strlen(aname) + 1];
        strcpy(pname, aname);
        age = aage;
    }
    Human(const Human &other){
        pname = new char[strlen(other.pname) + 1];
        strcpy(pname, other.pname);
        age = other.age;
    }
    // **대입 연산자 오버로딩 추가**
    Human& operator=(const Human &other) {
		    if (this == &other) return *this;  // 자기 자신과의 대입 방지
		    
		    // 기존 동적 메모리 해제
		    delete[] pname;
		    
		    // 새로운 메모리 할당 및 복사 (Deep Copy)
		    pname = new char[strlen(other.pname) + 1];
		    strcpy(pname, other.pname);
		    age = other.age;
		    
		    return *this;
    }
    ~Human(){
        delete[] pname;
    }
    void intro(){
        printf("이름 = %s, 나이 = %d\n", pname, age);
    }
};

int main(void){
    Human kang("강감찬", 1424);
    Human boy;

    boy = kang;
    boy.intro();    // 이름 = 강감찬, 나이 = 1424

    return 0;
}