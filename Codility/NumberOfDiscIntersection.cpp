#include <algorithm>
#include <limits.h>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int intersect = 0;
    int size = (int) A.size();
    vector<int> left(size);
    vector<int> right(size);

    // 양끝 점 구하기
    for(int i=0; i<size; i++){
        if(i-A[i] < INT_MIN) left[i] = INT_MIN;
        else left[i] = i-A[i];
        if(i+A[i] > INT_MAX) right[i] = INT_MAX;
        else right[i] = i+A[i];
    }
    
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(left[i] > right[j] || left[j] > right[i]) continue;
            else{
                intersect++;
                if(intersect > 10000000) return -1;
            }
        }
        
    }
    
    return intersect;
}

