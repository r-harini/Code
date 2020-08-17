package assignments;
import java.util.*;

public class Rand {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random rand=new Random();
		//rand.setSeed(1234567890);
		int randnum=rand.nextInt(10)+1;
		Scanner sc=new Scanner(System.in);
		int num=0;
		while (num!=randnum) {
			System.out.println("Enter your guess:");
			num=sc.nextInt();
			if (num<randnum) {
				System.out.println("Too less. Try again!");
			}
			else if (num>randnum) {
				System.out.println("Too high. Try again!");
			}
			else {
				System.out.println("Correct!");
			}
		}
		sc.close();
	}

}
