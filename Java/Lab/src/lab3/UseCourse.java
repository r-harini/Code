package lab3;
import java.util.*;

public class UseCourse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		Scanner sc2=new Scanner(System.in);
		int option=1;
		System.out.println("Press 1 to enter a course and 0 to exit");
		option=sc.nextInt();
		while (option==1) {
			
			System.out.println("Enter the course department:");
			String c=sc2.next();
			System.out.println("Enter the course num: ");
			int cnum=sc2.nextInt();
			System.out.println("Enter the number of credits: ");
			int creds=sc2.nextInt();
			if (c.equals("BIO") || c.equals("CHM") || c.equals("CIS") || c.equals("PHY")) {
				LabCourse l=new LabCourse(cnum,creds,c);
				l.display();
			}
			else {
				CollegeCourse cc=new CollegeCourse(cnum,creds,c);
				cc.display();
			}		
			System.out.println("Press 1 to enter a course and 0 to exit");
			option=sc.nextInt();
		}
		sc.close();
		sc2.close();
		
	}

}
