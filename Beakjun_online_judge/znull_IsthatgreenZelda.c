/* 190726 백준-다익스트라알고리즘-비밀이메일 */

#include <stdio.h>
#include <stdlib.h>

int N;
int MAP[125][125] = {0, };
int VISIT[125][125] = {0, };
int COST = 0;
int ax[4] = {1, 0, -1, 0};
int ay[4] = {0, 1, 0, -1};

void INPUT();
int BFS(int x, int y, int cur_cost);

int main(void){
    int solve;
    while(1){
        INPUT();
        if(N == 0) {
            // free(MAP);
            break;
        }
        else {
            solve = BFS(0, 0, MAP[0][0]);
            printf("%d\n", solve);
            // free(MAP);  
        }
    }
    
    return 0;
}

void INPUT(){
    int i, j;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &MAP[i][j]);
        }
    }
    
    // MAP = (int**) malloc ( sizeof(int*) * N );
    // for(int i=0; i<N; i++){
    //     MAP[i] = (int*) malloc ( sizeof(int) * N );
    //     for(int j=0; j<N; j++){scanf("%d", &MAP[i][j]);}
    // }


    return;
}

int BFS(int x, int y, int cur_cost){
    int i, dx, dy, temp, output;
    int opt_x, opt_y, opt_cost;

    VISIT[x][y] = 1;
    
    if(x == N-1 && y == N-1){
        return cur_cost;
    }
    else{
        temp = MAP[x+ax[0]][y+ay[0]];
        for(i=0; i<4; i++){
            dx = x+ax[i], dy=y+ay[i];
            if(dx<0 || dx>N-1 || dy<0 || dy>N-1 || VISIT[dx][dy] == 1){continue;};
            if(temp > MAP[dx][dy]){opt_x = dx, opt_y = dy, opt_cost = MAP[dx][dy];}
            else{opt_x = x+ax[0], opt_y = y+ay[0], opt_cost = MAP[x+ax[0]][y+ay[0]];}
        }
    }
    output = BFS(opt_x, opt_y, cur_cost + opt_cost);
    return output;
}