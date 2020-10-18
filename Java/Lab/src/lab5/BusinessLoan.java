package lab5;

public class BusinessLoan extends Loan{
	double lfee;
	BusinessLoan(int l, int amt, String t, String name, int prime ){
		super(l, amt,t, name );
		this.ir=1+prime;
	}
	
	public String toString() {
		return super.toString()+"\nInterest Rate: "+this.ir+"\nLoan fee: "+this.lfee+"\n";
	}
	
	public void calculate() {
		this.lfee=(this.loanamt*this.ir* this.term)/100;
	}
	
}
