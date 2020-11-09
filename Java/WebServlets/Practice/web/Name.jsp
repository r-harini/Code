<%-- 
    Document   : Name
    Created on : Nov 1, 2020, 12:36:48 PM
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
        <ul>
        <%
            int[] a=(int[])session.getAttribute("a");
            for (int i=0;i<a.length;i++){
            %>
            <li><%out.println(a[i]);%></li>
        <%
            }
         %>
        </ul>
    </body>
</html>
