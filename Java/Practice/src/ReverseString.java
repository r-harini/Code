import java.util.*;


public class ReverseString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="Harini";
		String r="";
		
		/*for (int i=s.length()-1; i>=0; i--) {
			r+=s.charAt(i);
		}
		System.out.println(r);
	*/
		StringBuilder r2=new StringBuilder();
		r2.append(s);
		r2=r2.reverse();
		System.out.println(r2);
	}

}
