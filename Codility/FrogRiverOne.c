// https://app.codility.com/demo/results/trainingTCFGPF-PVQ/

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int POSITION[100000] = {0,};
    int cur_pos = 0;
    int time = 0;
    int falling_pos;
    
    while(time < N){
        falling_pos = A[time];
        POSITION[falling_pos] = 1;
        while(POSITION[cur_pos+1] == 1) cur_pos++;
        if(cur_pos == X) return time;
        time++;
    }
    
    return -1;
}