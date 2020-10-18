package lab10;


import java.sql.*;

public class ViewGrade{
	public static void main(String args[]){  
		try{  
		Class.forName("com.mysql.cj.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/student?useTimezone=true&serverTimezone=UTC","root","");
		//here sonoo is database name, root is username and password  
		Statement stmt=con.createStatement();  
		String sql = "SELECT ID,NAME,C_GRADE, C_ID FROM student " +
		                   "WHERE c_id=222";
		ResultSet rs = stmt.executeQuery(sql);

	      while(rs.next()){
	         //Retrieve by column name
	         int id  = rs.getInt("id");
	         String name = rs.getString("name");
	         String grade = rs.getString("c_grade");
	         int c_id = rs.getInt("c_id");

	         //Display values
	         System.out.print("ID: " + id);
	         System.out.print(", Name: " + name);
	         System.out.print(", Grade: " + grade);
	         System.out.println(", Course ID: " + c_id);
	      }
	con.close();
	rs.close();
		stmt.close();
		}catch(Exception e){ System.out.println(e);}  
		} 
}
