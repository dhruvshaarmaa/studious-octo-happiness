/*
arr=[1,"Hi",true,[1,2,3]];
//for loop
console.log("For-Simple");
for(let i=0;i<arr.length;i++)
{
    console.log(arr[i]);
}
//for of loop (values)
console.log("For-Of");
for(let val of arr)
{
    console.log(val);
}
//for in loop (index)
console.log("For-In");
for(let i in arr)
{
    console.log(arr[i]);
}
//for each loop
console.log("For-Each");
arr.forEach(function(val){
    console.log(val);
});
*/
//slice,splice,concat
//Slice
arr=[0,1,2,3,4,5,6]
console.log("Original Array",arr);
console.log("SLICE slice(0,3)\n",arr.slice(0,3));
s=arr.slice(0,3);
console.log("Slice returns sliced part",s);
console.log("Array is not Mutated",arr,"\n\n");
console.log("SPLICE splice(4,2)\n");
s1=arr.splice(4,2);
console.log("Splice returns spliced part",s1);
console.log("Array is Mutated",arr);
s2=arr.splice(0,3,7,8,9);
console.log("Replacing Part",s2,"Using Splice\n\
New Array",arr,"\n\n");
console.log("CONCAT\n",10,11,12);
s3=arr.concat(10,11,12);
console.log("Concatnated Array",s3);
console.log("Array is not Mutated",arr,"\n\n");

