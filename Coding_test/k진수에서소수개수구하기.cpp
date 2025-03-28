#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ChangeNum {
private:
    int num;
    int k;
    string cnum;
public:
    ChangeNum(int anum, int ak) {
        num = anum;
        k = ak;
        cnum = "";
    }
    void Calc(){
        if (k == 10){
            cnum = to_string(num);
        }
        else {
            int tmp = num;
            while (tmp > 0) {
                cnum = to_string(tmp % k) + cnum;  // 나머지를 앞쪽에 추가
                tmp /= k;
            }
            if (cnum.empty()) cnum = "0";  // 0일 경우 예외 처리
        }
    }
    string Get_Cnum(){
        return cnum;
    }
    void printAll(){
        printf("%d %d %s\n", num, k, cnum.c_str());
    }
    int Find_PrimeNum(){
        long long find = 0, ans = 0;
        string sn = "";
        int idx = 0;
        for (char n : cnum){
            if((n - '0') == 0){
                if(!sn.empty()){
                    find = stoll(sn);
                    if(CheckPrime(find)){
                        ans++;
                    }
                }
                sn = "";
            }
            else{
                sn += n; 
            }
            idx++;
        }
        if(!sn.empty()){
            find = stoll(sn);
            if(CheckPrime(find)){
                ans++;
            }
        }
        return ans;
    }
    bool CheckPrime(long long num){
        if(num == 1 || num < 1){
            return false;
        }
        for(long long i = 2; i * i <= num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
};

int solution(int n, int k) {
    int answer = -1;
    ChangeNum CN(n, k);
    CN.Calc();
    
    //CN.printAll();
    
    answer = CN.Find_PrimeNum();
    
    return answer;
}