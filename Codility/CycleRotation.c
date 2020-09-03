// https://app.codility.com/demo/results/trainingRE34DY-Z2C/

struct Results solution(int A[], int N, int K) {
    struct Results result;
    result.A = A;
    result.N = N;
    
    
    int temp;
    int i,shift;
    
    if(N == 0) return result;
    if(N == K) return result;
    if(N < K) {K = K%N;}
    
    for(shift=0; shift<K; shift++){
        temp = result.A[N-1];
        for(i=N-1; i>=0; i--){
            if(i == 0) result.A[i] = temp;
            else result.A[i] = result.A[i-1];
        }
    }
    
    return result;
}