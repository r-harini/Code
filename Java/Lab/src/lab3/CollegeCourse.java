package lab3;

public class CollegeCourse {
	String dept="";
	int cnum,cred;
	float cfee=0;
	
	CollegeCourse(){
		this.cnum=0;
		this.cred=0;
		this.dept="";
		this.cfee=0;
	}
	
	CollegeCourse(int num, int credits, String d){
		this.cnum=num;
		this.cred=credits;
		this.dept=d;
		this.cfee=credits*120;
	}
	
	public void display() {
		System.out.println("Course number: "+this.cnum);
		System.out.println("Credits: "+ this.cred);
		System.out.println("Department: "+this.dept);
		System.out.println("Course Fee: "+ this.cfee);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CollegeCourse c=new CollegeCourse(1301, 3, "CSE");
		c.display();
	}

}
