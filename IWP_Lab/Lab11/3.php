<?php
     $dbhost = 'localhost';
     $dbuser = 'root';
     $dbpass = '';
     $conn = mysqli_connect($dbhost, $dbuser, $dbpass);
  
     if(! $conn ) {
        die('Could not connect: ' . mysqli_error($conn));
     }
     else{
         $item_code=$_POST['item_code'];
         $sql="DELETE FROM ITEMS where item_code='$item_code'";
         mysqli_select_db($conn, 'shopping');
         $query=mysqli_query($conn,$sql)or die("Error: " . mysqli_error($conn));
         echo "<b>Successfully Deleted</b><br><br>";
         $data="Select * from items";
mysqli_select_db($conn, 'shopping');
$val=mysqli_query($conn, $data) or die("Error: " . mysqli_error($conn));
echo "<table >";
echo "<tr><th>Item Code</th><th>Item Name</th><th>Price</th><th>Stock</th></tr>";
while($row=mysqli_fetch_array($val,MYSQLI_ASSOC)){
    echo "<tr><td >".$row['item_code']."</td><td> " .$row['name']. "</td><td> " .$row['price']. "</td><td> " .$row['stock']. "</td></tr>";
}
echo "</table>";
     }