#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int func(int n){
    int a = 0, b = 1;
    int temp = 0;
    int i = 1;
    while(i != n){
        temp = (a + b)%1234567;
        a = b % 1234567;
        b = temp % 1234567;
        i++;
    }
    return temp;
}

int solution(int n) {
    int answer = 0;
    answer = func(n);
    return answer;
}