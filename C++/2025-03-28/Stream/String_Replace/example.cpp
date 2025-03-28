#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1 = "독도는 일본땅";

    cout << s1 << endl;
    s1.replace(s1.find("일본"), 5, "대한민국");
    cout << s1 << endl;
/*  출력
    독도는 일본땅
    독도는 대한민국땅
*/
    return 0;
}