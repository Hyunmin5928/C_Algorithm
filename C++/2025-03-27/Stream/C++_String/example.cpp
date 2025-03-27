#include <iostream>

using namespace std;

int main(){
    string s("C++ string");

    cout << s << " 문자열의 길이 = " << s.size() << endl;
    cout << s << " 문자열의 길이 = " << s.length() << endl;
    cout << s << " 문자열의 할당 크기 = " << s.capacity() << endl;
    cout << s << " 문자열의 최대 길이 = " << s.max_size() << endl;

    s.resize(6);
    cout << s << " 길이 = " << s.size() << ",할당 크기 = " << s.capacity() << endl;

    s.reserve(100);
    cout << s << " 길이 = " << s.size() << ",할당 크기 = " << s.capacity() << endl;

/*  출력
    C++ string 문자열의 길이 = 10
    C++ string 문자열의 길이 = 10
    C++ string 문자열의 할당 크기 = 15
    C++ string 문자열의 최대 길이 = 4611686018427387903
    C++ st 길이 = 6,할당 크기 = 15
    C++ st 길이 = 6,할당 크기 = 100
*/

    return 0;
}