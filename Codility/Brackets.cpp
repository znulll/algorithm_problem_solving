// https://app.codility.com/demo/results/training9RTBZU-66R/

#include <map>
#include <stack>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> check1;
    int open = 0;
    int close = 0;
    int size = (int)S.size();
    
    map<char, char> m;
    m[']'] = '[';
    m['}'] = '{';
    m[')'] = '(';
    
    for(int i=0; i<size; i++){
        if(open > (int)(size/2) || close > (int)(size/2)) return 0;
        if(S[i] == '[' || S[i] == '{' || S[i] == '('){
            check1.push(S[i]);
            open++;
        }
        else if(S[i] == ']' || S[i] == '}' || S[i] == ')'){
            close++;
            if(check1.top() == m[S[i]]) check1.pop();
            else return 0;
        } 
    }
    
    return 1;
}