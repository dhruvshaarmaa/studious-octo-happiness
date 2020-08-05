//one way to create an object
var apple={
    taste:"sweet",
    colour:"Red"
};
console.log(apple);
//another way using new keyword
function fruit(taste,colour){
    this.taste=taste;
    this.colour=colour;
}
orange=new fruit("sour","orange");
console.log(orange);
//class declaration and class expression (Not Hoisted)
//class keyword (ECMAscript 2015)
class fruitClass{
    constructor(taste,colour){
        this.taste=taste;
        this.colour=colour;
    }
}
let mango=new fruitClass("sweet","yellowish");
console.log(mango);
//class expression
let fruitClass2=class{
    constructor(taste,colour){
        this.taste=taste;
        this.colour=colour;
    }
}
let mango2=new fruitClass("Sour","Greenish");
console.log(mango2);