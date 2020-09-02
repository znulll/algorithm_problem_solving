import java.util.Scanner;

public class Main {

	int N;     // 제품의 개수
	int[] ID;  // 아이디
	int[] S;   // 판매수량
	int[] R;   // 조회회수
	
	void inputData() {

		int i;

		Scanner sc = new Scanner(System.in);
		
		// 입력 읽기
		N = sc.nextInt();
		ID = new int [N + 10];
		S = new int [N + 10];
		R = new int [N + 10];

		for (i = 0; i < N; i++) {
			ID[i] = sc.nextInt();
			S[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}

		sc.close();
	}

	// 두 위치의 값을 교환하는 함수
	void swap(int x1, int x2)
	{
		int temp;

		temp = ID[x1];
		ID[x1] = ID[x2];
		ID[x2] = temp;

		temp = S[x1];
		S[x1] = S[x2];
		S[x2] = temp;

		temp = R[x1];
		R[x1] = R[x2];
		R[x2] = temp;
	}
	
	// 선호도 순으로 정렬하고 결과를 출력하는 함수
	void Solve()
	{
		int i, j;
		
		// 선호도 순으로 정렬
		for (i = 0; i < N - 1; i++) {
			for (j = i + 1; j < N; j++) {
				if (S[i] < S[j]) {
					swap(i, j);
				}
				else if (S[i] == S[j]) {
					if (R[i] < R[j]) {
						swap(i, j);
					}
					else if (R[i] == R[j]) {
						if (ID[i] < ID[j]) {
							swap(i, j);
						}
					}
				}
			}
		}

		// 결과 출력
		for (i = 0; i < N; i++) {
			System.out.printf("%d ", ID[i]);
		}		
	}
	
	public static void main(String[] args) {
		Main m = new Main();
		
		m.inputData();  // 입력 함수
		m.Solve();      // 문제 풀이
	}
}
