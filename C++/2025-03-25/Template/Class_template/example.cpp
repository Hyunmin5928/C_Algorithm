#include <stdio.h>

template <typename T, int N>
class Array{
private:
    T ar[N];
public:
    void SetAt(int n, T v) { if ( n < N && n >= 0) ar[n] = v; }
    T GetAt(int n) { return (n < N && n >= 0 ? ar[n] : 0); }
};


int main(){
    Array<int, 5> ari;
    ari.SetAt(1, 1234);
    ari.SetAt(1000, 5678);               // 1000 번째 인덱스는 존재하지 않음
    
    printf("%d\n", ari.GetAt(1));        // 1234
    printf("%d\n", ari.GetAt(5));        // 0

    return 0;
}