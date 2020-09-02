#include <stdio.h>

int N;//송수신 안테나 수
int H[100000 + 10];//송수신 안테나 높이

// 배열 스택 생성
int stk[100000 + 10];
// stack pointer
int sp;
// 스택에 저장
void push(int d) { stk[++sp] = d; }
// 제거
void pop() { sp--; }
// 읽기, 제거는 하지 않음
int front() { return stk[sp]; }
// 비었는지 여부
int empty() { return sp == 0; }
// 저장된 개수
int size() { return sp; }

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
        scanf("%d", &H[i]);
        push(H[i]);
    }
}

int solve(int start, int end){
    int res = 0;
    int i,j, temp, highest;

    for(i=start; i<end; i++){
        temp = 0, highest = 0;
        for(j=i+1; j<=end; j++){
            if(highest >= H[i]) break;
            if(H[j] > highest) {
                temp += 1;
                highest = H[j];
            }
        }
        res += temp;
    }

    return res;
}

int stk_solve(){
    int res = 0;
    int idx;
    int start=0, end;
    while(start < N){
        for(idx=start+1; idx<N; idx++){
            if(H[start] <= H[idx]){
                res += solve(start, idx-1);
                start = idx;
                break;
            }
        }
    }
    return res;
}

int stk_solve2(){
    int res =0;
    int i, current;
    int highest = 0;

    while(!empty()){
        current = front();
        pop();
        if(current <= front())
    }
    return res;
}

int main(){
	int ans = -1;
	InputData();//	입력 함수
    // main 함수에서 sp 초기화
    sp = 0;
	ans = stk_solve();
	printf("%d\n", ans);//출력 
	return 0;
}
