package assignments;
import java.util.*;
  
public class Para {
	
    public static void main(String[] args) { 
         
    	Scanner sc=new Scanner(System.in);
    	String para=sc.nextLine();

        int countWord = 0; 
        int sentenceCount = 0; 
        int characterCount = 0;  
        
        int length=para.length();
        
        for (int i=0; i<length; i++) {
        	char c=para.charAt(i);
        	if (Character.isWhitespace(c)) {
        		countWord++;
        	}
        	else if (c=='.') {
        		countWord++;
        		sentenceCount++;
        		characterCount++;
        		i++;
        	}
        	else {
        		characterCount++;
        	}
        }
        sc.close();
          
        System.out.println("Total word count = " + countWord); 
        System.out.println("Total number of sentences = " + sentenceCount); 
        System.out.println("Total number of characters = " + characterCount); 
    } 
} 