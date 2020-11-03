// 54%
// https://app.codility.com/demo/results/trainingJWS2H5-49U/

#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int) A.size();
    vector<int> pos_A;
    
    int total = 0;
    
    for(int i=0; i<size; i++){
        if( A[i] < 0 ) pos_A.push_back(-A[i]);
        else pos_A.push_back(A[i]);
        total += pos_A[i];
    }
    
    int half = total/2;
    // int even = total%2;
    
    if(size == 0) return 0;
    else if(size == 1) return A[0];

    sort(pos_A.rbegin(), pos_A.rend());
    
    for(int i=0; i<size; i++){
        int temp_half = half;
        for(int j=i; j<size; j++){
            if(temp_half >= pos_A[j]) temp_half -= pos_A[j];
        }

        if(half > temp_half) half = temp_half;
        if(half == 0) break;
    }
    int max_possible_half = (total/2) - half;
    int rest = total - max_possible_half;
    int result = rest - max_possible_half;
    
    return result;
}