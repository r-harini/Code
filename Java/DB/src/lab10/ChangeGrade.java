package lab10;

import java.sql.*;

public class ChangeGrade{
	public static void main(String args[]){  
		try{  
		Class.forName("com.mysql.cj.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/student?useTimezone=true&serverTimezone=UTC","root","");
		//here sonoo is database name, root is username and password  
		Statement stmt=con.createStatement();  
		String sql = "UPDATE student " +
		                   "SET c_grade = 'F' WHERE id=1014 AND c_id=222";
		      stmt.executeUpdate(sql);

		     System.out.println("Student Grade updated using student ID and Course_id");
		con.close();
		
		stmt.close();
		}catch(Exception e){ System.out.println(e);}  
		} 
}