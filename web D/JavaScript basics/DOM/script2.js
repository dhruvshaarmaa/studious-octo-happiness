let inpbox=document.getElementById("inpbox");
let list=document.getElementById("list");
let btn=document.getElementById("btn");
btn.onclick=function(){
    let N=parseInt(inpbox.value);
    let start=Date.now();
    //let str="" 2
    for(let i=1;i<=N;i++)
    {
        /*let newstr=list.innerHTML+'<li>'+i+'</li>';
        list.innerHTML=null;
        list.innerHTML=newstr; //every time document is changing and printing
        list from start
        */
       //str+='<li>'+i+'</li>'; 2
       let item=document.createElement('li');
       item.innerText=i;
       list.appendChild(item);
    }
    //list.innerHTML=str;  2
    console.log(Date.now()-start);
}