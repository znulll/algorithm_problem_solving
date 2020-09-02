/* 190721 백준-그래프알고리즘-섬의개수 */

#include <stdio.h>

int ax[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int ay[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int GROUND = 0;
int W, H;
int MAP[50][50] = {0, };

void INPUT();
void SEARCH();
void DFS(int x, int y);

int main(void){
    while(1){
        INPUT();
        if(W==0 && H==0){
            break;
        }
        SEARCH();
        printf("%d\n", GROUND);

        GROUND = 0;
    }

    return 0;
}

void INPUT(){
    int x, y;
    scanf("%d", &W);
    scanf("%d", &H);
    for(x=0; x<H; x++){
        for(y=0; y<W; y++){
            scanf("%d", &MAP[x][y]);
            // printf("%d ", MAP[x][y]);
        }
        // printf("\n");
    }
}

void SEARCH(){
    int x, y;
    for(x=0; x<H; x++){
        for(y=0; y<W; y++){
            if(MAP[x][y] > 0){
                GROUND++;
                DFS(x, y);
            }
        }
    }

    return;
}

void DFS(int x, int y){
    int i;
    int dx, dy;

    if(MAP[x][y] == 0){
        return;
    }
    else{
        MAP[x][y] = 0;  
    }
        
    for(i=0; i<8; i++){
        dx = x + ax[i], dy = y + ay[i];

        // MAP 벗어나는 경우 리턴
        if(dx < 0 || dx > H-1 || dy < 0 || dy > W-1){continue;}

        // 주변이 육지인 경우 DFS
        if(MAP[dx][dy] > 0){DFS(dx, dy);}
    }

    return;
}
