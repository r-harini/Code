package lab10;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class InsertCourse {
	public static void main(String args[]){  
		try{  
		Class.forName("com.mysql.cj.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/student?useTimezone=true&serverTimezone=UTC","root","");

		//here sonoo is database name, root is username and password  
		Statement stmt=con.createStatement();  
		String sql = "INSERT INTO CollegeCourse " +
		                   "VALUES (111, 30, 'IWP')";
		      stmt.executeUpdate(sql);
		      sql = "INSERT INTO CollegeCourse " +
		                   "VALUES (222, 40, 'Java')";
		      stmt.executeUpdate(sql);
		      sql = "INSERT INTO CollegeCourse " +
		                   "VALUES (333, 25, 'ML')";
		      stmt.executeUpdate(sql);
		      sql = "INSERT INTO CollegeCourse " +
		                   "VALUES(444, 35, 'Networks')";
		      stmt.executeUpdate(sql);
		      sql = "INSERT INTO CollegeCourse " +
		              "VALUES(555, 25,'DSA')";
		      stmt.executeUpdate(sql);
		      System.out.println("Inserted records into the CollegeCourse table...");
		con.close();

		stmt.close();
		}catch(Exception e){ System.out.println(e);}  
		}  
}
