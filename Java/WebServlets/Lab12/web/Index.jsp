<%-- 
    Document   : Index
    Created on : Oct 25, 2020, 10:53:46 AM
    Author     : rhari
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
       <title>Food Ordering Login</title>
    </head>
    <body>
	<h1>Food Ordering Portal</h1>
	<form action="Order.jsp" method = "POST">
		<table>
			<tr>
				<td>UserName : </td>
				<td><input type = "text" name = "username"></td>
			</tr>
			<tr>
				<td>Password : </td>
				<td><input type = "password" name = "password"></td>
			</tr>
			<tr>
				<td></td>
				<td><input type="submit" value="Login"></td>
			</tr>
		</table>
	</form>

    </body>
</html>
