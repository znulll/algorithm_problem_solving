https://app.codility.com/demo/results/trainingDHBQ8F-W7Q/

#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    int size = (int) A.size();
    if (size < 2) return 0;

    int min_price = A[0]; //initialize
    int max_local = 0;
    int max_global = 0;
    
    for (int i=1; i<size; i++) {
        if(A[i] < min_price) min_price = A[i];
        else max_local = A[i] - min_price;
        
        max_global = max(max_global, max_local);
    }
    
    if(max_global < 0)
        return 0;
    else
        return max_global;
}