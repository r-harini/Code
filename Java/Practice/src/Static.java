
class StaticTest{
	static int i=47;
	static void method(){
		i--;
	}
}

public class Static {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StaticTest s1=new StaticTest();
		StaticTest s2=new StaticTest();
		StaticTest.method();
		//System.out.println(s1.i);
		//System.out.println(StaticTest.i);
		
		/*int i=1;
		if((boolean)i) {
			System.out.println("T");
		}
		else {
			System.out.println("F"); 
		}*/
		System.out.printf("%.2f",(108*5)/100);
		
	}

}
