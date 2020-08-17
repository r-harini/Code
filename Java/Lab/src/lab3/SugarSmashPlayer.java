package lab3;

public class SugarSmashPlayer {
	int playerID;
	String name="";
	int[] highscore=new int[50];
	
	public void setPlayerID(int id) {
		this.playerID=id;
	}
	
	public void setName(String n) {
		this.name=n;
	}
	
	public int getPlayerID() {
		return this.playerID;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setScore(int score, int level) {
		//this.highscore[level]=score;
		if (level>10 && level<1) {
			System.out.println("No such level exists");
			return;
		}
		else if (level==1) {
			this.highscore[0]=score;
		}
		else {
			for (int i=0;i<(level-1);i++) {
				if (this.highscore[i]!=100) {
					System.out.println("Cannot access this level yet");
					return;
				}
			}
			this.highscore[level-1]=score;
		}
	}
	
	public int getScore(int level) {
		if (level>10 && level<1) {
			System.out.println("No such level exists");
			return 0;
		}
		else {
			return this.highscore[level-1];
		}
	}

}
