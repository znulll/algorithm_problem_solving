// https://app.codility.com/demo/results/trainingKFVFP3-XQH/

#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size();
    int distinct = size;
    for(int i=0; i<size; i++){
        if(A[i] < 0) A[i] = -A[i];
    }
    sort(A.begin(), A.end());
    
    for(int i=1; i<size; i++){
        if(A[i] == A[i-1]) distinct -= 1;
    }

    return distinct;
}