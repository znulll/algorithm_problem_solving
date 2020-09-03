int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    int divisible = 0;
    
    for(i=A; i<B+1; i++){
        if(i%K == 0) divisible++;
    }
    
    return divisible;
}

// https://app.codility.com/demo/results/trainingFJYN4Y-RJN/
int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    int divisible = 0;
    
    if(B<K){
        if(A == 0) return 1;
        else return 0;
    }
    
    for(i=A; i<B+1; i++){
        if(i==0) divisible++;
        else if(i<K) continue;
        if(i%K == 0) divisible++;
    }
    
    return divisible;
}