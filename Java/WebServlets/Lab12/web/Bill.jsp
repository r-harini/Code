<%-- 
    Document   : Bill
    Created on : Oct 25, 2020, 10:57:14 AM
    Author     : rhari
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Food Ordering Bill</title>
</head>
<body>
	<h1>Online Food Ordering Portal</h1>
	<h2>
		<%=session.getAttribute("username")%>
	</h2>

	<h2>Thank You for Ordering !!!</h2>
	<table>
		<tr>
			<td>S.No.</td>
			<td>Name Of Dish</td>
			<td>Price</td>
			<td></td>
			<td>Quantity</td>
			<td></td>
			<td>Total Price</td>
		</tr>
		<tr>
			<td>---------</td>
			<td>------------------------</td>
			<td>-------------</td>
			<td>-----</td>
			<td>--------------</td>
			<td>-----</td>
			<td>------------------------</td>
		</tr>
		<%
			String food[] = (String[]) session.getAttribute("food");
		double price[] = (double[]) session.getAttribute("price");
		int count = 1;
		double bill = 0.0, totalBill = 0.0;
		for (int i = 0; i < food.length; i++) {
			int x = Integer.parseInt(request.getParameter(food[i]));
		%>
		<tr>
			<%
				if (x != 0) {
				out.println("<td>" + count + "." + "</td>");
				out.println("<td>" + food[i] + "</td>");
				out.println("<td>" + String.format("%.2f", price[i]) + "</td>");
				out.println("<td>" + " x " + "</td>");
				out.println("<td>" + x + "</td>");
				out.println("<td>" + " = " + "</td>");
				bill = price[i] * x;
				out.println("<td>" + String.format("%.2f", bill) + "</td>");
				totalBill += bill;
				count += 1;
			}
			}
			%>
		</tr>
	</table>
	<h4>
		Total Price :
		<%=String.format("%.2f", totalBill)%></h4>
	<h4>
		CGST (8%) :
		<%=String.format("%.2f", totalBill * 0.08)%></h4>
	<h4>================================</h4>
	<h4>
		Amount Payable :
		<%=String.format("%.2f", totalBill + totalBill * 0.08)%></h4>
</body>

</html>
