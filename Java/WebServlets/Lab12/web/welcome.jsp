<%-- 
    Document   : welcome
    Created on : Oct 23, 2020, 11:52:22 PM
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
        <%
            String name=request.getParameter("uname");
            out.print("Welcome "+name);
            session.setAttribute("user", name);
        %>
    </body>
</html>
