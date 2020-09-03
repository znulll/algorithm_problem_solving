// https://app.codility.com/demo/results/trainingR6F7HK-9PH/

void arrInput(int * arr, int num, int len) {
    int i;
    for (i = 0; i < len; i++)
        arr[i] = num;
}
 
struct Results solution(int N, int A[], int M) {
    struct Results result;
    int i, count = 0, max = 0, index = 0, flag = 0;
    int *arr = (int *)malloc(sizeof(int) * N);
 
    result.L = N;
    arrInput(arr, 0, N); // 0 초기화
 
    for (i = 0; i < M; i++) {
        if (A[i] > N) {
            max = count;
            index = i;
            flag = 1;
            continue;
        }
 
        if (flag == 1 && arr[A[i] - 1] < max)
            arr[A[i] - 1] = max;
 
        arr[A[i] - 1]++;
 
        if (arr[A[i] - 1] > count)
            count = arr[A[i] - 1];
    }
 
    if (flag == 0)
        result.C = arr;
    else {
        arrInput(arr, max, N);               //max 값과 index 값을 대입하여 배열을 마무리
        for (i = index + 1; i < M; i++)      //남은 요소 값들 증가
            arr[A[i] - 1]++;
 
        result.C = arr;
    }
 
    return result;
}



// int MAXCOUNTER_FLAG = 0;
// int CUR_MAX = 0;

// int* MaxCounter(int* A, int N, int Max){
//     int i;
//     for(i=0; i<N; i++){A[i] = Max;}
//     return A;
// }

// // N = array size, A = array, M = case
// struct Results solution(int N, int A[], int M) {
//     struct Results result;
//     // write your code in C99 (gcc 6.2.0)
    
//     result.C = (int*) calloc(N, sizeof(int));
//     result.L = N;
//     // result.C = MaxCounter(result.C, N, 0);
//     arrInput(result.C, 0, N);
    
//     int iter = 0;
    
//     for(iter=0; iter<M; iter++){
//         if(A[iter] > N){
//             if(MAXCOUNTER_FLAG == 1) continue;
//             result.C = MaxCounter(result.C, N, CUR_MAX);
//             MAXCOUNTER_FLAG = 1;
//         }
//         else{
//             int idx = A[iter] -1;
//             result.C[idx] = result.C[idx]+1;
//             if(CUR_MAX < result.C[idx]) CUR_MAX = result.C[idx];
//             MAXCOUNTER_FLAG = 0;
//         }
//     }
    
//     return result;
// }