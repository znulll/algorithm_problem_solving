#include <stdio.h>

int N;//보내려는 물품 개수
int BOX[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
int C[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
int sol[10];//보내는 BOX 개수
int temp[10] = {0,};

void InputData(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < 10; i++){
		scanf("%d", &C[i]);
	}
}
void OutputData(int ans){
	int i;
	printf("%d\n", ans);
	for(i = 0; i < 10; i++){
		printf("%d ", temp[i]);
	}
	printf("\n");
}

int solve(){
	int ans = 0;
	int i;
	int N_temp = N;
	
	for(i=9; i>-1; i--){
		temp[i] = N_temp/BOX[i];
		if(C[i] >= temp[i]){
			C[i] -=temp[i];
		}	
		else{
			temp[i] = C[i];
			C[i] = 0;
		}
		N_temp -= temp[i]*BOX[i];
	}
	
	if(N_temp != 0) {
        printf("debug");
        return 0;
    }
	for(i=0; i<9; i++){
		int check = C[i]/BOX[i+1]; 
		C[i] -= check * BOX[i+1];			// 작은 상자 재고에서 큰 상자 개수만큼 감소
		temp[i] += check * BOX[i+1];	// 제출할 작은 상자에 큰 상자 개수만큼 증가
		C[i+1] += check;							// 큰 상자 재고에서 작은 상자 개수만큼 증가
		temp[i+1] -= check;							// 제출할 큰 상자에 작은 상자 개수만큼 감소
		
		check = C[i]/BOX[i+1]; 
		if(check == 0) ans += temp[i];
	}
	ans += temp[9];
	
	return ans;
}

int main(){
	int ans = -1;

	InputData();//	입력 함수

	ans = solve();

	OutputData(ans);//	출력 함수

	return 0;
}