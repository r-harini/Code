package lab8;
import java.util.*;
import java.io.*;

public class DisplaySelectedCustomersByName {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the Last Name to be found:");
		String name=sc.next();
		int f=0;
		
		try {
			File obj=new File("customer.txt");
			Scanner reader=new Scanner(obj);
			
			while (reader.hasNextLine()) {
				String data=reader.nextLine();
				String[] arr=data.split(" ", 5);
				if (name.equals(arr[2])) {
					System.out.println(data);
					f=1;
				}
			}
			
			if (f!=1) {
				System.out.println("No such name exists.");
			}
			
			reader.close();
		}catch (FileNotFoundException e) {
			System.out.println("Error occurred");
		}
		
		sc.close();
	}
}
