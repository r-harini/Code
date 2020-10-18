package lab8;
import java.util.*;
import java.io.*;

public class DisplaySavedCustomerList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			File obj=new File("customer.txt");
			Scanner sc=new Scanner(obj);
			while(sc.hasNextLine()) {
				String data=sc.nextLine();
				System.out.println(data);
			}
			sc.close();
		}catch(FileNotFoundException e) {
			System.out.println("An error occurred");
		}

	}

}
