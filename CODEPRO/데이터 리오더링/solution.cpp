#include <iostream>
using namespace std;

unsigned int Make_Data(unsigned int rcv);

// 작성할 함수
unsigned int Make_Data(unsigned int rcv)
{
	unsigned int sol = 0;
	unsigned int val = 0;
	
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
int main(void)
{
	unsigned int rcv=0,sol;
	
	// 입력 받는 부분
	cin >> hex >> uppercase >> rcv;
	
	sol = Make_Data(rcv);

	cout << hex << uppercase << sol;
}