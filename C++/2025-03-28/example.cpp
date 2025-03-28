#include <string>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class myptr{
private:
    T *p;
public:
    explicit myptr(T *ap) : p(ap) { }
    ~myptr() { // 소멸자
        delete p;
        cout << "메모리가 해제되었습니다." << endl;
    }

    T& operator*() { // 역참조 연산자
        return *p;
    }

    T* operator->() { // 멤버 접근 연산자
        return p;
    }
};

int main(){
    // myptr를 사용하여 동적 메모리 관리
    myptr<string> ptr(new string("Hello, myptr!"));

    // 역참조 연산자를 사용하여 값 출력
    cout << "값: " << *ptr << endl;

    // 멤버 접근 연산자를 사용하여 string의 메서드 호출
    cout << "문자열 길이: " << ptr->length() << endl;

    return 0;
}