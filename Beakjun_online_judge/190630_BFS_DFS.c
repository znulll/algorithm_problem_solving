/* 190630 백준-BFS-BFS와DFS */

#include <stdio.h>
#include <stdlib.h>

int Graph[1001][1001] = {0, };
int BFSvisit[1001] = {0, };
int DFSvisit[1001] = {0, };
int queue[1001];
int N, M, Start;

void INPUT();
void BFS(int v, int N);
void DFS(int v, int N);

int main(void){
    INPUT();
    DFS(Start, N);
    printf("\n");
    BFS(Start, N);

    return 0;
}


void INPUT(){
    int i, x, y;

    scanf("%d%d%d", &N, &M, &Start);
    for(i=0; i<M; i++){
        scanf("%d%d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
}

void BFS(int v, int N){
    int front = 0;
    int rear = 0;
    int pop, i;

    printf("%d ", v);
    queue[0] = v;
    rear++; // rear = 1
    BFSvisit[v]=1;  // check v

    while(front < rear){
        pop = queue[front]; //front = 0
        front++;  //

        for(i=1; i<=N; i++){
            if(Graph[pop][i]==1 && BFSvisit[i]==0){
                printf("%d ", i);
                queue[rear] = i;
                rear++;
                BFSvisit[i]=1;
            }
        }
    }
    return;
}

void DFS(int v, int N){
    int i;
    DFSvisit[v] = 1;
    printf("%d ", v);
    for(i=1; i<=N; i++){
        if(Graph[v][i] == 1 && DFSvisit[i] == 0){
            DFS(i, N);
        }
    }
    return;
}