// https://app.codility.com/demo/results/trainingM4RRVU-AGE/

#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() == 3) return A[0]*A[1]*A[2];
    
    int size = A.size();
    sort(A.begin(), A.end());
    if(A[0]*A[1]*A[size-1] > A[size-2]*A[size-1]*A[size-3]) return A[0]*A[1]*A[size-1];
    else return A[size-2]*A[size-1]*A[size-3];
}