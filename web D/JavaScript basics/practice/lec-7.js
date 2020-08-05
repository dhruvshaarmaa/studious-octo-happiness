//console.log("Aloha");
let str="abc";
let num=10;
let b=true;
let arr=[1,2,3];
let obj={a:1 , b:2};
let fun=function(){console.log("Aloha")};

console.log("type of String",typeof String);
console.log("type of Number",typeof Number);
console.log("type of Object",typeof Object);
console.log("type of Function",typeof Function);
console.log("type ofBooleang",typeof Boolean);
console.log("type oArrayng",typeof Array);


console.log(str.__proto__==String.prototype);
console.log(num.__proto__==Number.prototype);
console.log(b.__proto__==Boolean.prototype);
console.log(fun.__proto__==Function.prototype);
console.log(obj.__proto__==Object.prototype);
console.log(arr.__proto__==Array.prototype);
//prototype means model,blueprint
