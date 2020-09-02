

import dcs.ControlSystem;
import dcs.FireSensor;
import dcs.Position;
import dcs.TestUtils;

// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 LedTest class에 테스트 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * Position.java
 * (y, x) 위치 정보를 표현하는 자료구조 
 *
public class Position {
	public Position(int y, int x) { // NOTE: (y,x) 순 이라는 점에 유의
		...
	}
	public int x = 0;
	public int y = 0;
	... (적절한 equals가 구현되어 있음)
}
...

/**
 * FireSensor.java
 * 화재 감지 센서 인터페이스
 *
public interface FireSensor {

	**
	 * 현재 화재를 감지한 센서의 위치 값을 반환
	 * @return Position 타입의 좌표.
	 *
	Position getSensorPosition();

}
...
*/

/**
 * ControlSystem.java
 * 드론 관제 시스템 (테스트 대상)
 * 
public class ControlSystem {
	...
	private FireSensor sensor;

	public ControlSystem(FireSensor sensor) {
		this.sensor = sensor;
		...
		// 드론 위치 초기화
	}
	
	/**
	 * 화재가 발생한 위치를 얻어와서 현재 드론과의 위치를 계산하여 가장 가까운 드론을 선택하는 함수 (테스트 대상)
	 * 다음 위치 계산을 위해 선택된 드론의 위치를 저장해둔다. (선택된 드론이 해당 좌표로 이동함을 가정)
	 * @return 화재가 발생한 곳과 가장 가까운 드론의 번호. 1 혹은 2
	 *
	public int selectDrone() {
		Position dpos1 = drone[0].getPosition();
		Position dpos2 = drone[1].getPosition();
		Position issued = sensor.getSensorPosition();
		
		int dx = issued.x - currentDrone1.x;
		int dy = issued.y - currentDrone1.y;
		int dist1 = (dx * dx) + (dy * dy);

		dx = issued.x - currentDrone2.x;
		dy = issued.y - currentDrone2.y;
		int dist2 = (dx * dx) + (dy * dy);
		
		...
		// 선택된 드론의 위치를 저장
		...
		
		return (dist2>=dist1) ? 1 : 2;
	}

}
*/


public class DroneControlSystemTest {
	
	// 문제1.	
	// 정답 배열의 Format - 화재감지 센서번호가 주어진 순서대로 감지 되었을 때, 출동하는 드론의 번호를 순서대로 기술
	// 예를 들어, 드론이 1, 1, 2, 2, 1 순으로 출동한다면 { 1, 1, 2, 2, 1 }로 기록
	public int[] expectedResult_1_1 = {2, 2, 2, 1, 1};
	public int[] expectedResult_1_2 = {1, 2, 2, 1, 1};
	
	// 문제 2.
	// 각 문제에 해당하는 TC를 설계
	// TC배열의 Format : 주어진 순서대로 드론이 현장에 방문을 하기 위해 감지 되야 하는 화재센서의 번호를 순서대로 기술
	// 예) 2, 2, 1, 2, 2번 순으로 드론이 현장에 방문하기 위해서는 1,2,3,4,5순으로 센서가 감지되어야 하므로 {1, 2, 3, 4, 5} 기입
	public int[] testInput_example = {1, 2, 3, 4, 5};
	
	public int[] testInput_2_1 = {3, 7, 4, 2, 1};//{2, 1, 4, 7, 3};
	public int[] testInput_2_2 = {5, 1, 6, 2, 4};
	public int[] testInput_2_3 = {3, 7, 1, 5, 4};
	public int[] testInput_2_4 = {3, 5, 1, 7, 2};

	
	// 문제 3. 테스트 코드 작성
	
	public void test_3_1() {
		// TODO: 항목 3-1. 
		// 화재 위치가 센서 1, 7, 2, 3, 5 순으로 감지되는 상황을 재현하는 테스트 코드
		FireSensor sensor = new FireSensor() {
			Position[] fakeSensors = { 
				new Position(1, 10), 
				new Position(8, 2),
				new Position(2, 6),
				new Position(4, 1),
				new Position(6, 10)
			};
			int count = 0;
 
			@Override
			public Position getSensorPosition() {
				// TODO Auto-generated method stub
				return fakeSensors[count++];
			}
			
		};
		ControlSystem dcs = new ControlSystem(sensor);
		
		dcs.selectDrone();
		dcs.selectDrone();
		dcs.selectDrone();
		dcs.selectDrone();
		dcs.selectDrone();
	}

	public void test_3_2() {
		// TODO: 항목 3-2. 
		// 화재 위치가 센서 3, 1, 4, 6, 2 순으로 감지되는 상황을 재현하는 테스트 코드
		FireSensor sensor = new FireSensor() {
			Position[] fakeSensors = { 
				new Position(4, 1),
				new Position(1, 10), 
				new Position(5, 5),
				new Position(7, 8),
				new Position(2, 6),
				
			};
			int count = 0;
 
			@Override
			public Position getSensorPosition() {
				// TODO Auto-generated method stub
				return fakeSensors[count++];
			}
			
		};
		ControlSystem dcs = new ControlSystem(sensor);
		
		dcs.selectDrone();
		dcs.selectDrone();
		dcs.selectDrone();
		dcs.selectDrone();
		dcs.selectDrone();
	}
	
	
	// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
	// main 함수의 코드는 채점과 관련이 없다.
	public static void main(String[] args) {
		DroneControlSystemTest test = new DroneControlSystemTest();
		TestUtils.printTestResult("example", test.testInput_example);
		TestUtils.printTestResult("2-1", test.testInput_2_1);
		TestUtils.printTestResult("2-2", test.testInput_2_2);
		TestUtils.printTestResult("2-3", test.testInput_2_3);
		TestUtils.printTestResult("2-4", test.testInput_2_4);
	}


}


