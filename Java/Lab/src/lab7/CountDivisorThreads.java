package lab7;

public class CountDivisorThreads extends Thread{
	 public void run(){
	 int maxDivisors = 1;
	 int numWithMax = 1;
	 long startTime = System.currentTimeMillis();
	 for (int i = 2; i <= 100000; i++ ) {
	 int count = 0;
	 for (int j = 1; j <= i; j++ ) {
	 if ( i % j == 0 )
	 count++;
	 }
	 if (count > maxDivisors) {
	 maxDivisors = count;
	 numWithMax = i;
	 }
	 }
	 long elapsedTime = System.currentTimeMillis() - startTime;
	 System.out.println("Number "+ numWithMax +" with " + maxDivisors + " hasmaximum number of divisors.");
	 System.out.println("Total elapsed time: " + (elapsedTime/1000.0) + "seconds.\n");
	 }
	 public static void main(String[] args) {
	 CountDivisorThreads t1 = new CountDivisorThreads();
	 t1.start();
	 }
	}