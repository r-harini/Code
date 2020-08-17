import java.util.Scanner;
class Billing1{
    double price; 
    double quantity;
    double coupon_value;
    
    double computeBill(double price){
        double total = price+(8*price/100);
        return total;
    }
    
    double computeBill(double price, int quantity){
        double total = (108*price*quantity)/100;
        return total;
    }
    
    double computeBill(double price, int quantity, double coupon_value){
        double total = 108*(price*quantity-coupon_value)/100;
        return total;
    }
}

 public class Billing
{
 public static void main( String [] args )
 {
 Scanner keyboard;
 keyboard = new Scanner( System.in );
 double price;
 int quantity;
 double coupon_value;
 double total;
 Billing1 bill = new Billing1();
 System.out.print("Enter price: ");
 price = keyboard.nextDouble ();
 System.out.print("Enter quantity: ");
 quantity = keyboard.nextInt ();
 System.out.print("Enter coupon value: ");
 coupon_value = keyboard.nextDouble ();
 keyboard.close();
 total = bill.computeBill(price);
 System.out.println("Total Bill: "+ total);
 total = bill.computeBill(price, quantity);
 System.out.println("Total Bill: "+ total);
 total = bill.computeBill(price, quantity, coupon_value);
 System.out.println("Total Bill: "+ total);
 }
}
