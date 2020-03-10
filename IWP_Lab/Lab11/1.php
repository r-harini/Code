<?php
$servername="localhost";
$username="root";
$password="";

$conn=mysqli_connect($servername, $username, $password);

if(! $conn ) {
    die('Could not connect: ' . mysqli_error($conn));
}

$data="Select * from items";
mysqli_select_db($conn, 'shopping');
$val=mysqli_query($conn, $data) or die("Error: " . mysqli_error($conn));
echo "<table >";
echo "<tr><th>Item Code</th><th>Item Name</th><th>Price</th><th>Stock</th></tr>";
while($row=mysqli_fetch_array($val,MYSQLI_ASSOC)){
    echo "<tr><td >".$row['item_code']."</td><td> " .$row['name']. "</td><td> " .$row['price']. "</td><td> " .$row['stock']. "</td></tr>";
}
echo "</table>";
echo "<br><br>";
echo "<button><a href='purchase.html'>Purchase</a></button>";
mysqli_close($conn);
?>