#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("야호 신난다.");
    string s2;

    s2 = "임의의 문자열";
    cout << s2 << endl;
    s2 = s1;
    cout << s2 << endl;
    s2 = 'A';
    cout << s2 << endl;

    s1 += "문자열 연결.";
    cout << s1 << endl;
    s1 += s2;
    cout << s1 << endl;
    s1 += '!';
    cout << s1 << endl;

    string s3;
    s3 = "s1:" + s1 + "s2:" + s2 + '.';
    cout << s3 << endl;
/*  출력
    임의의 문자열
    야호 신난다.
    A
    야호 신난다.문자열 연결.
    야호 신난다.문자열 연결.A
    야호 신난다.문자열 연결.A!
    s1:야호 신난다.문자열 연결.A!s2:A.
*/

    return 0;
}