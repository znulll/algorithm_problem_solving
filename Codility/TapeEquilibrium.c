// https://app.codility.com/demo/results/training43NTZ4-FEZ/

int FRONT[100000] = {0,};
int RARE[100000] = {0,};
int DIST[100000] = {0,};

int total_sum(int A[], int N){
    int total = 0, i;
    for(i=0; i<N; i++){total += A[i];}
    return total;
}

int getDist(int front, int rare, int i){
    int dist = front - rare;
    if(dist < 0) dist = -dist;
    return dist;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int TOTAL = 0, i;
    TOTAL = total_sum(A, N);
    FRONT[1] = A[0];
    RARE[1] = TOTAL-A[0];
    DIST[1] = getDist(FRONT[1], RARE[1], 1);
    
    int minDist = DIST[1];
    
    // if(N==2) return minDist;
    
    for(i=2; i<N; i++){
        FRONT[i] = FRONT[i-1] + A[i-1];
        RARE[i] = RARE[i-1] - A[i-1];
        DIST[i] = getDist(FRONT[i], RARE[i], i);
        if(minDist > DIST[i]) minDist = DIST[i];
        // printf("%d: %d\n", i, DIST[i]);
    }
    
    return minDist;
}