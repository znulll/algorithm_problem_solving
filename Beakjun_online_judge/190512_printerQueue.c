/* 190512 백준-큐-프린터큐 문제 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;
  
typedef struct Queue //Queue 구조체 정의
{
    Node *front; //맨 앞(꺼낼 위치)
    Node *rear;  //맨 뒤(보관할 위치)
    int count;   //보관 개수
    int target;  //찾을 위치
}Queue;
 
void InitQueue(Queue *queue);//큐 초기화
int IsEmpty(Queue *queue); //큐가 비었는지 확인
void Enqueue(Queue *queue, int data); //큐에 보관
int Dequeue(Queue *queue); //큐에서 꺼냄

int main(void){
    int num_testCase;
    int i;
    int iteration;
    int check = 0;
    Queue queue;
    scanf("%d", &num_testCase);

    for (i = 1; i <= num_testCase; i++) // test case 개수 동안
    {
        printf("----- Test case %d -----\n", num_testCase);
        iteration = 0;
        int j = 0;
        int count = 0;
        int idx_target = 0;
        int target = 0;
        int max = 0;
        InitQueue(&queue);         // 큐 초기화
        scanf("%d", &count);         // 큐의 노드 개수
        scanf("%d", &idx_target);    // 찾을 노드 넘버

        for(j=0; j<count; j++){    // 우선순위 인큐
            printf("큐 하나 들어가요\n");
            int priority;
            scanf("%d", &priority);
            Enqueue(&queue, priority);
            if(j == idx_target){
                target = priority;
            } 
            if(max < priority){
                max = priority;    
            } 
        }

        while(!IsEmpty(&queue)){    // 큐가 비어있지 않는 동안 반복
            int p;
            for(p=max; p>0; p--){
                printf("현재 max : %d\n", max);
                printf("현재 count : %d\n", count);
                printf("현재 큐 프론트 : %d\n", queue.front->data);
                printf("현재 정답 idx : %d\n", idx_target);
                if(queue.front->data < max){
                    Enqueue(&queue, Dequeue(&queue));
                }
                else if(queue.front->data == max) {
                    iteration++;
                    count -= 1;
                    if(idx_target == 0 && Dequeue(&queue) == target){
                        printf("정답!!!!! : %d\n", iteration);
                        check = 1;
                        break;               
                    }
                    else{
                        printf("큐를 하나 빼요\n");
                        Dequeue(&queue); 
                    }
                }
                idx_target = idx_target - 1;
                if(idx_target < 0){
                    idx_target += count;
                }
            }
            if(max > 0){
                max -= 1;
            }
            else {
                max = 1;
            }

            if(check == 1){
                check = 0;
                while(!IsEmpty(&queue)){
                    Dequeue(&queue);
                }
                break;
            }
        }
    }

    return 0;
}

void InitQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;  //front와 rear를 NULL 설정
    queue->count = 0;                   // 큐 노드 개수 = 0
}
 
int IsEmpty(Queue *queue)
{
    return queue->count == 0;           // 큐 노드 개수가 0인지 체크
}
 
void Enqueue(Queue *queue, int data)
{
    Node *now = (Node *)malloc(sizeof(Node)); // 노드 생성 및 메모리 할당
    now->data = data;                         //데이터 설정
    now->next = NULL;
 
    if (IsEmpty(queue)) // 큐가 비어있을 때
    {
        queue->front = now; //맨 앞을 now로 설정       
    }
    else                // 비어있지 않을 때
    {
        queue->rear->next = now; //맨 뒤의 다음을 now로 설정
    }
    queue->rear = now; //맨 뒤를 now로 설정   
    queue->count++; //보관 개수를 1 증가
}
 
int Dequeue(Queue *queue)
{
    int re = 0;
    Node *now;
    if (IsEmpty(queue))//큐가 비었을 때
    {
        return re;
    }
    now = queue->front;//맨 앞의 노드를 now에 기억
    re = now->data;//반환할 값은 now의 data로 설정
    queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
    free(now);//now 소멸
    queue->count--;//보관 개수를 1 감소
    return re;
}