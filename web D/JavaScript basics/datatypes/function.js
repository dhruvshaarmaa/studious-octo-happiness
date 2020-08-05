console.log(1,typeof 1)
console.log('a',typeof 'a')
console.log("abc",typeof "abc")
console.log(1.23,typeof 1.23)
console.log(true,typeof true)
console.log(null,typeof null)
console.log(undefined,typeof undefined)
function alpha(){
    return 1
}
console.log(alpha())
let a=function() {
    return 0
}
console.log(a,typeof a)
console.log(a(),typeof a())
function area(height,width)
{
    if(!width)
    {
        return Math.PI*height*height
    }
    return height*width
}
console.log(area(1))
function area(side){
    console.log(arguments)
    return side*side
}
console.log(area(4,2))
