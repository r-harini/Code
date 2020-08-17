package lab4;

public class DemoSubscription {
	
	public static void print(String a, String b, double c) {
		System.out.println("\nThe Details are: ");
		System.out.println("Name: "+a+"\nAddress: "+b+"\nRate: $"+c);
	}

	public static void main(String[] args) {
		NewspaperSubscription a=new PhysicalNewspaperSubscription();
		NewspaperSubscription b=new OnlineNewspaperSubscription();
		NewspaperSubscription c=new PhysicalNewspaperSubscription();
		NewspaperSubscription d=new OnlineNewspaperSubscription();
		
		a.setName("Harini");
		a.setAddress("405, Harlur Road, Bangalore");
		
		b.setName("Arjun");
		b.setAddress("Arjun@gmail.com");
		
		print(a.getName(),a.getAddress(), a.getRate());
		print(b.getName(), b.getAddress(), b.getRate());
		
		System.out.println();
		
		c.setName("Raj");
		c.setAddress("Ann Harbor, Mumbai");
		
		System.out.println();
		
		d.setName("Malathi");
		d.setAddress("malgmail.com");
	}

}
