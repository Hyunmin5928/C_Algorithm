#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("aaa");
    string s2("bbb");

    cout << (s1 == s1 ? "같다" : "다르다") << endl;
    cout << (s1 == s2 ? "같다" : "다르다") << endl;
    cout << (s1 > s2 ? "크다" : "작다") << endl;

    string s3("1234567");
    string s4("1234999");
    cout << (s3.compare(s4) == 0 ? "같다" : "다르다") << endl;
    cout << (s3.compare(0, 4, s4, 0 ,4) == 0 ? "같다" : "다르다") << endl;

    string s5("hongkildong");
    cout << (s5 == "hongkildong" ? "같다" : "다르다") << endl;


/*  출력
    같다
    다르다
    작다
    다르다
    같다
    같다
*/
    return 0;
}