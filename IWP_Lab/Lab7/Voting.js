Parties=[0,0,0,0];
            
function redirect(){
    setTimeout(function() {window.location.replace("file:///C:/Code/IWP_Lab/Lab7/Lab7.html");}, 5000);
}
            
function cast(){
    alert("A:"+ Parties[0]+"\nB:"+Parties[1]+"\nC:"+Parties[2]+"\nD:"+Parties[3]);
    var q=document.getElementsByName("p");
    var i=0;
    for (i=0;i<q.length;i++){
        if (q[i].checked){
            Parties[i]++;
        }
    }
    alert("A:"+ Parties[0]+"\nB:"+Parties[1]+"\nC:"+Parties[2]+"\nD:"+Parties[3]);   
}

function winner(){
    var max=0;
    var k=0;
    for (var i=0;i<4;i++){
        if (Parties[i]>max){
            max=Parties[i];
            k=i;
        }
    }
    if (i==0){
        document.getElementById("winner").innerHTML='Party A';
    }
    else if(i==1) {
        document.getElementById("winner").innerHTML='Party B';
    }
    else if(i==2) {
        document.getElementById("winner").innerHTML='Party C';
    }
    else{
        document.getElementById("winner").innerHTML='Party D';
    }
}