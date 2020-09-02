/* 190711 백준-그리디알고리즘-회의실배정 문제 */

#include <stdio.h>

void INPUT();
int getMax(int candidate1, int candidate2);
void quickSort(unsigned int* start, unsigned int* end, unsigned int* take);

int CNT_MEETING = 0;
unsigned int START_TIME[100000] = {0,};
unsigned int END_TIME[100000] =  {0,};
unsigned int TAKE_TIME[100000] = {0,};
int CNT_MAX_ARG = 0;

int main (void) {
    INPUT();

    return;
}

void INPUT(){
    int i;

    scanf("%d", &CNT_MEETING);
    for(i=0; i<CNT_MEETING; i++){
        scanf("%d", &START_TIME[i]);
        scanf("%d", &END_TIME[i]);
        TAKE_TIME[i] = END_TIME[i] - START_TIME[i];
    }
    return;
}

int getMax(int candidate1, int candidate2){
    if(candidate1 > candidate2){
        return candidate1;
    }
    else{
        return candidate2
    }
}

int find_local_optimal(){
    int index;


    return index;
}

void quickSort(unsigned int* start, unsigned int* end, unsigned int* take){
    unsigned int L, R, Pivot;
    L = 0;
    R = CNT_MEETING-1;
    Pivot = (int)R/2;

    return;
}