//@author Admin

package lab10;
import java.sql.*;

public class CreateDB {

   
   public static void main(String[] args) {
   
 
   try{
      //STEP 2: Register JDBC driver
      
Class.forName("com.mysql.cj.jdbc.Driver");
      //STEP 3: Open a connection
      System.out.println("Connecting to database...");
      Connection conn=DriverManager.getConnection(  
"jdbc:mysql://localhost:3306/","root","");

      //STEP 4: Execute a query
      System.out.println("Creating database...");
   Statement stmt = conn.createStatement();
      
      String sql = "CREATE DATABASE myjavadb";
      stmt.executeUpdate(sql);
      System.out.println("Database created successfully...");
   conn.close();

stmt.close();
   }
   catch(Exception e)
   { System.out.println(e);}  
   
   }
}