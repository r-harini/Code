
var U=["admin"];
var P=["admin"];

function check(){
    Username=document.getElementById("Username").value;
    Password=document.getElementById("Password").value;
    
    for (var i=0;i<U.length;i++){
        if (Username==U[i]){
            if (Password==P[i]){
               window.open("frames.html", "_parent");
            }
            else{
                alert("Password Incorrect");
            }
        }
        else{
            alert("Username does not exist");
        }
    }
}

function signup(){
    user=document.getElementById("nuser").value;
    pass1=document.getElementById("pass1").value;
    pass2=document.getElementById("pass2").value;
    u=/^[0-9]{2}[A-Z]{3}[0-9]{4}$/;
    if (!u.test(user)){
        alert("Enter a valid username");
    }else{
    if (pass1!=pass2){
        alert("Passwords do not match");
    }
    else{
        U.push(user);
        P.push(pass1);
        
        window.open("Start.html", "_parent");
    }
}
}