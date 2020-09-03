// https://app.codility.com/demo/results/trainingHWFE6N-CCZ/

#include <limits.h>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_value = INT_MIN;
    int max_global = 0;
    int max_local = 0;
    int size = (int) A.size();
    if(size < 2) return A[0];
    
    for(int i=0; i<size; i++) {
        max_global += A[i];
        max_value = max(max_value, A[i]);
    }
    if(max_value < 0) return max_value;
    
    for(int i=0; i<size; i++) {
        max_local = max(0, max_local+A[i]);
        max_global = max(max_global, max_local);
    }
    
    return max_global;
}