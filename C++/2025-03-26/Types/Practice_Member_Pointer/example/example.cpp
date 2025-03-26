#include <stdio.h>

class Parent{
public:
    int p;
};

class Child : public Parent{
public:
    int c;
};

int main(){
    int Parent::*pP;
    int Child::*pC;

    pP = &Parent::p;
    pC = &Child::c;

    pC = &Parent::p;
    pP = &Child::p;
    // pP = &Child::c;  // 오류 발생!

    return 0;
}