import java.util.*;

public class Julian {
    public static String findDay(int c) {
        String ans = "";
        if (c==0){
            ans = "Sunday";
        }
        else if (c==1){
            ans = "Monday";
        }
        else if (c==2){
            ans = "Tuesday";
        }
        else if (c==3){
            ans = "Wednesday";
        }
        else if (c==4){
            ans = "Thursday";
        }
        else if (c==5){
            ans = "Friday";
        }
        else{
            ans = "Saturday";
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter the Julian day in Number : ");
        int day = ob.nextInt();
        int a = (day + 1) % 7;
        String ans = findDay(a);
        System.out.println("Day : " + ans);
        ob.close();
    }
}