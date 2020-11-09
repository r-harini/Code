
public class Main
{
    public static int mult(int m, int n){
        int num, times;
        if (m<=n){
            times=m;
            num=n;
        }
        else{
            times=n;
            num=m;
        }
        if (times==0) {
        	return 0;
        }
        if (times==1){
            return num;
        }
        if (times%2==0){
            return mult(num<<1, times/2);
        }
        else{
            return num+mult(num, times-1);
        }
    }
	public static void main(String[] args) {
		System.out.println(mult(20,160));
	}
}
