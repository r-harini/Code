package lab5;
import java.util.*;

public class CreateLoans {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		Loan[] l=new Loan[5];
		int lno, loanamt;
		String custname, term;
		System.out.print("Enter prime rate:");
		int prime=sc.nextInt();
		for (int i=0;i<5;i++) {
			System.out.print("Enter Loan type:");
			String type=sc.next();
			if ("Business-Loan".contentEquals(type)) {
				lno=sc.nextInt();
				custname=sc.next();
				loanamt=sc.nextInt();
				term=sc.next();
				l[i]=new BusinessLoan(lno, loanamt, term, custname, prime);
				
			}
			else {
				lno=sc.nextInt();
				custname=sc.next();
				loanamt=sc.nextInt();
				term=sc.next();
				l[i]=new PersonalLoan(lno, loanamt, term, custname, prime);
			}
			l[i].calculate();
		}
		for (int i=0;i<5;i++) {
			System.out.println(l[i]);
		}
		
		sc.close();
	}

}
