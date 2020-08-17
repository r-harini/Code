package lab3;

public class TeeShirt {
	int ordnum;
	double price;
	String size="";
	String color="";
	
	public void setOrdNum(int ord) {
		this.ordnum=ord;
	}
	
	public void setSize(String size) {
		this.size=size;
		if (size.equals("XXL") || size.equals("XXXL")) {
			this.price=22.99;
		}
		else {
			this.price=19.99;
		}
	}
	
	public void setColor(String col) {
		this.color=col;
	}
	
	public int getOrdNum() {
		return this.ordnum;
	}
	
	public double getPrice() {
		return this.price;
	}
	
	public String getSize() {
		return this.size;
	}
	
	public String getColor() {
		return this.color;
	}
	
	

}
