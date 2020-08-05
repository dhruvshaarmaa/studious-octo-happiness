s=`hi there`;            //backticks
s="Hi There";            //double quotes
s='Hi There fella\'s'    //single quotes
console.log(s)
s2="ab abc ab\
\nabcd ab"
console.log(s2);
console.log(s2.indexOf("ab")); //starting index
//ending index before 7 i.e. 3
console.log(s2.lastIndexOf("ab",6));
str="this is a string example";
console.log(str.slice(-2)); //slicing is done from left to right
console.log(str.substring(2,4));
console.log(str.substr(-2,1));
