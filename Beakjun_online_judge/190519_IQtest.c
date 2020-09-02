/* 190519 백준-수학-IQ test 문제 */

#include <stdio.h>

int getAccelrate(int* value, int n);
int getBias(int* value, int acc, int n);
int check(int* value, int N);

int main (void) {
    int N;  // 0 <= N <= 50 : input의 개수
    int a, b;   // a*앞수 + b
    int i;
    int ans;
    scanf("%d", &N);
    
    int value[N];
    for(i=0; i<N; i++){
        scanf("%d", &value[i]);
    }
    if(check(value, N) == 1){
        printf("B\n");    
    }
    else{
        a = getAccelrate(value, 0);
        b = getBias(value, a, 0);

        ans = (a * value[N-1]) + b;
        printf("%d\n", ans);
        // printf("A\n");           
    }
    
    return 0;
}

int getAccelrate(int* value, int n){
    int a;
    if((value[n+1] - value[n]) == 0){
        a = 0;
    }
    else{
        a = (int)((value[n+2]-value[n+1])/(value[n+1]-value[n]));
    }
    
    return a;
}

int getBias(int* value, int acc, int n){
    int b;
    b = value[n+1] - (acc*value[n]);

    return b;
}

int check(int* value, int N){
    int i;
    int check = 0;
    int a_N, a_otherN, b_N, b_otherN;
    for(i=0; i<N-2; i++){
        a_N = getAccelrate(value, i);
        b_N = getBias(value, a_N, i);
        a_otherN = getAccelrate(value, i+1);
        b_otherN = getBias(value, a_otherN, i+1);
        if((a_N != a_otherN) || (b_N != b_otherN)){
            check = 1;
            break;
        }
    }

    return check;    
}