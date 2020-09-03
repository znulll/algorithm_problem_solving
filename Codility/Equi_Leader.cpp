// https://app.codility.com/demo/results/trainingC7M938-6ZQ/

#include <map>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
 
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    map<int, int> m;
    int max_cnt = 0; 
    int max_idx = 0;
    int result = 0;
    int count = 0;
    
    

    for(int i = 0; i < (int)A.size(); i++){
        if(m.find(A[i]) != m.end()){
            m[A[i]] += 1;
            if(max_cnt < m[A[i]]){
                max_cnt = m[A[i]];
                max_idx = A[i];   
            }
        }
        else m.insert(pair<int, int>(A[i], 1));
    }
    
    if(max_cnt < (int) A.size()/2) return 0;
    
    for(int i = 0; i < (int)A.size(); i++){
        if(A[i] == max_idx){
            count++;
            m[max_idx]--;
        }
        int f_size = i+1;
        int r_size = (int)A.size() - f_size;
        
        if(m[max_idx] > r_size / 2 && count > f_size / 2) result++;
    }
    
    return result;
}