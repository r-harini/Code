package q1;

import java.util.*;
import java.io.*;

public class DiagnoseMaster {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter 1 for storing and 2 for reading the questions");
		int c=sc.nextInt();
		
		try {
			File Diseases=new File("DM.txt");
			if (Diseases.createNewFile()) {
				System.out.println("File Created");
			}
			else {
				System.out.println("File already exists");
			}
		if (c==1) {
			//To Store the Questions
			System.out.println("Enter the number of diseases to be entered");
			int n=sc.nextInt();
			FileWriter dis=new FileWriter("DM.txt");
			for (int i=0;i<n;i++) {
				System.out.println("Enter disease name:");
				String disease=sc.nextLine();
				String junk=sc.nextLine();
				System.out.println("Enter the questions separated by comma: ");
				
				String ques=sc.nextLine();
				dis.write(disease+"\t"+"("+ques+")\n");
			}
			dis.close();
			System.out.println("Written Successfully");
		}
		else {
			//To Read the Questions
			System.out.println("Enter the disease name:");
			String name=sc.next();
			Scanner reader=new Scanner(Diseases);
			int f=0;
			while(reader.hasNextLine()) {
				String data=reader.nextLine();
				String[] arr=data.split("\t", 2);
				if (name.equals(arr[0])) {
					System.out.println(data);
					f=1;
				}
			}
			if (f!=1) {
				System.out.println("Disease not found in the file");
			}
			reader.close();
		}
		
		}catch (IOException e) {
			System.out.println("Error occurred");
		}
		
		sc.close();
	}
}
