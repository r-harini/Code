package lab10;

import java.sql.*;  

public class CreateTable{  
public static void main(String args[]){  
try{  
Class.forName("com.mysql.cj.jdbc.Driver");  
Connection con=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/student?useTimezone=true&serverTimezone=UTC","root","");

//here sonoo is database name, root is username and password  
System.out.println("Creating table in given database...");
   Statement   stmt = con.createStatement();
      
      String sql1 = "CREATE TABLE CollegeCourse" +
                   "(id INTEGER not NULL, " +
                   " cred_hours INTEGER, "+
                   " course_name VARCHAR(255), " + 
                   " PRIMARY KEY ( id ))"; 

      stmt.executeUpdate(sql1);
      System.out.println("Created CollegeCourse table in given database...");
      
      String sql2 = "CREATE TABLE Student" +
              "(id INTEGER not NULL, " +
    		  " name VARCHAR(255), "+
              " c_id INTEGER, " +
    		  " c_grade VARCHAR(255), "+
              " fac_id INTEGER, "+
              " PRIMARY KEY ( id ))"; 
      
      stmt.executeUpdate(sql2);
      System.out.println("Created Student table in given database...");
      
con.close();

stmt.close();
}catch(Exception e){ System.out.println(e);}  
}  
} 