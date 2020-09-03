// https://app.codility.com/demo/results/trainingF29VVV-365/

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int i;
    int size = strlen(S);
    int num_A[size+1];
    int num_C[size+1];
    int num_G[size+1];
    num_A[0] = num_C[0] = num_G[0] = 0;
    int* input = (int*) malloc(sizeof(int) * M);
    
    for(i=0; i<size; i++){
        if(S[i] == 'A'){
            num_A[i+1] = num_A[i] + 1;
            num_C[i+1] = num_C[i];
            num_G[i+1] = num_G[i];
        } 
        else if(S[i] == 'C'){
            num_A[i+1] = num_A[i];
            num_C[i+1] = num_C[i] + 1;
            num_G[i+1] = num_G[i];
        } 
        else if(S[i] == 'G'){
            num_A[i+1] = num_A[i];
            num_C[i+1] = num_C[i];
            num_G[i+1] = num_G[i] + 1;
        }
        else{
            num_A[i+1] = num_A[i];
            num_C[i+1] = num_C[i];
            num_G[i+1] = num_G[i];
        }
    }
    
    for(i=0; i<M; i++){
        int start = P[i];
        int end = Q[i] + 1;
        if(P[i] == Q[i]){
            if(S[start] == 'A') input[i] = 1;
            else if(S[start] == 'C') input[i] = 2;
            else if(S[start] == 'G') input[i] = 3;
            else if(S[start] == 'T') input[i] = 4;
        }
        else{
            if(num_A[start] != num_A[end]) input[i] = 1;
            else if(num_C[start] != num_C[end]) input[i] = 2;
            else if(num_G[start] != num_G[end]) input[i] = 3;
            else input[i] = 4;
        }
    }
    
    result.A = input;
    result.M = M;
    return result;
}