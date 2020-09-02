/* 190705 백준-DFS-미친로봇 */

#include <stdio.h>

void INPUT();
void DFS(int x, int y, double prob, int nPATH);

double simple_prob = 0.;
double complex_prob = 0.;
int LENGTH = 0;
int ARR_PATH[29][29] = {0, };
double p_direction[4] = {0., };     // 동, 서, 남, 북
int EWSNcoordinate[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}} ;

int main(void){
    INPUT();
 
    // 시작점을 좌표(14, 14)로 offset, 확률 1.0으로 0번째부터 DFS로 복잡할 확률 계산
    DFS(14, 14, 1., 0);
    
    // 단순할 확률 계산
    printf("%.10lf", simple_prob);
    
    return 0;
}

void INPUT(){
    int i;
    double temp;

    scanf("%d", &LENGTH);
    for(i=0; i<4; i++){
        scanf("%lf", &temp);
        temp /= 100;
        p_direction[i] = temp;
    }

    return;
}

void DFS(int x, int y, double prob, int nPATH){
    int dx, dy;
    int i;

    // 확률이 0이면 계산 필요 x
    if(prob == 0){
        return;
    }

    // [탈출] Complex case : 왔던 곳이면 리턴 
    if(ARR_PATH[x][y] == 1){     
        return;
    }

    // [탈출] Simple case : 마지막 지점이고, 방문하지 않은 경우 확률에 더하고 리턴
    if(ARR_PATH[x][y] == 0 && nPATH == LENGTH){
        simple_prob += prob;
        return;
    }

    // 왔던 곳이 아니면 체크 후, 그 위치에서 동서남북 경로 가보기
    ARR_PATH[x][y] = 1;
    for(i=0; i<4; i++){ 
        dx = EWSNcoordinate[i][0];
        dy = EWSNcoordinate[i][1];
        DFS(x + dx, y + dy, prob * p_direction[i], nPATH+1);
    }

    // 동서남북 경로 탐색 후, 왔던 곳 체크 해제
    ARR_PATH[x][y] = 0;

    return; 
}