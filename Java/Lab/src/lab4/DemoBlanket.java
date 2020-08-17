package lab4;

public class DemoBlanket {

	public static void main(String[] args) {
		
		Blanket b1= new Blanket();
		System.out.println(b1);
		
		b1.setColor("Red");
		b1.setSize("King");
		b1.setMaterial("Cashmere");
		System.out.println(b1);
		
		ElectricBlanket eb=new ElectricBlanket();
		System.out.println(eb);
		
		System.out.println("**Giving the number of heat settings as 6**");
		eb.setHeatSettings(6);
		System.out.println();
		eb.setHeatSettings(2);
		eb.setShutoff(true);
		System.out.println(eb);
	}

}
