#include <stdio.h>

class Shape {
public:
    // void draw() { puts("도형 오브젝트 입니다."); }       // virtual 키워드를 붙이지 않으면 Shape 클래스의 draw함수만 호출된다.
    virtual void draw() { puts("도형 오브젝트 입니다."); }
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
    Shape *ar[] = { new Shape(), new Rect(), new Circle(), new Rect(), new Line() };

    for (int i = 0; i < sizeof(ar)/sizeof(ar[0]); i++){
        ar[i]->draw();
    }

    /*
    도형 오브젝트 입니다.
    사각형 그리기.
    동그라미 그리기.
    사각형 그리기.
    선을 긋습니다.
    */
    
    for (int i = 0; i < sizeof(ar)/sizeof(ar[0]); i++){
        delete ar[i];
    }

    return 0;
}