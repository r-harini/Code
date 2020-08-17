package cat1;

import java.util.*;

interface Runner{
	public void run();
	
}

class Machine implements Runner{
	public void run() {
		System.out.println("Machine is running");
	}
}

class Athlete implements Runner{
	public void run() {
		System.out.println("Athlete is running a race");
	}
}

public class DemoRunners {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Machine m=new Machine();
		m.run();
		Athlete a=new Athlete();
		a.run();
	}

}
