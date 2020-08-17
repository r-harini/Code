package lab3;

public class CustomTee extends TeeShirt{
	String slogan="";
	
	public void setSlogan(String slog) {
		this.slogan=slog;
	}
	
	public String getSlogan() {
		return this.slogan;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CustomTee c=new CustomTee();
		c.setColor("Red");
		System.out.println(c.getColor());
		c.setSlogan("Hello");
		System.out.println(c.getSlogan());
	}

}
