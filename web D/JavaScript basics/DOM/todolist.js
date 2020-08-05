let newtask=document.getElementById("newtask");
let addtask=document.getElementById("addtask");
let list=document.getElementById("list");
addtask.onclick=function(){
    let li=document.createElement("li");
    let s=document.createElement("span");
    s.innerText=newtask.value;
    let xbtn=document.createElement("button");
    xbtn.innerText='✖';
    xbtn.onclick=function(event){
        event.target.parentElement.remove();
    }
    let upbtn=document.createElement("button");
    upbtn.innerText='⬆';
    upbtn.onclick=function(event){
        //event.target upbtn
        //event.target.parentElement //li
        event.target.parentElement.parentElement.insertBefore(
            event.target.parentElement,
            event.target.parentElement.previousElementSibling
        )
    }
    let dnbtn=document.createElement("button");
    dnbtn.innerText='⬇';
    dnbtn.onclick=function(event){
        //event.target dnbtn
        //event.target.parentElement //li
        event.target.parentElement.parentElement.insertBefore(
            event.target.parentElement.nextElementSibling,
            event.target.parentElement
        )
    }
    li.appendChild(xbtn);
    li.appendChild(upbtn);
    li.appendChild(dnbtn);
    li.appendChild(s);
    list.appendChild(li);
    //list.innerHTML+='<li>'+newtask.value+'</li>'
}