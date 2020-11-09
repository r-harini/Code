<%-- 
    Document   : newjsp
    Created on : Oct 28, 2020, 12:49:39 PM
    Author     : rhari
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="Name.jsp" method="POST">
            <%
                session.setAttribute("fullname", "R. Harini");
                int[] a={1,5,6,7,2,3};
                session.setAttribute("a",a);
                %>
            <input type="text" name="name">
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
