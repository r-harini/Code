package lab4;

public class Blanket {
	String size;
	String color;
	String material;
	double price;
	
	Blanket(){
		this.size="Twin";
		this.color="White";
		this.material="cotton";
		this.price=30.00;
	}
	
	public void setSize(String s) {
		
		if (s.equals("Double")) {
			price+=10;
		}
		else if (s.contentEquals("Queen")) {
			price+=25;
		}
		else if (s.contentEquals("King")) {
			price+=40;
		}
		else {
			System.out.println("Size does not exist");
			return;
		}
		size=s;
	}
	
	public void setColor(String s) {
		color=s;
	}
	
	public void setMaterial (String s) {
		
		if (s.contentEquals("Wool")) {
			price+=20;
		}
		else if (s.contentEquals("Cashmere")) {
			price+=45;
		}
		else {
			System.out.println("Material does not exist");
			return;
		}
		material=s;
	}
	
	public void setPrice(double p) {
		price=p;
	}
	
	public double getPrice() {
		return this.price;
	}
	
	public String getSize() {
		return this.size;
	}
	
	public String getMaterial() {
		return this.material;
	}
	
	public String getColor() {
		return this.color;
	}
	
	public String toString() {
		return "Blanket size: "+this.size + "\nColor: "+ this.color +"\nMaterial: "+ this.material+"\nPrice: "+this.price+"\n";
	}
	


}
