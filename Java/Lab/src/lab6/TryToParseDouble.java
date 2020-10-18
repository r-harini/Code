package lab6;
import java.util.*;

public class TryToParseDouble {

	public static void main(String[] args) {
		Scanner ob = new Scanner(System.in);
		double num;
		try {
			System.out.println("Enter the String Value of Double type : ");
			String a = ob.next();
			ob.close();
			num = Double.parseDouble(a);
		} catch(NumberFormatException e) {
			num = 0;
			System.out.println("The String Cannot be Converted to Double");
		}
		System.out.println("Double Value is : " + num);
	}
}
