// https://app.codility.com/demo/results/trainingT8GM4A-64B/

#define MAX_N (1000000 + 10)
#define MAX_VALUE (1000000000 + 10)

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int ans = 0, i, j;
    int* check;
    check = (int*) malloc (sizeof(int)*N);
    for(i=0; i<N; i++){
        check[i] = 0;
    }

    for(i=0; i<N-1; i++){
        if(check[i] != 0) continue;
        for(j=i+1; j<N; j++){
            if(check[j] != 0) continue;
            else if(A[i] == A[j] && check[i] == 0 && check[j] == 0) {
                check[i] = j+1;
                check[j] = i+1;
            }
        }

    }
    
    for(i=0; i<N; i++){
        // printf("%d %d\n", A[i], check[i]);
        if(check[i] == 0) {
            ans = A[i]; 
            break;
        }
    }
    
    return ans;
}