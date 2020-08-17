package assignments;
import java.util.*;

public class Palindrome {
	public static boolean checkPalindrome(String a) {
		String b="";
		int n = a.length();
        for(int i = n - 1; i >= 0; i--)
        {
            b = b + a.charAt(i);
        }
		if (a.equals(b)) {
			return true;
		}
		else {
			return false;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		boolean b=checkPalindrome(s);
		if (b) {
			System.out.println("String entered is a palindrome");
		}
		else {
			System.out.println("String entered is not a palindrome");
		}
		sc.close();
	}

}
