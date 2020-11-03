// https://app.codility.com/demo/results/trainingBY8SY3-EUJ/

#include <vector>

int getMaxDivisor(int A, int B){
    int a,b;
    if(A>=B) {
        a = A;
        b = B;
    }
    else{
        a = B;
        b = A;
    }
    
    if(a % b == 0) {
        return b;
    }
    
    return getMaxDivisor(b, a%b);
}

bool isSameDivisors(int A, int B) {
        int gmd_ab = getMaxDivisor(A, B);
        int gmd_a = 0;
        int gmd_b = 0;
        
        while(gmd_a != 1) {
            gmd_a = getMaxDivisor(A, gmd_ab);
            A /= gmd_a;
        }
        
        while(gmd_b != 1) {
            gmd_b = getMaxDivisor(B, gmd_ab);
            B /= gmd_b;
        }
        
        return (A == 1 && B == 1) ? true : false;
    }

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    int test_case = (int) A.size();
    int result = 0;
    
    for(int i=0; i<test_case; i++){
        if(isSameDivisors(A[i], B[i])) result++;
    }
    
    return result;
}