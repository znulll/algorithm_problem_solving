/* 190728 백준-이분탐색-엘리베이터 */

#include <stdio.h>
#include <stdlib.h>

#define TIME_WALK 20;
#define TIME_ELVT 4;
#define TIME_STAY 10;

int N;
int PASSENGER[30];
int GAP_PASSENGER[30];

void INPUT(); 
int getLastTime(int times);
int getMinStop();
void getCloser();

int main(void){
    int cnt_stop;
    INPUT();
    getCloser();

    cnt_stop = getMinStop();
    return 0;
}

void INPUT(){
    int i, j;
    scanf("%d", &N);
    for(i=0; i<N; i++) {scanf("%d", &PASSENGER[i]);}
}

int getLastTime(int times){
    int i;

}

int getMinStop(){
    int i;
    int cnt = 0;
    for(i=0; i<N-1; i++){
        if(GAP_PASSENGER[i]*)
    }

    return cnt;
}

void getCloser(){
    int i;
    GAP_PASSENGER[0] = PASSENGER[1] - PASSENGER[0];
    for(i=1; i<N-1; i++){
        if(abs(PASSENGER[i+1]-PASSENGER[i]) > abs(PASSENGER[i]-PASSENGER[i-1]){
            GAP_PASSENGER[i] = abs(PASSENGER[i]-PASSENGER[i-1]);
        }
        else{
            GAP_PASSENGER[i] = abs(PASSENGER[i+1]-PASSENGER[i]);
        }
    }

    return;
}