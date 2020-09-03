// https://app.codility.com/demo/results/trainingD2HSXB-52H/

#include <vector>
#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int upstream = 0;
    int size = (int) A.size();
    int direction = 0;
    stack<int> downstream;
    
    for(int i=0; i<size; i++) direction += B[i];
    if(size <= 1) return 1;
    if(direction == 0 || direction == size) return size;
    
    for(int i=0; i<size; i++){
        // if i is downstream
        if(B[i] == 1) downstream.push(A[i]);
        
        // if i is upstream
        else{
            // if downstream is empty
            if(downstream.empty()) upstream++;
            
            // if downstream exist
            else{
                while(!downstream.empty()){
                    if(A[i] > downstream.top()){
                        downstream.pop();
                        if(downstream.empty()) upstream++;
                    }
                    else break;
                }
            }
            
        }
    }
    
    return upstream + downstream.size();
}