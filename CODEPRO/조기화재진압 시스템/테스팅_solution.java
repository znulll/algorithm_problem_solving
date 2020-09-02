

import dcs.ControlSystem;
import dcs.FireSensor;
import dcs.Position;
import dcs.TestUtils;

// �׽�Ʈ ����� �Ʒ� �ּ��� ���� �����Ǿ� �ִ�. 
// �ʿ��� ��� �Ʒ� �ּ��� ������ �����Ͽ� LedTest class�� �׽�Ʈ �Է°� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�. 
// NOTE: �׽�Ʈ ��� �ڵ�� ���忡 �̹� ���ԵǾ� ������ �Ʒ� �ּ��� �����Ͽ� ������� ���ÿ�.

/**
 * Position.java
 * (y, x) ��ġ ������ ǥ���ϴ� �ڷᱸ�� 
 *
public class Position {
	public Position(int y, int x) { // NOTE: (y,x) �� �̶�� ���� ����
		...
	}
	public int x = 0;
	public int y = 0;
	... (������ equals�� �����Ǿ� ����)
}
...

/**
 * FireSensor.java
 * ȭ�� ���� ���� �������̽�
 *
public interface FireSensor {

	**
	 * ���� ȭ�縦 ������ ������ ��ġ ���� ��ȯ
	 * @return Position Ÿ���� ��ǥ.
	 *
	Position getSensorPosition();

}
...
*/

/**
 * ControlSystem.java
 * ��� ���� �ý��� (�׽�Ʈ ���)
 * 
public class ControlSystem {
	...
	private FireSensor sensor;

	public ControlSystem(FireSensor sensor) {
		this.sensor = sensor;
		...
		// ��� ��ġ �ʱ�ȭ
	}
	
	/**
	 * ȭ�簡 �߻��� ��ġ�� ���ͼ� ���� ��а��� ��ġ�� ����Ͽ� ���� ����� ����� �����ϴ� �Լ� (�׽�Ʈ ���)
	 * ���� ��ġ ����� ���� ���õ� ����� ��ġ�� �����صд�. (���õ� ����� �ش� ��ǥ�� �̵����� ����)
	 * @return ȭ�簡 �߻��� ���� ���� ����� ����� ��ȣ. 1 Ȥ�� 2
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
		// ���õ� ����� ��ġ�� ����
		...
		
		return (dist2>=dist1) ? 1 : 2;
	}

}
*/


public class DroneControlSystemTest {
	
	// ����1.	
	// ���� �迭�� Format - ȭ�簨�� ������ȣ�� �־��� ������� ���� �Ǿ��� ��, �⵿�ϴ� ����� ��ȣ�� ������� ���
	// ���� ���, ����� 1, 1, 2, 2, 1 ������ �⵿�Ѵٸ� { 1, 1, 2, 2, 1 }�� ���
	public int[] expectedResult_1_1 = {2, 2, 2, 1, 1};
	public int[] expectedResult_1_2 = {1, 2, 2, 1, 1};
	
	// ���� 2.
	// �� ������ �ش��ϴ� TC�� ����
	// TC�迭�� Format : �־��� ������� ����� ���忡 �湮�� �ϱ� ���� ���� �Ǿ� �ϴ� ȭ�缾���� ��ȣ�� ������� ���
	// ��) 2, 2, 1, 2, 2�� ������ ����� ���忡 �湮�ϱ� ���ؼ��� 1,2,3,4,5������ ������ �����Ǿ�� �ϹǷ� {1, 2, 3, 4, 5} ����
	public int[] testInput_example = {1, 2, 3, 4, 5};
	
	public int[] testInput_2_1 = {3, 7, 4, 2, 1};//{2, 1, 4, 7, 3};
	public int[] testInput_2_2 = {5, 1, 6, 2, 4};
	public int[] testInput_2_3 = {3, 7, 1, 5, 4};
	public int[] testInput_2_4 = {3, 5, 1, 7, 2};

	
	// ���� 3. �׽�Ʈ �ڵ� �ۼ�
	
	public void test_3_1() {
		// TODO: �׸� 3-1. 
		// ȭ�� ��ġ�� ���� 1, 7, 2, 3, 5 ������ �����Ǵ� ��Ȳ�� �����ϴ� �׽�Ʈ �ڵ�
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
		// TODO: �׸� 3-2. 
		// ȭ�� ��ġ�� ���� 3, 1, 4, 6, 2 ������ �����Ǵ� ��Ȳ�� �����ϴ� �׽�Ʈ �ڵ�
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
	
	
	// ��������� �����ϰ� ���� �ڵ尡 �ִٸ� �Ʒ� main()�� �ۼ��Ͽ� Ȱ���� �� �ִ�.
	// main �Լ��� �ڵ�� ä���� ������ ����.
	public static void main(String[] args) {
		DroneControlSystemTest test = new DroneControlSystemTest();
		TestUtils.printTestResult("example", test.testInput_example);
		TestUtils.printTestResult("2-1", test.testInput_2_1);
		TestUtils.printTestResult("2-2", test.testInput_2_2);
		TestUtils.printTestResult("2-3", test.testInput_2_3);
		TestUtils.printTestResult("2-4", test.testInput_2_4);
	}


}


