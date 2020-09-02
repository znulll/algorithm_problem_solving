import java.util.Scanner;

public class Main {

	// 작성해야 할 함수
	static int GCD(int m, int n)	{
		return (n!=0) ? GCD(n, m%n) : m;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 입력 받는 부분
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		// 큰수를 변수 m에 대입
		if (m < n)
		{
			int temp = m; m = n; n = temp;
		}

		int sol = GCD(m,n);

		System.out.println(sol);

	}

}
