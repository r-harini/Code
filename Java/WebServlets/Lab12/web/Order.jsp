<%-- 
    Document   : Order
    Created on : Oct 25, 2020, 10:54:51 AM
    Author     : rhari
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Food Menu</title>
    </head>
    <body>
	<h1>Food Ordering Portal</h1>
	<h2>
		<%
			String name = request.getParameter("username");
		session.setAttribute("username", name);
		out.print("Welcome " + name);
		%>
	</h2>
	<h3>Choose your Order from the Menu</h3>
	<%
		String food[] = { "Margherita", "Fried Rice", "Manchurian", "Lasagna", "Chicken Biryani", "Panner Tikka",
			"Kathi Rolls", "Non Veg Pizza", "Cold Coffee", "Chocolate Shake" };
	double price[] = { 200, 150, 110.45, 340, 425, 250.25, 110, 460, 225, 135 };
        session.setAttribute("food", food);
				session.setAttribute("price", price);
	%>
	<form action="Bill.jsp" method="POST">
		<table>
			<tr>
				<td>S.No.</td>
				<td>Name Of Dish</td>
				<td>Price</td>
				<td>Choose</td>
			</tr>
			<tr>
				<td>---------</td>
				<td>------------------------</td>
				<td>-------------</td>
				<td>----------------------------</td>
			</tr>
			<%
				for (int i = 0; i < food.length; i++) {
			%>
			<tr>
				<%
					
				out.println("<td>" + (i + 1) + "." + "</td>");
				out.println("<td>" + food[i] + "</td>");
				out.println("<td>" + price[i] + "</td>");
				%>
				<td><input type="number" name="<%=food[i]%>" value="0"></td>
			</tr>
			<%
				}
			%>
			<tr>
				<td></td>
				<td></td>
				<td></td>
				<td><button type="submit" name="submit">Place Order</button></td>
			</tr>
		</table>
	</form>
</body>

</html>
