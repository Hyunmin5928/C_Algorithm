#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";

    int idx = 0;

    for (char c : s){
        if(c == ' ') {
            idx = 0;
        }
        else{
            if((idx % 2) == 0){
                c = toupper(c);
            }
            else{
                c = tolower(c);
            }
            idx++;
        }
        answer += c;
    }

    return answer;
}