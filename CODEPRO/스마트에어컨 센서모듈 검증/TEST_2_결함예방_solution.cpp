#include <iostream>
using namespace std;

int N; //명령의 갯수
int exit_flag = 0; // Power OFF 대기 상태를 알려주는 변수 1이 Power OFF 대기상태임

// 들어온 명령을 리턴해 주는 함수
int Get_Command(void)
{
	int data;
	cin >> data;
	return data;
}

int main(void)
{
	int data, i;
	
	cin >> N;
	
	for(i=0; i<N; i++)
	{
		data = Get_Command();
		
		if(data !=6 )exit_flag = 0;	
		switch(data)
		{
			default:
				cout << "Unknown Error" << endl;
			case 9:
				printf("Error Code %d\n", data);
				break;
			case 4:	// 스마트 청정냉방 모드
				cout << "Sensing Mode Init" << endl;
				cout << "Temp. Sensing Mode ON" << endl;
			case 3:	// 청정제습 모드
				if(data==3)cout << "Sensing Mode Init" << endl;
				cout << "Humidity Sensing Mode ON" << endl;
			case 2:	// 공기 청정기 모드
				if(data==2)cout << "Sensing Mode Init" << endl;
				cout << "Air Sensing Mode ON" << endl;
				break;
			case 5:
				cout << "Wait Power OFF" << endl;
				exit_flag = 1;
				break;
			case 6:
				if(exit_flag ==1)
				{
					cout << "Power OFF" << endl;
				}
				else
				{
					cout << "No Operation" << endl;
				}
				break;
			case 1:
				cout << "Power ON" << endl;
				break;
		}
		if((exit_flag == 1)&& (data==6))break;
	}
	cout << "Finish" << endl;
	return 0;
}
