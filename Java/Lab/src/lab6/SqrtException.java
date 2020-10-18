package lab6;
import java.util.*;

public class SqrtException {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		double n=sc.nextDouble();
		double s=0;
		sc.close();
		try {
			if (n<0) {
				throw new ArithmeticException();
			}
			s=Math.sqrt(n);
			System.out.println(s);
		}catch (ArithmeticException e) {
			System.out.println("Square root not possible");
		}
		
		
	}

}
