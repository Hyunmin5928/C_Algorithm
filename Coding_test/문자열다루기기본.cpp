#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int sizes = sizeof(s)/sizeof(s[0]);
    int len = 0;
    for(int i = 0; i < sizes; i++){
        if(s[i] == NULL){
            break;
        }
        if(s[i] >= '0' && s[i] <='9'){
            answer = true;
        }
        else {
            printf("%c", s[i]);
            return false;
        }
        len++;
    }
    if(len != 4 && len != 6){
        printf("h");
        return false;
    }
    
    return answer;
}