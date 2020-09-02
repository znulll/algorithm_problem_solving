#include <stdio.h>

int N;	// 필터의 수
int SELECT[11];
int R[11]; // 반사의 정도
int P[11]; // 투과의 정도
int MIN, Optimal_Depth;

void InputData(void){
	int i;
	scanf("%d", &N);
	for(i=1; i<=N; i++){
        scanf("%d %d", &R[i], &P[i]);
        SELECT[i] = 1;
    }
}

int summation(int a, int b){ int sum = a + b; return sum; }
int multiplication(int a, int b){ int mul = a*b; return mul; }
int substraction(int a, int b){
    int dif;
    if(a>b) dif = a-b;
    else dif = b-a;
    return dif;
}

int getIterDif(){
    int i, res = 0;
    int init_sum = 0, init_mul = 1;
    for(i=1; i<=N; i++){
        if(SELECT[i] == 1){
            init_mul = multiplication(init_mul, R[i]);
            init_sum = summation(init_sum, P[i]);
        }
    }
    res = substraction(init_mul, init_sum);
    return res;
}

void print(){
    int i;
    printf("{");
    for(i=1; i<=N; i++){
        printf("%d ", SELECT[i]);
    }
    print("}\n");
}

void DFS(int depth){
    if(depth == N) return;
    int i;
    int difference = getIterDif();
    if(MIN >= difference) {
        MIN = difference;
        Optimal_Depth = depth;
    }

    for(i=1; i<=N; i++){
        if(SELECT[i] == 1){
            SELECT[i] = 0;
            DFS(depth+1);
            SELECT[i] = 1;
        }
    }
}

int main(){
	int ans = -1;
	InputData(); // 입력함수
    MIN = getIterDif();
    Optimal_Depth = 0;
	DFS(0);
    ans = Optimal_Depth;
	printf("%d\n", ans);//출력 
	return 0;
}

