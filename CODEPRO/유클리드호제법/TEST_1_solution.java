import java.util.Scanner;

public class Main {

	// �ۼ��ؾ� �� �Լ�
	static int GCD(int m, int n)	{
		return (n!=0) ? GCD(n, m%n) : m;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// �Է� �޴� �κ�
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		// ū���� ���� m�� ����
		if (m < n)
		{
			int temp = m; m = n; n = temp;
		}

		int sol = GCD(m,n);

		System.out.println(sol);

	}

}
