#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int N;//테스트 케이스 수
int B;//진법
char S[110];//첫 번째 정수
char D[110];//두 번째 정수
char O[110];

void InputData(){
	scanf("%d %s %s", &B, S, D);
}

// int char_to_decimal(char character){
//     int ans;
//     ans = atoi(character[0]) - 48;
//     return character;
// }

int decimal_to_char(int decimal){
    char charicter;
    if(decimal > 9) charicter = (char)(decimal + 55);
    return decimal;
}

// int check_length(char* array){
//     int length;
//     int idx = 0;

//     while(array[idx] != '\0'){
//         idx++;
//     }

//     length = idx +1;

//     return length;
// }

void OutputData(int Total, int sign){
    int std_num = B;
    int copy_Total = Total;
    int real_std = 0;
    int i = 0, j = 0;
    char s;

    while(copy_Total/std_num > 0){
        if(copy_Totalstd_num > 0){
            copy_Total = copy_Total%std_num;
            i++;
        }
        printf("check : %d\n", copy_Total);
        printf("std num %d\n", std_num);
    }
    printf("std_num : %d\n", std_num);
    printf("copy_Total : %d\n", copy_Total);
    printf("Total : %d\n", Total);

    real_std = i;

    if(sign == 1){printf("-");    j++;}

    for(i=real_std; i>-1; i--){
        O[j] = (char)(Total/std_num + 48);
        printf("%c", O[j]);
    }
    printf("\n");

    return;
}

// 'A' = 65
void solve(){
	int std_num = B;    // 진법
	int s, d, int_s, int_d, tmp_s, tmp_d;   //
    
	int max_s = strlen(S);
    int max_d = strlen(D);
    // printf("strlen(S) : %d\n", max_s);
    // printf("strlen(D) : %d\n", max_d);

    int s_start_idx = 0, d_start_idx = 0;
    int s_end_idx = max_s, d_end_idx = max_d;

    int decimal_Total = 0;
    int sign = 0;

    if(S[0] == '-'){s_start_idx++;  s_end_idx++;}
    if(D[0] == '-'){d_start_idx++;  d_end_idx++;}
    if( (S[0] == '-' && D[0] != '-') || (S[0] != '-' && D[0] == '-') ){sign = 1;}
    // printf("sign : %d\n", sign);

	for(s=s_start_idx; s<s_end_idx; s++){
        int_s = (int)S[s] - 48;          // S[s]번째 숫자(문자)를 10진수로 변환
        tmp_s = pow(B, s_end_idx-s-1) * int_s;        // B진수의 max_s-s자리수의 S[s]만큼의 수를 10진수로 계산

        for(d=d_start_idx; d<d_end_idx; d++){
            int_d = (int)D[d] - 48;      // D[d]번째 숫자(문자)를 10진수로 변환
            printf("int_d : %d\n", int_d);
            tmp_d = pow(B, d_end_idx-d-1) * int_d;    // B진수의 max_d-d자리수의 D[d]만큼의 수를 10진수로 계산

            decimal_Total += (tmp_s * tmp_d);   // 10진수로 변환한 두 수의 곱을 총합에 더함 
            // printf("progress total : %d", decimal_Total);
        }
    }
    printf("decimal_Total : %d\n", decimal_Total);
    OutputData(decimal_Total, sign);

	return;
}

int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
        // 배열 초기화
        S[0] = '\0';
        D[0] = '\0';

        // 입력 함수
		InputData();//입력 함수

		solve();
        // printf("point\n");
	}

	return 0;
}
	