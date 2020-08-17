package lab3;

public class DemoSugarSmash {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("***Sugar Smash Player***");
		SugarSmashPlayer s=new SugarSmashPlayer();
		s.setScore(100, 1);
		s.setScore(20, 2);
		System.out.println("Score of level 1:"+s.getScore(1));
		System.out.println("Score of level 2:"+ s.getScore(2)+"\n");
		
		System.out.println("***Premium Sugar Smash Player***");
		PremiumSugarSmashPlayer p=new PremiumSugarSmashPlayer();
		p.setScore(20, 1);
		p.setPaid(2);
		p.setPaid(3);
		p.setScore(100, 1);
		p.setScore(30, 3);
		p.setScore(100, 2);
		p.setScore(35, 3);
		System.out.println("Score of leve 1:"+p.getScore(1));
		System.out.println("Score of level 2:"+p.getScore(2));
		System.out.println("Score of level 3:"+ p.getScore(3));

	}

}
