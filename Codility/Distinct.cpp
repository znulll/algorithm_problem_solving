// https://app.codility.com/demo/results/trainingVZQVDJ-XFJ/

#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int ans = 0;
    
    for(int i=0; i<A.size(); i++){
        if(i == 0) ans +=1 ;
        else if(A[i] != A[i-1]) ans += 1;
    }
    
    return ans;
}