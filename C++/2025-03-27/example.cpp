#include <iostream>
#include <string>

using namespace std;

int main(){
    string name, addr;

    cout << "이름을 입력하시오 : ";
    cin >> name;
    cout << "입력한 이름은 " << name << "입니다." << endl;
    cin.ignore();        // 입력 버퍼 초기화
    cout << "주소를 입력하시오 : ";
    getline(cin, addr);
    cout << "입력한 주소는 " << addr << "입니다." << endl;
    

/*  출력
    이름을 입력하시오 : HongKildong
    입력한 이름은 HongKildong입니다.
    주소를 입력하시오 : Seoul Gangnam
    입력한 주소는 Seoul Gangnam입니다.
*/

    return 0;
}