class Addition extends Thread {
	private int currNum;
	private static int sum;

	public Addition(int currNum) {
		this.currNum = currNum;
	}

	public static synchronized void add(int num) {
		sum = sum + num;
	}

	public void run() {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum = sum + currNum + i;
		}
		add(sum);
	}

	public int getSum() {
		return sum;
	}
}

public class Test {
	public static void main(String[] a) {
		Thread[] threadList = new Thread[10];
		for (int i = 0; i < 10; i++) {
			threadList[i] = new Addition(10 * i + 1);
			threadList[i].start();
		}
		Addition a1 = new Addition(0);
		System.out.println("Sum is : " + a1.getSum());
	}
}
