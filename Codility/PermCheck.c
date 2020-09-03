// https://app.codility.com/demo/results/trainingSA7RY7-VAY/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    if(N == 1){
        if(A[0] == 1) return 1;
        else return 0;
    }
    
    int* check;
    check = (int*) malloc(sizeof(int)*(N+1));
    for(i=1; i<N+1; i++){check[i] = 0;}
    
    for(i=0; i<N; i++){
        if(A[i] > N || A[i] < 1) return 0;
        check[A[i]]++;
        if(check[i] > 1) return 0;
    }
    
    for(i=1; i<N+1; i++){
        if(check[i] != 1) return 0;
    }
    
    
    return 1;
}