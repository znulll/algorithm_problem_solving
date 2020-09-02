#include <stdio.h>

int N; //명령의 갯수
int exit_flag = 0; // Power OFF 대기 상태를 알려주는 변수 1이 Power OFF 대기상태임

// 들어온 명령을 리턴해 주는 함수
int Get_Command(void)
{
	int data;
	scanf("%d",&data);
	return data;
}

int main(void)
{
	int data, i;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++)
	{
		data = Get_Command();
		if(data !=6 )exit_flag = 0;
		switch(data)
		{
			default:	
				printf("Unknown Error\n");
				printf("Error Code %d\n", data);
				break;
			case 9:
				printf("Error Code %d\n", data);
				break;
			case 4:
				printf("Sensing Mode Init\n");
				printf("Temp. Sensing Mode ON\n");
				printf("Humidity Sensing Mode ON\n");
				printf("Air Sensing Mode ON\n");
				break;
			case 3:	
				printf("Sensing Mode Init\n");
				printf("Humidity Sensing Mode ON\n");
				printf("Air Sensing Mode ON\n");
				break;
			case 2:	
				printf("Sensing Mode Init\n");
				printf("Air Sensing Mode ON\n");
				break;
			case 5:
				printf("Wait Power OFF\n");
				exit_flag = 1;
				break;
			case 6:
				if(exit_flag ==1)
				{
					i = 30;
					printf("Power OFF\n");
					break;
				}
				else
				{
					printf("No Operation\n");
					break;
				}
			case 1:
				printf("Power ON\n");
				break;
				
		}
	}
	printf("Finish\n");
	return 0;
}
