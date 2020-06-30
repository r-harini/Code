import java.util.*;

public class Data {
    public static void main(String[] args){
        Character i= new Character('c');
        Character j=i;
        i='q';
        System.out.println("The character is:");
        System.out.println(j);

    }    
}