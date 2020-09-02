/* 190630 백준-BFS-빙산 */

#include <stdio.h>
#include <stdlib.h>

int iceMap[301][301] = {0, };
int iceMelt[301][301] = {0, };
int DFSvisit[301][301] = {0, };
int N, M;
int sumIce;
int nVisit;
int nIce;

void INPUT();
void DFS(int v, int N);
void sumIceberg();
void getMelt(int x, int y);

int main(void){
    int nx, ny;
    int year = 0;
    INPUT();
    sumIceberg();

    // 매년 빙산이 깎이는 경우
    while(sumIce != 0){
        nIce = 0;
        nVisit = 0;
        nx=0, ny=0;
        
        // 빙산 깎기
        int i, j;
        for(i=0; i<N; i++){
            for(j=0; j<M; j++){
                getMelt(i, j);
            }
        }
        for(i=0; i<N; i++){
            for(j=0; j<M; j++){
                if(iceMap[i][j] != 0){
                    if(iceMap[i][j] < iceMelt[i][j]){
                        iceMap[i][j] = 0;
                    }
                    else{
                        iceMap[i][j] = iceMap[i][j] - iceMelt[i][j];
                    }

                    if(iceMap[i][j] != 0){
                        nIce++;
                        nx=i;
                        ny=j;
                    }
                }          
                printf("%d ", iceMap[i][j]);
            }
            printf("\n");
        }

        // 연수+1
        year++;

        // 빙산의 합 계산
        sumIceberg();

        // 그룹 개수 확인
        DFS(nx, ny);

        // 그룹개수 두개 이상이면 loop 탈출
        if(nVisit != nIce){
            break;
        }
    }

    // 빙산이 다 녹은 경우
    if(sumIce == 0){
        year = 0;
    }

    printf("%d", year);

    return 0;
}

void INPUT(){
    int i, j;

    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            scanf("%d ", &iceMap[i][j]);
        }
    }
}

void DFS(int x, int y){
    int i, j;
    DFSvisit[x][y] = 1;
    nVisit++;

    for(i=1; i<N-1; i++){
        for(j=1; j<M-1; j++){
            if(iceMap[i+1][j] != 0 && DFSvisit[i+1][j] == 0){
                DFS(i+1, j);
            }
            else if(iceMap[i-1][j] != 0 && DFSvisit[i-1][j] == 0){
                DFS(i-1, j);
            }
            else if(iceMap[i][j-1] != 0 && DFSvisit[i][j-1] == 0){
                DFS(i, j-1);
            }
            else if(iceMap[i][j+1] != 0 && DFSvisit[i][j+1] == 0){
                DFS(i, j+1);
            }
        }
    }
    return;
}

void getMelt(int x, int y){
    int nZero = 0;
    if(iceMap[x-1][y]==0){
        nZero++;
    }
    else if(iceMap[x][y-1]==0){
        nZero++;
    }
    else if(iceMap[x+1][y]==0){
        nZero++;
    }
    else if(iceMap[x][y+1]==0){
        nZero++;
    }
    
    iceMelt[x][y] = nZero;
}

void sumIceberg(){
    int i, j;
    sumIce = 0;

    for(i=1; i<N-1; i++){
        for(j=1; j<M-1; j++){
            sumIce += iceMap[i][j];
        }
    }
}