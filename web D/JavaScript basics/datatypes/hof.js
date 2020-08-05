function creategreeter(greeting){ //hof
    function greet(name){ // greet is hof for name(getName)
        console.log(greeting,name()) //treat name as function
    }//getName is called here
    return greet
}
let g1=creategreeter("Good Evening");
let g2=creategreeter("Good Morning");
console.log(g1)
function getName(){
    return document.getElementById('namebox').value
}