//Object oriented programming in java script
//it allows to create object without defining classes

//one way of creating java script object
//(JSON->java script object notation)
var bird={
    x:10,
    y:20,
    colour:"yellow",
    eggs:["one","two","three"],
    fly:function(){
        console.log("Bird is flying at",this.x,this.y)
    }
}
console.log(bird.fly())
//for loop
for(let i=0;i<bird.eggs.length;i++){
    console.log(bird.eggs[i])
}
//for each loop
bird.eggs.forEach(
    function(val,idx){
    console.log(idx,val)
    }
)
