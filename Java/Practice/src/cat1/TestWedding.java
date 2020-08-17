package cat1;
import java.util.Date;

class Person {
	String first;
	String last;
	String d;
	
	Person(String f, String l, String d){
		this.first=f;
		this.last=l;
		this.d=d;
		
	}
	
	public String toString() {
		return first+" "+last+" born on "+d;
	}
	
}


class Couple{
	Person p1;
	Person p2;
	
	Couple(Person u, Person v){
		this.p1=u;
		this.p2=v;
	}
	
	public String toString() {
		return p1+" and "+ p2;
	}
	
}


class Wedding{
	String w;
	Couple c;
	String location;
	
	Wedding(String d, Couple c, String loc){
		this.w=d;
		this.c=c;
		this.location=loc;
	}
	
	public String toString() {
		return this.c+" are getting married on "+w+" in "+location;
	}
}


public class TestWedding {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		Person p1=new Person("Harry", "Potter", "31/7/2000");
		Person p2=new Person("Ginny", "Weasley", "23/5/2003");
		Couple c=new Couple(p1,p2);
		Wedding w=new Wedding("1/1/2020", c, "Paris");
		System.out.println(w);
	*/
		int[] arr=new int[10];
		for (int i=0;i<10;i++) {
			arr[i]=i;
			//System.out.println(i);
		}
		//System.out.println(arr.length);
		int[] arr2=arr;
		for (int i=0;i<10;i++) {
			System.out.println(arr2[i]);
		}
	}

}
