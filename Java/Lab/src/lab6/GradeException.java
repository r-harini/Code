package lab6;
import java.util.Scanner;

public class GradeException {
int[] Sid = {11,12,13,14,15,16,17,18};
char[] Grade = new char[8];
String AllwdGrd = "ABCDFI";
public void getGrades() {
Scanner get = new Scanner(System.in);
for(int i=0;i<Sid.length;i++) {
System.out.println("\nEnter grade for "+Sid[i]+" : ");
try {
String in = get.next();
char m = in.charAt(0);
if(AllwdGrd.contains(in)) {
Grade[i] = m;
}
else throw new Exception();
}
catch(Exception e) {
System.out.println("\nInappropriate grade found!");
Grade[i] = 'I';
}
}
get.close();
}
public void disp() {
System.out.println("\nS.ID\tGrade");
for(int i=0;i<Sid.length;i++) {
System.out.println("\n"+Sid[i]+"\t"+Grade[i]);
}
}
}
