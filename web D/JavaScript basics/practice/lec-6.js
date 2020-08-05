/* CLOSURES
function outer(arg1){
    let x=10;
    function middle(arg2){
        let y=12;
        function inner(arg3){
            let z=14;
            console.log(arg1,arg2,arg3,x,y,z);

        }
        return inner;
    }
    return middle;
}
let a=outer("p1");
let b=a("p2");
b("p3");
*/
//THIS POINTER
/*function checkThis(){
    console.log(this); //points to window as function
                       //is defined globally
}
let obj={
    a:10,
    b:20,
    c:function(){
        console.log(this);//points to the Object in 
                          //which function is Defined
    },
    e: {
        l:1,
        m:2,
        n:function(){
            console.log(this);//points to object e
        }
    }
};
*/
//string literals
let s=`this is a string,'yo' 10+2= ${10+2}`;//backticks
console.log(s);
let obj1= {
    a:10,
    b:20,
    c:30
}
let obj2=Object.create(obj1);
obj2.a++;
console.log("obj2",obj2);
console.log("obj1",obj1)