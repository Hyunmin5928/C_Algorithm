#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "cursor.h"

class Point {
protected:
    int x, y;
    char ch;
public:
    Point(int ax, int ay, char ach) { x = ax; y = ay; ch = ach; }
    virtual void show() {
        gotoxy(x, y); _putch(ch);
    }
    virtual void hide() {
        gotoxy(x, y); _putch(' ');
    }
    void move(int nx, int ny) {
        hide();
        x = nx;
        y = ny;
        show();
    }
};

class Circle : public Point {
protected:
    int radius;
public:
    Circle(int ax, int ay, char ach, int aradius) : Point(ax, ay, ach) {
        radius = aradius;
    }
    void show() {
        for (double a = 0; a < 360; a += 10) {
            gotoxy(int(x + sin(a * 3.14 / 180) * radius), int(y - cos(a * 3.14 / 180) * radius / 2));
            _putch(ch);
        }
    }
    void hide() {
        for (double a = 0; a < 360; a += 10) {
            gotoxy(int(x + sin(a * 3.14 / 180) * radius), int(y - cos(a * 3.14 / 180) * radius / 2));
            _putch(' ');
        }
    }
};

int main() {
    Point p(1, 10, 'P');
    Circle c = { 20, 20, 'C', 12 };

    p.show();
    c.show();

    _getch();
    p.move(40,  10);
    _getch();
    c.move(40, 30);
    _getch();

    p.hide();
    _getch();
    c.hide();
    _getch();

    p.show();
    _getch();
    c.show();
    _getch();

    c.move(20, 20);
    _getch();

    return 0;
}