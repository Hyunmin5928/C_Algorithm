#include <string>
#include <vector>

using namespace std;

class ChangeNum {
private:
    int num;
    int k;
    int cnum;
public:
    ChangeNum(int anum, int ak, int acnum = 0) {
        num = anum;
        k = ak;
        cnum = acnum;
    }
    void Calc(){
        int tmp = 0;
        cnum = tmp;
    }
    int Get_Cnum(){
        return cnum;
    }
};

int solution(int n, int k) {
    int answer = -1;
    ChangeNum CN(n, k);
    return answer;
}