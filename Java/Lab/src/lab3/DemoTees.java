package lab3;

public class DemoTees {

	public static void main(String[] args) {
		
		TeeShirt t=new TeeShirt();
		t.setColor("Red");
		t.setSize("XXL");
		t.setOrdNum(12);
		System.out.println("Order num of Tee: "+t.getOrdNum());
		System.out.println("Color of Tee: "+ t.getColor());
		System.out.println("Size of Tee: "+t.getSize());
		System.out.println("Price of Tee: "+t.getPrice()+"\n");
		
		TeeShirt t1=new TeeShirt();
		t1.setColor("Green");
		t1.setSize("L");
		t1.setOrdNum(14);
		System.out.println("Order num of Tee: "+t1.getOrdNum());
		System.out.println("Color of Tee: "+ t1.getColor());
		System.out.println("Size of Tee: "+t1.getSize());
		System.out.println("Price of Tee: "+t1.getPrice()+"\n");		
		
		CustomTee c=new CustomTee();
		c.setColor("Blue");
		c.setSize("M");
		c.setOrdNum(245);
		c.setSlogan("Good Vibes Only");
		System.out.println("Order num of Custom Tee: "+c.getOrdNum());
		System.out.println("Color of Custom Tee: "+ c.getColor());
		System.out.println("Size of Custom Tee: "+c.getSize());
		System.out.println("Price of Custom Tee: "+c.getPrice());
		System.out.println("Slogan: "+c.getSlogan());
		
		CustomTee c1=new CustomTee();
		c1.setColor("Black");
		c1.setSize("XXXL");
		c1.setOrdNum(565);
		c1.setSlogan("Enjoy Life");
		System.out.println("Order num of Custom Tee: "+c1.getOrdNum());
		System.out.println("Color of Custom Tee: "+ c1.getColor());
		System.out.println("Size of Custom Tee: "+c1.getSize());
		System.out.println("Price of Custom Tee: "+c1.getPrice());
		System.out.println("Slogan: "+c1.getSlogan());
	}

}
