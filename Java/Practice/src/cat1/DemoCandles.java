package cat1;

import java.util.*;

class Candle{
	String color;
	int height;
	int price;
	
	public String getColor() {
		return color;
	}
	
	public int getHeight() {
		return height;
	}
	
	public int getPrice() {
		return price;
	}
	
	public void setColor(String c) {
		color=c;
	}
	
	public void setHeight(int h) {
		height=h;
		price=2*height;
	}
	
	public String toString() {
		return color+" "+ height+" "+ price;
	}
		
}

class ScentedCandle extends Candle{
	String scent;
	
	public void setScent(String s) {
		scent=s;
	}
	
	public String getScent() {
		return scent;
	}
	
	public void setHeight(int h) {
		height=h;
		price=height*3;
	}
	
	public String toString() {
		return color+" "+scent+" "+height+" "+price;
	}
}

public class DemoCandles {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Candle c=new Candle();
		c.setColor("Red");
		c.setHeight(4);
		System.out.println(c);
		
		ScentedCandle s=new ScentedCandle();
		s.setColor("Blue");
		s.setHeight(5);
		s.setScent("Spring");
		System.out.println(s);
		

	}

}
