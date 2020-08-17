package assignments;
import java.util.*;

public class Dist {
	static double calc(double x1, double y1, double x2, double y2) {
		double dist=((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
		dist=Math.sqrt(dist);
		return dist;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter x1: ");
		double x1=sc.nextDouble();
		System.out.println("Enter y1: ");
		double y1=sc.nextDouble();
		System.out.println("Enter x2: ");
		double x2=sc.nextDouble();
		System.out.println("Enter y2: ");
		double y2=sc.nextDouble();
		
		double dist=calc(x1,y1,x2,y2);
		System.out.println("The distance between the points is "+ dist);
		
		sc.close();
		
	}

}
