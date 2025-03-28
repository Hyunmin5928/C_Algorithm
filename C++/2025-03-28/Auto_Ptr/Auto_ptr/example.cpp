#include <iostream>
#include <memory>

using namespace std;

int main(){
    auto_ptr<double> rate(new double);
    *rate = 3.1415;

    cout << *rate << endl;
    // 파괴를 하지 않아도 알아서 메모리가 해제 됨.

    auto_ptr<string> pStr(new string("AutoPtr Test"));
    cout >> *pStr << endl;
    // 아무것도 출력되지 않음.

    return 0;
}