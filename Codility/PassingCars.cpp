// https://app.codility.com/demo/results/trainingRU3NFX-5NK/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    int num_zero = 0;
    
    for(int i=0; i<A.size(); i++){
        if(A[i] == 0) num_zero++;
        else if(A[i] == 1) {
            ans += num_zero;
            if (ans > 1000000000) return -1;
        }
    }

    return ans;
}