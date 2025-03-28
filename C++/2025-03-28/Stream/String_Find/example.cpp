#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("string class find function");
    string s2("func");

    cout << "i:" << s1.find('i') << "번째" << endl;
    cout << "i:" << s1.find('i', 10) << "번째" << endl;
    cout << "ass:" << s1.find("ass") << "번째" << endl;
    // "finding"의 앞 4글자(0번 인덱스에서 4개) "find" 를 s1에서 찾는 부분
    cout << "finding의 앞 4:" << s1.find("finding", 0, 4) << "번째" << endl;
    cout << "kiss:" << s1.find("kiss") << "번째" << endl;
    cout << s2 << ":" << s1.find(s2) << "번째" << endl;

/*  출력
    i:3번째
    i:14번째
    ass:9번째
    finding의 앞 4:13번째
    kiss:18446744073709551615번째
    func:18번째
*/
    return 0;
}