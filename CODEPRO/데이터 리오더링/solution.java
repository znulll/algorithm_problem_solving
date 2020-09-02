import java.util.Scanner;

public class Main {

	// 작성할 함수
	static int Make_Data(int rcv){
		int sol = 0;
		int val = 0;
		
		val = rcv>>26 & 0x3F;
		sol |= val<<18;

		val = rcv>>23 & 0x7;
		sol |= val<<13;

		val = rcv>>19 & 0xF;
		sol |= val<<0;

		val = rcv>>15 & 0xF;
		sol |= val<<24;

		val = rcv>>11 & 0xF;
		sol |= val<<4;

		val = rcv>>9 & 0x3;
		sol |= val<<16;
		
		val = rcv>>4 & 0x1F;
		sol |= val<<8;
		
		val = rcv & 0xF;
		sol |= val<<28;
		
		return sol;
	}

	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 입력 받는 부분
		long temp = Long.parseLong(sc.next(), 16);
		int rcv = (int)temp;
		
		int sol = Make_Data(rcv);

		System.out.format("%X%n"  , sol);

	}

}
