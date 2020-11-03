// https://app.codility.com/demo/results/trainingJRTTZY-2EG/

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>

// To get subvector
vector<int> get_subvector(vector<int> &v, int m, int n) {
   auto first = v.begin() + m;
   auto last = v.begin() + n + 1;
   vector<int> vector(first, last);
   
   return vector;
}

// To get maximal sum from 0 to cur_idx
void DP(int cur_idx, vector<int> &A, vector<int> &max){
    vector<int> temp;
    
    if(cur_idx < 1) max[cur_idx] = A[0];
    else if(cur_idx < 2) max[cur_idx] = A[0] + A[1];
    else if(cur_idx < 6) {
        temp = get_subvector(max, 0, cur_idx-1);
        sort(temp.rbegin(), temp.rend());
        max[cur_idx] = temp[0] + A[cur_idx];
    }
    else{
        temp = get_subvector(max, cur_idx-6, cur_idx-1);
        sort(temp.rbegin(), temp.rend());
        max[cur_idx] = temp[0] + A[cur_idx];
    }
    
    return;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int) A.size();
    vector<int> max(size, 0);
    for(int i=0; i<size; i++) DP(i, A, max);
    
    return max[size-1];
}