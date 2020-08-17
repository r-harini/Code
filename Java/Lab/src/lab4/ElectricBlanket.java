package lab4;

public class ElectricBlanket extends Blanket{
	int heatsettings;
	boolean shutoff;
	
	ElectricBlanket(){
		heatsettings=1;
		shutoff=false;
	}
	
	public void setHeatSettings(int n) {
		if (n<1 || n>5) {
			System.out.println("Number of Heat settings not allowed");
		}
		else {
			heatsettings=n;
		}
	}
	
	public void setShutoff(boolean b) {
		if (b) {
			shutoff=b;
			price+=5.75;
		}
	}
	
	public int getHeatSettings() {
		return this.heatsettings;
	}
	
	public boolean getShutoff() {
		return this.shutoff;
	}
	
	public String toString() {
		return super.toString()+"No. of Heat settings: "+ heatsettings + "\nAutomatic shutoff feature: "+ shutoff+"\n";
	}
	
	

}
