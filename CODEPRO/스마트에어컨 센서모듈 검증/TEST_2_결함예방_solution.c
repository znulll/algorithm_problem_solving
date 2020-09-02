#include <stdio.h>

int N; //����� ����
int exit_flag = 0; // Power OFF ��� ���¸� �˷��ִ� ���� 1�� Power OFF ��������

// ���� ����� ������ �ִ� �Լ�
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
			case 9:
				printf("Error Code %d\n", data);
				break;
			case 4:	// ����Ʈ û���ù� ���
				printf("Sensing Mode Init\n");
				printf("Temp. Sensing Mode ON\n");
			case 3:	// û������ ���
				if(data==3)printf("Sensing Mode Init\n");
				printf("Humidity Sensing Mode ON\n");
			case 2:	// ���� û���� ���
				if(data==2)printf("Sensing Mode Init\n");
				printf("Air Sensing Mode ON\n");
				break;
			case 5:
				printf("Wait Power OFF\n");
				exit_flag = 1;
				break;
			case 6:
				if(exit_flag ==1)
				{
					printf("Power OFF\n");
				}
				else
				{
					printf("No Operation\n");
				}
				break;
			case 1:
				printf("Power ON\n");
				break;
		}
		if((exit_flag == 1)&& (data==6))break;
	}
	printf("Finish\n");
	return 0;
}
