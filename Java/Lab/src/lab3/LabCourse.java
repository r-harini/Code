package lab3;

public class LabCourse extends CollegeCourse{
	
	LabCourse(int num, int credits, String d){
		super(num,credits,d);
		this.cfee=(credits*120)+50;
	}
	
	public void display() {
		System.out.println("This is a Lab Course");
		System.out.println("Course number: "+this.cnum);
		System.out.println("Credits: "+ this.cred);
		System.out.println("Department: "+this.dept);
		System.out.println("Course Fee: "+ this.cfee);
	}
	
	

}
