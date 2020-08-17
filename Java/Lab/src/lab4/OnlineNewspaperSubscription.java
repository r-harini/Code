package lab4;

public class OnlineNewspaperSubscription extends NewspaperSubscription{
	void setAddress(String s) {
		int flag=0;
		for (int i=0;i<s.length();i++) {
			char x=s.charAt(i);
			if (x=='@') {
				flag =1;
				break;
			}
		}
		if (flag==0) {
			System.out.println("The address is not valid");
		}
		else {
			this.address=s;
			this.rate=9.00;
		}
	}
}
