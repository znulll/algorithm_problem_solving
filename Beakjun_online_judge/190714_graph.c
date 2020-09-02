/* 190714 백준-그래프이론-그래프 문제 */

#include <stdio.h>

int VERTEX = 0;
int VERTEX_EDGE[50] = {0,};
int VISIT_VERTEX[50] = {0,};
int EDGE[50][50] = {0,};

void INPUT();
int SOLVE();
int getMaxindex();
void DFS(int vertex, int cnt);
int getVisit();

int main(void){
    int ans;
    
    INPUT();
    ans = SOLVE();
    printf("%d", ans);

    return 0;
}

int SOLVE(){
    int solve = -1, temp = 0;
    int i;
    int maxNode;
    int check = 0;
    for (i=0; i < VERTEX; i++){
        // 방문배열 초기화
        VISIT_VERTEX = {0,};    
        // 간선이 많은 노드 
        maxNode = getMaxindex();
        
        // 현재 상태에 대해서 부터 DFS
        DFS(maxNode, 0);
        temp = getVisit();

        // DFS 결과, 모든 노드 개수만큼 방문하면 탈출
        if(temp == VERTEX){
            check = 1;
            solve = i;
            break;
        }
    }

    return solve; 
}

void INPUT(){
    int i, j;
    char temp;

    scanf("%d", &VERTEX);
    for(i=0; i<VERTEX; i++){
        for(j=0; j<VERTEX; j++){
            scanf("%c", &temp);
            if (temp == 'N'){
                EDGE[i][j] = 0;
            }
            else if (temp == 'Y'){
                EDGE[i][j] = 1;
                VERTEX_EDGE[i] += 1;
            }
            
        }
    }
}

int getMaxindex(){
    int index = 0;
    int max = 0;
    int i;
    for(i=0; i<VERTEX; i++){
        if(VERTEX_EDGE[i] > max){
            index = i;
        }
    }
    return index;
}

void DFS(int vertex, int cnt){
    int i;

    if(VERTEX_EDGE[vertex] == 0 || VISIT_VERTEX[vertex] == 1){
        return;
    }
    else if(VISIT_VERTEX[vertex] == 0 && VERTEX_EDGE[vertex] != 0){
        VISIT_VERTEX[vertex] = 1;
        for(i=0; i<VERTEX; i++){
            if(EDGE[vertex][i] == 1){
                DFS(i, cnt + 1);
            }
        }
    }
    return;
}

int getVisit(){
    int visit = 0;
    int i;
    for(i=0; i<VERTEX; i++){
        if(VISIT_VERTEX[i] == 1){
            visit++;
        }
    }

    return visit;
}