/* 190804 백준-이분탐색-공유기설치 */

#include <stdio.h>
#include <stdlib.h>

int nHOME;
int nROUTER;
unsigned int arrHOME[20000] = {0, };

void INPUT();
void qSort(int start, int end);
int BSearch(int len, int target);
void Solve();

int main(void){
    INPUT();
    qSort(0, nHOME);
    
    Solve();

    return 0;
}

void INPUT(){
    int i;
    scanf("%d", &nHOME);
    scanf("%d", &nROUTER);
    for(i=0; i<nHOME; i++){
        scanf("%d", &arrHOME[i]);
    }
}

void qSort(int start, int end){
    if(start >= end){
        return; 
    }
    
    int pivot = start;
    int L = pivot + 1; // 왼쪽 출발 지점 
    int R = end; // 오른쪽 출발 지점
    int temp;
    
    while(L <= R){
        // 포인터가 엇갈릴때까지 반복
        while(L <= end && arrHOME[L] <= arrHOME[pivot]){L++;}
        while(R > start && arrHOME[R] >= arrHOME[pivot]){R--;}
        
        if(R > L){
            // 엇갈림
            temp = arrHOME[R];
            arrHOME[R] = arrHOME[pivot];
            arrHOME[pivot] = temp;
        }else{
            // i번째와 j번째를 스왑
            temp = arrHOME[L];
            arrHOME[L] = arrHOME[R];
            arrHOME[R] = temp;
        }
    } 
    
    qSort(start, R - 1);
    qSort(R + 1, end);
}

int BSearch(int len, int target){
    int first = 0;
    int last = len - 1;
    int mid = 0;
 
    while (first <= last){
        mid = (first + last) / 2;
        if (arrHOME[mid] == target){
            return mid;
        }
        else{
            if (arrHOME[mid] > target)
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1;
}

void Solve(){
    int left = 1;                                // 가능한 최소 거리
    int right = arrHOME[nHOME - 1] - arrHOME[0]; // 가능한 최대 거리
    int d = 0;
    int ans = 0;
 
    while (left <= right) {
        int mid = (left + right) / 2; // 기준
        int start = arrHOME[0];
        int cnt = 1;
 
        // 간격(d) 를 기준으로 공유기 설치
        for (int i = 1; i < nHOME; i++) {
            d = arrHOME[i] - start;
            if (mid <= d) {
                ++cnt;
                start = arrHOME[i];
            }
        }
 
        if (cnt >= nROUTER) {
            // 공유기의 수를 줄이자 => 간격 넓히기
            ans = mid;
            left = mid + 1;
        } else {
            // 공유기가 더 설치되어야한다. => 간격 좁히기
            right = mid - 1;
        }
    }

    printf("%d", ans);
}
