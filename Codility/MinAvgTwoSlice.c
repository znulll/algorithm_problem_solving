// https://app.codility.com/demo/results/training5NQQ5G-ZTA/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, j;
    
    // 전체 평균 구하기
    int total_sum = 0;
    for(i=0; i<N; i++) total_sum += A[i];
    float total_avg = (float) total_sum/N;
    
    // min_avg, start_poin 초기화
    float min_avg = total_avg;
    int start_point = 0;
    
    for(i=0; i<N-1; i++){
        // 시작점이 전체평균보다 작을 때만
        if((float)A[i] < min_avg){
            int temp_sum = A[i];
            int temp_num = 1;
            float temp_avg;
            for(j=i+1; j<N; j++){
                temp_sum += A[j];
                temp_num += 1;
                temp_avg = (float) temp_sum/temp_num;
                if(temp_avg < min_avg) {
                    min_avg = temp_avg;
                    start_point = i;
                    break;
                }
                else if (total_avg < temp_avg) break;
            }
        }
    }
    return start_point;
}