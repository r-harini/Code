public class Patient{
    int ID;
    int age;
    char BloodGroup;
    
    Patient() {
        ID = 0;
        ID = 0;
        BloodGroup = 'O';
    }
    public Patient(int a, int b, char c) {
		ID = a;
		age = b;
		BloodGroup = c;
	}
	
	public int getId() {
		return ID;
	}
	
	public int getAge() {
		return age;
	}
	
	public char getBloodGroup() {
		return BloodGroup;
    }
    public static void print(Patient p) {
		System.out.println("Id : " + p.getId());
		System.out.println("Age : " + p.getAge());
		System.out.println("BloodData : " + p.getBloodGroup());
    }    
    public static void main(String [] args){
        Patient a = new Patient();        
        print(a);

        Patient b = new Patient(10,20,'O');
        print(b) ;
    }      
}