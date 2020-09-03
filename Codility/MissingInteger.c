//  https://app.codility.com/demo/results/trainingS2AMAT-RXV/

int solution(int A[], int N) {
    int i, j=1;
    int max = -1000000;
    int smallest = 0;
    
    // find max 
    for(i=0; i<N; i++){
        if(max < A[i]) max = A[i];
    }
    
    if(max <= 0) return 1;
    else{
        int check[1000001];
        for(i=0; i<N; i++){
            if(A[i] > 0) check[A[i]] = 1;
            while(check[j] == 1){
                smallest++;
                j++;
            }
        }
        return smallest+1;
    }
}