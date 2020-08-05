console.log("Hi")
let c=[1,2,3,4,5]//block scope
console.log(c)
var d=[1,2,3,4,5] //function scope
c=[1,2,3,4,5,6] //global scope
console.log(c)
e=10
console.log("e",e)
function fun(a){
    if(a==1){
        //let b=30; //block scope
        //var b=30; //function scope
        b=30 //global scope
    }
    console.log(b);
    return 1;
}
console.log(fun(1))
console.log(b)
arr=["Miku Chan","Yatogami Tohka","Tobichi Origami","Yuzuru","Kazuya"]
console.log(arr)
console.log(arr.length)
console.log(arr["length"])
l=arr.pop()
console.log("Popped",l,arr)
arr.push("Kotori")
console.log("Pushed",arr[arr.length-1],arr)
front=arr.shift()
console.log("Remove from front",front,arr)
arr.unshift("Rias Gremory")
console.log("Pushed at Front",arr[0],arr)
console.log(arr.indexOf("Kotori"))

