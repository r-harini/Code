/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.sql.Connection;
/**
 *
 * @author rhari
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try{
      //STEP 2: Register JDBC driver
      
Class.forName("com.mysql.cj.jdbc.Driver");
      //STEP 3: Open a connection
      System.out.println("Connecting to database...");
      Connection conn=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/?useTimezone=true&serverTimezone=UTC","root","");

      //STEP 4: Execute a query
      System.out.println("Creating database...");
   Statement stmt = conn.createStatement();
      
      String sql = "CREATE DATABASE studrernt";
      stmt.executeUpdate(sql);
      System.out.println("Student database created successfully...");
   conn.close();

stmt.close();
   }
   catch(Exception e)
   { System.out.println(e);}  
   
   }
    }
    
}