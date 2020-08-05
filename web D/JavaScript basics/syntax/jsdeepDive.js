//set interval
/*let intervalId=0;
runCount=0;
function myfun(){
    runCount++;
    if(runCount>5)
    {
        clearInterval(intervalId);
    }
    console.log("Hi! This runs after every 1 sec");
    console.log("...");
}

intervalId=setInterval(myfun,1000);
*/
//set timeout
console.log("hey There!");
setTimeout(function(){
    console.log("Konichiwa");
}, 1000);//runs only one time after 1 second
//Call stack in JS
/*function ceo(){
    console.log("Lets call cto");
    cto();
}
function cto(){
    console.log("lets call vpengg");
    vpeng();
}
function vpeng()
{
    console.log("lets call techlead");
    techlead();
}
function techlead(){
    console.log("lets call dev");
    dev();
}
function dev(){
    console.log("Konichiwa");
    //throw error("baka");
}
ceo();
*/
//closures counter
/*function counter(initial,delta){
    return {
        up(){
            initial+=delta;
            console.log(initial);
        },
        down(){
            initial-=delta;
            console.log(initial);
        }
    }
}
let obj=counter(8,2);
obj.up(); //8->10
obj.down();//10->8
obj.down();//8->6
*/
//variables
/*const arr=[1,2,3,4];
arr.push(5); //mutable
arr[2]=1;    //mutable
console.log(arr);
//arr=[0,1];//can't reassign it
const x=10;
// x++;//x=x+1; assignment not possible for const
console.log(x);

function fun(){
    //var myval =20;
    if(true)
    {
        let y=10;
        var myval=30;//function scope equivalent to
        //myval=30; overwriting myval
    }
    console.log(myval);
    //console.log(y);
}
fun();//let has block scope
*/
//pass by value or by reference
//JS passes by value always but in case of arrays it passese the
//value as reference to that array or object
/*var waifus=["Elizabeth","Esdeth","Rias"];
function changewaifus(waifus){
    waifus[0]="Tobichi Origami";
    waifus[1]="Yatogami Tohka";
}
console.log("My waifus were",waifus);
changewaifus(waifus);//waifus reference is passed by value
console.log("Now my waifus are",waifus);
*/
//IIFE's ->immediately invoked function expression
/*(function(greet){
    console.log("Konichiwa!",greet);
})("aloha");

(function(){
    console.log("3^4=",Math.pow(3,4));
    console.log("4^3=",Math.pow(4,3));
    console.log("root 10",Math.sqrt(10));
    console.log("sin 1",Math.sin(1));
})();
//using iife's
(function(p,q,r,s){
    p("3^4=",q(3,4));
    p("4^3=",q(4,3));
    p("root 10",r(10));
    p("sin1",s(1));

})(console.log,Math.pow,Math.sqrt,Math.sin) //minimization
//case 1 ecma5
for(var i=0;i<10;i++){
    setTimeout(function(){
        console.log(i); //i has functional scope or due to closure
        // i.e once for loop is iterated
        // i becomes 10 and for all iterations i=10 is printed...
    },100);
}
//case 2:ecma 6(use let or const for block scope)
for(let i=0;i<10;i++){ //i has separate scope for each function call
    setTimeout(function(){
        console.log(i); 
    },100);
}
//case 3:use iffe 
for(var i=0;i<10;i++){ //i has separate scope foe each iteration
    (function(j){//iife create block scope for j
        setTimeout(function(){
            console.log(j); 
        },100);
    })(i)
}
for(var i=0;i<10;i++){
    setTimeout(console.log,100,i);//function callback
    //copy of arguement i is made and is bound to each
    //function call
}
*/
//object inheritance
/*
function person(name,age){
    this.age=age;
    this.name=name;
}
p=new person("Harry",20);
console.log(p);
console.log(person.prototype.isPrototypeOf(p));
console.log(Object.prototype.isPrototypeOf(p));
*/
//Promises
function fakePromises(done){
    setTimeout(function() {
        let downloadedData="Some data we ripped off interwebs";
        done(downloadedData);
    }, 1000);
}
fakePromises(function(data){ //callback function
    console.log("We Downloaded this Data");
    console.log(data);
});

function fakeDownloadPromise(correct){
    return new Promise(function(resolve,reject){ //executor object arguements
                setTimeout(function() {
                    let downloaddata="Some data from net";
                    if(correct)
                    {
                        resolve(downloaddata);
                    }else{
                        reject(new Error("Could not Download File."));
                    }
                    
                }, 1000);                                 //having two functions         

    });
}
fakeDownloadPromise(false).then(function resolve(data){
    console.log("we downloaded data");
    console.log(data);
}).catch(function(err){
    console.log(err);
});
