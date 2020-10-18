package lab10;

import java.sql.*;

public class InsertStudent{  
public static void main(String args[]){  
try{  
Class.forName("com.mysql.cj.jdbc.Driver");  
Connection con=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/student?useTimezone=true&serverTimezone=UTC","root","");

//here sonoo is database name, root is username and password  
Statement stmt=con.createStatement();  
String sql = "INSERT INTO Student " +
                   "VALUES (1010, 'Harini', 111, 'S',123)";
      stmt.executeUpdate(sql);
      sql = "INSERT INTO Student " +
                   "VALUES (1011, 'Mahnaz', 222,'B', 234)";
      stmt.executeUpdate(sql);
      sql = "INSERT INTO Student " +
                   "VALUES (1012, 'Zaid', 333, 'C', 345)";
      stmt.executeUpdate(sql);
      sql = "INSERT INTO Student " +
                   "VALUES(1013, 'Sumit', 444, 'A', 345)";
      stmt.executeUpdate(sql);
      sql = "INSERT INTO Student " +
              "VALUES(1014, 'Amit', 222,'B', 234)";
      stmt.executeUpdate(sql);
      System.out.println("Inserted records into the Students table...");
con.close();

stmt.close();
}catch(Exception e){ System.out.println(e);}  
}  
} 
