// https://app.codility.com/demo/results/trainingGD39XG-VKY/

int compare(const void *a, const void *b){    // 오름차순 비교 함수 구현
    int num1 = *(int *)a; 
    int num2 = *(int *)b;  

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    int find = -1;
    int flag = 0;
    qsort(A, N, sizeof(int), compare);
    
    for(i=0; i<N; i++){
        if(A[i] == i+2) {
            find = i+1;
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) find = N+1;
    
    return find;
}