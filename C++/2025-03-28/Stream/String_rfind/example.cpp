#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("starcraft");
    string s2("123abc456");
    string moum("aeiou");
    string num("0123456789");

    cout << "순방향 t:" << s1.find('t') << "번째" << endl;
    cout << "역방향 t:" << s1.rfind('t') << "번째" << endl;
    cout << "역방향 cra:" << s1.rfind("cra") << "번째" << endl;
    cout << "최초의 모음" << s1.find_first_of(moum) << "번쨰" << endl;
    cout << "최후의 모음" << s1.find_last_of(moum) << "번째" << endl;
    cout << "최초의 비숫자" << s2.find_first_not_of(num) << "번째" << endl;
    cout << "최후의 비숫자" << s2.find_last_not_of(num) << "번째" << endl;

/*  출력
    순방향 t:1번째
    역방향 t:8번째
    역방향 cra:4번째
    최초의 모음2번쨰
    최후의 모음6번째
    최초의 비숫자3번째
    최후의 비숫자5번째
*/
    return 0;
}