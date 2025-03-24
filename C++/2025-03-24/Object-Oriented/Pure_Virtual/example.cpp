#include <stdio.h>

class Shape {
public:
    // 순수 가상 함수 선언부!
    virtual void draw() = 0;
};

class Line : public Shape {
public:
    // Override
    void draw() { puts("선을 긋습니다."); }
};

class Circle : public Shape { 
public:
    // Override
    void draw() { puts("동그라미 그리기."); }
};

class Rect : public Shape {
public:
    // Override
    void draw() { puts("사각형 그리기."); }
};

int main(){
    Shape *pS[3];

    // Shape s;
    pS[0] = new Line;
    pS[1] = new Rect;
    pS[2] = new Circle;

    for (int i = 0; i < sizeof(pS)/sizeof(pS[0]); i++){
        pS[i]->draw();
    }
    /*
    선을 긋습니다.
    사각형 그리기.
    동그라미 그리기.
    */

    for (int i = 0; i < sizeof(pS)/sizeof(pS[0]); i++){
        delete pS[i];
    }

    return 0;
}