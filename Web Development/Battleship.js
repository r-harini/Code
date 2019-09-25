var l1=3;
var l2=4;
var l3=5;



function Go(){
    var guess;
    var hits=0;
    var attempts=0;
    var isSunk=false;
    while (isSunk==false){
        guess=prompt("Enter a number 0-6:");
        if (guess>6 || guess<0){
            guess=prompt("Enter a valid number:");
        }
        else{
            attempts=attempts+1;
            if (guess==l1||guess==l2||guess==l3){
                hits=hits+1;
                if (hits==3){
                    isSunk=true;
                    alert("Battleship sank");
                }
                else{
                    alert("Wonderful!Try one more time");
                }
            }
            
        }
    }
}