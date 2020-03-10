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
            $quantity=$_POST['quantity'];
            $sql1="SELECT price from items where item_code='$item_code'";
            mysqli_select_db($conn, 'shopping');
            $query=mysqli_query($conn,$sql1)or die("Error: " . mysqli_error($conn));
            $row1=mysqli_fetch_object($query);
            $price=$row1->price;
            $total_cost=$price*$quantity;
    
            $sql2="Select stock from items where item_code='$item_code'";
            mysqli_select_db($conn, 'shopping');
            $query1=mysqli_query($conn,$sql2)or die("Error: " . mysqli_error($conn));
            $row2=mysqli_fetch_object($query1);
            $stock=$row2->stock;
            $qty=$stock-$quantity;
            if ($qty<0){
                die("Error: Stock is insufficient");
            }
            $sql3="Update items set stock='$qty' where item_code='$item_code'";
            mysqli_select_db($conn,'shopping');
            $query2=mysqli_query($conn,$sql3) or die("Error:" . mysqli_error($conn));
             
            
                echo "<center>Your total cost is: '$total_cost'</center><br><br><br>";
                $data="Select * from items";
mysqli_select_db($conn, 'shopping');
$val=mysqli_query($conn, $data) or die("Error: " . mysqli_error($conn));
echo "<table >";
echo "<tr><th>Item Code</th><th>Item Name</th><th>Price</th><th>Stock</th></tr>";
while($row=mysqli_fetch_array($val,MYSQLI_ASSOC)){
    echo "<tr><td >".$row['item_code']."</td><td> " .$row['name']. "</td><td> " .$row['price']. "</td><td> " .$row['stock']. "</td></tr>";
}
echo "</table>";
                mysqli_close($conn);
        }
    
?>