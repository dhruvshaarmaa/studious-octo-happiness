let btnWait = document.getElementById("btnWait");
let btnCount = document.getElementById('btnCount');
let divStatus = document.getElementById('divStatus');
let divVal = document.getElementById('divVal');
let count=0;

btnCount.onclick=function(){
    count++;
    console.log(count);
    divVal.textContent=count;
}

btnWait.onclick=function(){
    divStatus.textContent="Waiting";
    console.log("Waiting");
    /*let start=Date.now();
    while(Date.now()<start+5000){
        //do nothing
    }*/
    setTimeout(function() {
        //do nothing
        console.log("Done");
        divStatus.textContent="Done";
    }, 5000);
    
}
