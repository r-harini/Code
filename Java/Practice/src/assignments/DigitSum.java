package assignments;
import java.util.*;

public class DigitSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int num=sc.nextInt();
		int sum=0;
		int rem=0;
		while (num!=0) {
			rem=num%10;
			sum=sum+rem;
			num=num/10;
		}
		System.out.println("The sum is "+sum);
		
		sc.close();
	}

}
