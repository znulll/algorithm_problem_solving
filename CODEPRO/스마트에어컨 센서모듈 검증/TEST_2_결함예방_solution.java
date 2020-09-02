import java.util.Scanner;

public class Main {
	int N;				//	명령어의 갯수
	int exit_flag = 0; 	// Power OFF 대기 상태를 알려주는 변수 1이 Power OFF 대기상태임
	 
	Scanner s = new Scanner(System.in);
	// 들어온 명령을 리턴해 주는 함수
	int Get_Command()
	{
		return s.nextInt();
	}
	
	void inputData() {
			N = s.nextInt();
	}
	
	void solve() {
		int data =0;
		

		for(int i=0; i<N; i++)
		{
			data = Get_Command();

			if(data !=6 )exit_flag = 0;
			switch(data)
			{
				default:
					System.out.println("Unknown Error");
				case 9:
					System.out.println("Error Code " + data);
					break;
				case 4:	// 스마트 청정냉방 모드
					System.out.println("Sensing Mode Init");
					System.out.println("Temp. Sensing Mode ON");
				case 3:	// 청정제습 모드
					if(data==3)System.out.println("Sensing Mode Init");
					System.out.println("Humidity Sensing Mode ON");
				case 2:	// 공기 청정기 모드
					if(data==2)System.out.println("Sensing Mode Init");
					System.out.println("Air Sensing Mode ON");
					break;
				case 5:
					System.out.println("Wait Power OFF");
					exit_flag = 1;
					break;
				case 6:
					if(exit_flag ==1)
					{
						System.out.println("Power OFF");
					}
					else
					{
						System.out.println("No Operation");
					}
					break;
				case 1:
					System.out.println("Power ON");
					break;
			}
			if((exit_flag == 1)&& (data==6))break;

		}
		System.out.println("Finish");
		s.close();
	}

	public static void main(String[] args) {
		Main m = new Main();

		m.inputData();				//	입력 함수
		m.solve();					//	정답 출력
	}
}
