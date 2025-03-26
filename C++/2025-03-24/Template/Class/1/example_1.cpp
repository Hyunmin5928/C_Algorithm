#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T &a, T &b){
    T t;
    t = a; a = b; b = t;
}

class Human{
private:
    char *name;
    int age;
public:
    Human(){
        name = new char[1];
        name[0] = NULL;
        age = 0;
    }
    Human(const char *aname, int aage){
        name = new char[strlen(aname) + 1];
        strcpy(name, aname);
        age = aage;
    }
    Human(const Human &other){
        name = new char[strlen(other.name + 1)];
        strcpy(name, other.name);
        age = other.age;
    }
    Human &operator =(const Human &other){
        if(this != &other){
            delete[] name;
            name = new char[strlen(other.name + 1)];
            strcpy(name, other.name);
            age = other.age;
        }
        return *this;
    }
    ~Human(){
        delete[] name;
    }
    void intro(){
        printf("이름 = %s, 나이 = %d\n", name, age);
    }
};

int main(){
    Human a("이승만", 25);
    Human b("박정희", 12);

    a.intro();
    b.intro();

    swap(a, b);
    a.intro();
    b.intro();

    /*
    이름 = 이승만, 나이 = 25
    이름 = 박정희, 나이 = 12
    이름 = 박정희, 나이 = 12
    이름 = 이승만, 나이 = 25
    */

    return 0;
}