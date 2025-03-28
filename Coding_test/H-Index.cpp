#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    sort(citations.begin(), citations.end());
    printf("%d\n",n);
    int temp = 0;

    for(int i = 0; i < n; i++){
        if (n - i >= citations[i]){
            answer = citations[i];
        }
        else{
            break;
        }
    }
    
    return answer;
}