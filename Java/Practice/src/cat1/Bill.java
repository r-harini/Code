package cat1;

public class Bill {
	static public double computeBill(double price) {
		return price*1.08;
	}
	
	static public double computeBill(double price, int quantity) {
		return (price*quantity)*1.08;
	}
	
	static public double computeBill(double price, int q, int c) {
		return ((q*price)-c)*1.08;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int price=100;
		int q=2;
		int c=2;
		System.out.println("1:"+ computeBill(price));
		System.out.println("2:"+ computeBill(price,q));
		System.out.println("3:"+ computeBill(price,q,c));

	}

}
