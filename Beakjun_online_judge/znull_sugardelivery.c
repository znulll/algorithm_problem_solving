/* 190519 백준-2839번-수학-설탕배달 */

#include <stdio.h>

int check (int n, int r);

int main (void) {
    int N;
    int n, r;
    scanf("%d", &N);
    
    // N = 5*n + r
    n = N/5;    // n: N을 5로 나눈 몫
    r = N%5;    // r: N을 5로 나눈 나머지
    
    printf("%d\n", check(n, r));
    
    return 0;
}

int check (int n, int r){
    int ans;
    
    if(r%3 != 0){
        if(n > 0){
            n = n - 1;
            r = r + 5;
            ans = check(n , r);
        }
        else{
            ans = -1;
        }
    }
    else{
        ans = n + (r/3);    
    }

    return ans;
}
