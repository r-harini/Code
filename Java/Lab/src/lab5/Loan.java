package lab5;

public abstract class Loan implements LoanConstants {
	int lno;
	String custlname;
	int loanamt, ir, term;
	
	Loan(int l, int amt, String t, String name ){
		this.lno=l;
		this.custlname=name;
		if (amt>maxamt) {
			this.loanamt=maxamt;
		}
		else {
		this.loanamt=amt;}
		if ("medium-term".equals(t)) {
			this.term=medterm;
		}
		else if ("long-term".contentEquals(t)) {
			this.term=longterm;
		}
		else {
			this.term=shortterm;
		}
	}
	
	public String toString() {
		return "Loan No.: "+this.lno+"\nCustomer name: "+custlname+"\nLoan Amount: "+this.loanamt+"\nTerm: "+ this.term+"years";
	}
	
	abstract public void calculate();
}
