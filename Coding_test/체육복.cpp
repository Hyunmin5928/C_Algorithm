#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Check{
private:
    vector<int> lost;
    vector<int> reserve;
    int answer;
public:
    Check(int aanswer, vector<int> alost, vector<int> areserve) { 
        answer = aanswer;
        lost = alost;
        reserve = areserve;
    }
    // void printAll(){
    //     printf("answer = %d\n",answer);
    //     for(int i = 0; i < lost.size(); i++){
    //         printf("lost[%d] = %d\n", i, lost[i]);
    //     }
    //     for(int i = 0; i < reserve.size(); i++){
    //         printf("reserve[%d] = %d\n", i, reserve[i]);
    //     }
    // }
    int GreedyStep_1(){
        answer = answer - lost.size();
        for(int i = 0; i < lost.size(); i++){
            for(int j = 0; j < reserve.size(); j++){
                if(lost[i] == reserve[j]){
                    answer++;
                    printf("erase lost[%d] = %d, reserve[%d] = %d\n"
                           , i, lost[i], j, reserve[j]);
                    lost.erase(lost.begin() + i);
                    reserve.erase(reserve.begin() + j);
                    j--;
                    i--;
                }
            }
        }
        return answer;
    }
    int GreedyStep_2(){
        for(int i = 0; i < lost.size(); i++){
            for(int j = 0; j < reserve.size(); j ++){
                if((lost[i] + 1) == reserve[j]){
                    answer++;
                    lost.erase(lost.begin() + i);
                    reserve.erase(reserve.begin() + j);
                    i--;
                    j--;
                }
                else if((lost[i] - 1) == reserve[j]){
                    answer++;
                    lost.erase(lost.begin() + i);
                    reserve.erase(reserve.begin() + j);
                    i--;
                    j--;
                }
            }
        }
        return answer;
    }
};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    Check c(answer, lost, reserve);
    
    answer = c.GreedyStep_1();
    answer = c.GreedyStep_2();
    
    return answer;
}

