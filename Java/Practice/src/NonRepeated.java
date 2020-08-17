
class Meh{
	String name;
}

public class NonRepeated {
	int x=2;
	NonRepeated(int i){x=i;}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Meh m=new Meh();
		m.name="A";
		Meh n=m;
		n=null;
		n=new Meh();
		m.name="C";
		n.name=m.name;
		System.out.println(n.name);
		
		
		

	}

}
