package assignments;
import java.util.*;

public class BMI {
	static void print(String sent) {
		System.out.println(sent);
	}
	public static void main(String[] args) {
		
		System.out.println("******Calculating BMI******");
		Scanner sc2=new Scanner(System.in);
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter your height (in m):");
		float height=sc2.nextFloat();
		System.out.println("Enter your weight (in kg):");
		int weight=sc.nextInt();
		sc2.close();
		sc.close();
		float bmi=weight/(height*height);
		if (bmi<16) {
			print("Serious Underweight");
		}
		else if (bmi>16 && bmi<18) {
			print("Underweight");
		}
		else if (bmi>18 && bmi<24) {
			print("Normal weight");
		}
		else if(bmi>24 && bmi<29) {
			print("Overweight");
		}
		else if (bmi>29 && bmi<35) {
			print("Seriously overweight");
		}
		else {
			print("Gravely owerweight");
		}
		
		
	}
}
