#include <stdio.h>
#include "cursor.h"
#include <iostream>
using namespace std;

template <typename T>
class PosValue{
private:
    int x, y;
    T value;
public:
    PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) { }
    void OutValue(){
        gotoxy(x, y);
        cout << value << endl;
    }
};
 
template <> class PosValue<double>{
private:
    int x, y;
    double value;
public:
    PosValue(int ax, int ay, double av) : x(ax), y(ay), value(av) { }
    void OutValue(){
        gotoxy(x, y);
        cout << "[" << value << "]" << endl;
    }
};

int main(){
    PosValue<int> iv(10, 10, 2);
    PosValue<double> dv(25, 5, 3.14);
    PosValue<char> cv(30, 15, 'C');

    iv.OutValue();
    dv.OutValue();
    cv.OutValue();

    /* 출력
    


                         [3.14]




          2




                              C
    
    */

    return 0;
}