package lab8;
import java.util.*;
import java.io.*;

public class WriteCustomerList {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		
		int id;
		String fname, lname;
		double balance;
		
		try {
			File cust=new File("customer.txt");
			if (cust.createNewFile()) {
				System.out.println("File Created");
			}
			else {
				System.out.println("File already exists");
			}
			System.out.println("Enter the number of customer records:");
			
			FileWriter customer=new FileWriter("customer.txt");
			int n=sc.nextInt();
			for (int i=0;i<n;i++) {
				id=sc.nextInt();
				fname=sc.next();
				lname=sc.next();
				balance=sc.nextDouble();
				customer.write(id+" "+fname+" "+lname+" "+balance+"\n");
			}
			customer.close();
			System.out.println("Written Successfully");
		}catch(IOException e) {
			System.out.println("Error occurred");
		}
		
		sc.close();
	}

}
