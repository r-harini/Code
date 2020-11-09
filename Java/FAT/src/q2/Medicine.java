package q2;

import java.time.LocalDate;
import java.util.*;
import java.text.*;

class ExpiryException extends Exception{
	ExpiryException(){
		System.out.println("Dosage days exceeds expiry date");
	}
}

public class Medicine {
	int ID;
	String med_name;
	double price;
	Date expiry_date;
	int dosage_days;
	
	Medicine(int id, String name, double p, Date d) {
		ID=id;
		med_name=name;
		price=p;
		expiry_date=d;
		
	}
	
	public double billing(int quant) {
		return price*quant;
	}
	
	public void set_dosage(int day) {
		try {
			Date today=new Date();
			long ltime=today.getTime()+(day*24*60*60*1000);
			Date after=new Date(ltime);
			if (expiry_date.before(after)){
				throw new ExpiryException();
			}
			else{
				this.dosage_days=day;
			}
		}catch (ExpiryException e) {
			
		}
	}
	
	public String toString() {
		return "ID: "+this.ID+"\nName: "+this.med_name+"\nPrice: "+this.price+"\nExpiry Date:"+this.expiry_date+"\n Dosage Days: "+this.dosage_days;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int id=sc.nextInt();
		String name=sc.next();
		double price=sc.nextDouble();
		//int year=sc.nextInt();
		//int month=sc.nextInt();
		//int day=sc.nextInt();
		String date=sc.next();
		Date d;
		try{d= new SimpleDateFormat("dd/MM/yyyy").parse(date);
Medicine m= new Medicine(id,name,price,d);
		
		int quant=sc.nextInt();
		System.out.println("The billing is ");
		System.out.println(m.billing(quant));
		
		int dosage=sc.nextInt();
		m.set_dosage(dosage);
		System.out.println(m);
		}
		catch(Exception e) {System.out.println(e.toString());}
		
		
		

	}

}
