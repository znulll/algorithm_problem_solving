#include <stdio.h>
#include "./lib/drone.h"


POS sensorTable[8] = { {0,0}, {1,10},{2,6},{4,1},{5,5},{6,10},{7,8},{8,2} };

/**
 * drone.h에는 대략적으로 아래와 같이 구현된 함수의 정의가 있다.
 * 구현 참고용이므로 본 주석을 풀어서 아래 코드를 사용해서는 안된다. (drone.h에 포함된 내용임)
 * 아래 주석을 해제하여 사용하는 경우 정상적으로 동작하지 않는다.
 */

 /**
 * (y, z) 좌표를 표현하는 자료구조
 *
typedef struct pos {
	int y;
	int x;
} POS;
/**
 * 현재 화재를 감지한 센서의 위치 값을 반환하는 인터페이스
 * @return POS 타입의 (y, x) 좌표. 예를 들어, 1번 센서에서 화재를 감지한 경우 {1, 10}을 반환
 *
POS getSensorPosition(void);

/**
 * 초기화 함수
 *
void initialize(void)
{
	...
	currentDrone1Position.x = 0;
	currentDrone1Position.y = 0;
	currentDrone2Position.x = 10;
	currentDrone2Position.y = 10;
	...
}

/**
 * 화재가 발생한 위치를 얻어와서 현재 드론과의 위치를 계산하여 가장 가까운 드론을 선택하는 함수 (테스트 대상)
 * 다음 위치 계산을 위해 선택된 드론의 위치를 저장해둔다. (선택된 드론이 해당 좌표로 이동함을 가정)
 * @return 화재가 발생한 곳과 가장 가까운 드론의 번호. 1 혹은 2
 *
int selectDrone(void)
{
	POS spos = getSensorPosition();
	int dist1 = 0, dist2 = 0;
	int dx = currentDrone1Position.x - spos.x;
	int dy = currentDrone1Position.y - spos.y;
	dist1 = dx*dx + dy*dy;

	dx = currentDrone2Position.x - spos.x;
	dy = currentDrone2Position.y - spos.y;
	dist2 = dx*dx + dy*dy;

	if (dist2 >= dist1)
	{
		currentDrone1Position = spos;
		return 1;
	}
	else
	{
		currentDrone2Position = spos;
		return 2;
	}
}
*/


// 문제1.	
// 정답 배열의 Format - 화재감지 센서번호가 주어진 순서대로 감지 되었을 때, 출동하는 드론의 번호를 순서대로 기술
// 예를 들어, 드론이 1, 1, 2, 2, 1 순으로 출동한다면 { 1, 1, 2, 2, 1 }로 기록

int expectedResult_1_1[5] = { 2, 2, 2, 1, 1 };  //TODO: 문제 (1-1) 1, 2, 5, 3, 7 순으로 센서 감지
int expectedResult_1_2[5] = { 1, 2, 2, 1, 1 };  //TODO: 문제 (1-2) 7, 6, 5, 4, 3 순으로 센서 감지

// 문제 2.
// 각 문제에 해당하는 TC를 설계
// TC배열의 Format : 주어진 순서대로 드론이 현장에 방문을 하기 위해 감지 되야 하는 화재센서의 번호를 순서대로 기술
// 예) 2, 2, 1, 2, 2번 순으로 드론이 현장에 방문하기 위해서는 1,2,3,4,5순으로 센서가 감지되어야함.
// {1, 2, 3, 4, 5} 기입
int testInput_example[5] = { 1, 2, 3, 4, 5 };

int testInput_2_1[5] = { 2, 1, 4, 7, 3 }; //TODO: 문제 (2-1) 1, 1, 1, 1, 1 => 1번 드론만 출동하는 경우
int testInput_2_2[5] = { 5, 1, 6, 2, 4 }; //TODO: 문제 (2-2) 2, 2, 2, 2, 2 => 2번 드론만 출동하는 경우
int testInput_2_3[5] = { 3, 7, 1, 5, 4 }; //TODO: 문제 (2-3) 1, 1, 2, 2, 1 => 1, 2번 병행 출동하는 경우
int testInput_2_4[5] = { 3, 5, 1, 7, 2 }; //TODO: 문제 (2-4) 1, 2, 2, 1, 2 => 1, 2번 병행 출동하는 경우


int* fakePosition;
int count = 0;
// 문제 3. 테스트 코드 작성
POS getSensorPosition(void)
{
	// TODO: 원하는 위치의 화재감지 센서번호를 전달할 수 있도록 fake/stub을 구현하시오.

	return sensorTable[fakePosition[count++]]; // TODO: 필요한 코드로 대체하시오.
}

void test_3_1(void)
{
	// TODO: 항목 3-1. 
	// 화재 위치가 센서 1, 7, 2, 3, 5 순으로 감지되는 상황을 재현하는 테스트 코드
	int sensorNumbers[] = { 1, 7, 2, 3, 5 };
	count = 0;
	fakePosition = sensorNumbers;

	for (int i = 0; i < 5; ++i)
		selectDrone();
	
}

void test_3_2(void)
{
	// TODO: 항목 3-2. 
	// 화재 위치가 센서 3, 1, 4, 6, 2 순으로 감지되는 상황을 재현하는 테스트 코드
	int sensorNumbers[] = { 3, 1, 4, 6, 2 };
	count = 0;
	fakePosition = sensorNumbers;

	for (int i = 0; i < 5; ++i)
		selectDrone();
	
}

// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main(void)
{
	printInputResult("example", testInput_example);
	printInputResult("2-1", testInput_2_1);
	printInputResult("2-2", testInput_2_2);
	printInputResult("2-3", testInput_2_3);
	printInputResult("2-4", testInput_2_4);

	return 0;
}
