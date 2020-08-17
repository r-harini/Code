package lab4;

public abstract class NewspaperSubscription {
	String name;
	String address;
	double rate;
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String s) {
		name=s;
	}
	
	public String getAddress() {
		return this.address;
	}
	
	public double getRate() {
		return this.rate;
	}
	
	abstract void setAddress(String s);
	
}
