#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("1234567890");
    string s2("^_^");

    cout << s1 << endl;
    s1.insert(5, "XXX");
    cout << s1 << endl;
    s1.insert(5, s2);
    cout << s1 << endl;
    s1.erase(5, 6);
    cout << s1 << endl;
/*  출력
    1234567890
    12345XXX67890
    12345^_^XXX67890
    1234567890
*/
    return 0;
}