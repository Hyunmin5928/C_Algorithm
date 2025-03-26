#include <stdio.h>

class Parent{
public:
    virtual void PrintMe() { printf("I am Parent.\n"); }
};

class Child : public Parent {
private:
    int num;
public:
    Child(int anum) : num(anum) { }
    virtual void PrintMe() { printf("I am Child.\n"); }
    void PrintNum() { printf("Hello Child = %d\n", num); }
};

void func(Parent *p){
    p->PrintMe();
    ((Child *)p)->PrintNum();
}

int main(){
    Parent p;
    Child c(5);

    func(&p);
    func(&c);

/*  출력
    I am Parent.
    Hello Child = 589896176
    I am Child.
    Hello Child = 5
*/

    return 0;
}