#include <string>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

string solution(string s) {
    string answer = "";

    stringstream ss(s);

    vector<string> strings;

    string str;

    while (getline(ss, str, ' ')){
        strings.push_back(str);
    }
    
    for(int i = 0; i < strings.size(); i++){
        for(int j = 0; j < strings[i].length(); j++){
            if(j % 2 == 0){
                strings[i][j] = toupper(strings[i][j]);
            }
            else{
                strings[i][j] = tolower(strings[i][j]);
            }
            // printf("strings[%d][%d] = %c\n", i, j, strings[i][j]);
        }
    }

    return answer;
}