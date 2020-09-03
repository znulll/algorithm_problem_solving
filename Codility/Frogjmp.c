// https://app.codility.com/demo/results/trainingPAX7YW-8K4/

int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 6.2.0)
    int jmp = 0;
    int dist = Y - X;
    if(dist == 0) return jmp;
    else{
        if(dist%D == 0) jmp = dist/D;
        else jmp = (dist / D) +1;
        return jmp;
    }
}