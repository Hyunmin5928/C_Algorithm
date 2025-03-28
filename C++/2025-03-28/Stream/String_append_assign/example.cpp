#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("1234567890");
    string s2("abcdefghijklmnopqrstuvwxyz");
    string s3;
    s3.assign(s1, 3, 4);        // strcpy와 동일한 역할, 원하는 범위만 복사 가능
    cout << s3 << endl;
    s3.append(s2, 10 ,7);       // 문자열 뒤에 추가해주는 역할, 원하는 범위만 추가 가능
    cout << s3 << endl;
/*  출력
    4567
    4567klmnopq
*/
    return 0;
}