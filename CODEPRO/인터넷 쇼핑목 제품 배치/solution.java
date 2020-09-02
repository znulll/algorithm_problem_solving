import java.util.Scanner;

public class Main {

	int N;     // ��ǰ�� ����
	int[] ID;  // ���̵�
	int[] S;   // �Ǹż���
	int[] R;   // ��ȸȸ��
	
	void inputData() {

		int i;

		Scanner sc = new Scanner(System.in);
		
		// �Է� �б�
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

	// �� ��ġ�� ���� ��ȯ�ϴ� �Լ�
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
	
	// ��ȣ�� ������ �����ϰ� ����� ����ϴ� �Լ�
	void Solve()
	{
		int i, j;
		
		// ��ȣ�� ������ ����
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

		// ��� ���
		for (i = 0; i < N; i++) {
			System.out.printf("%d ", ID[i]);
		}		
	}
	
	public static void main(String[] args) {
		Main m = new Main();
		
		m.inputData();  // �Է� �Լ�
		m.Solve();      // ���� Ǯ��
	}
}
