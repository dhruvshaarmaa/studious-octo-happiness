let value1=document.getElementById('value1');
let value2=document.getElementById('value2');
let value3=document.getElementById('value3');
let inpspeed=document.getElementById('inpspeed');
let values=['😍','😂','😡','😌','😇','😃','😆'];
let animationId;
function randomWithProbability() {
    var notRandomNumbers = [0,1,1,1,1,1,1,2,2,2,2,3,3,3,4,5,5,6];
    var idx = Math.floor(Math.random() * notRandomNumbers.length);
    return notRandomNumbers[idx];
  }
function getrandomvalue(){
    return values[randomWithProbability()];
}
function animationspeed(newspeed)
{
    if(animationId) clearInterval(animationId);
    animationId=setInterval(()=>{
        value1.innerText=getrandomvalue();
        value2.innerText=getrandomvalue();
        value3.innerText=getrandomvalue();
    },1000/newspeed);   
    if(newspeed==1) clearInterval(animationId);
}
animationspeed(2);
inpspeed.onchange=function(event){
    document.documentElement.style.setProperty('--speed',event.target.value);
    animationspeed(event.target.value);
}
let spin=document.getElementById("spin");
let result=document.getElementById("result");
spin.onclick=function(){
    result.innerText="";
    let i=20;
    runid=setInterval(() => {
        if(i==0)
        {
            clearInterval(animationId);
            clearInterval(runid);
        } 
        document.documentElement.style.setProperty('--speed',i);
        animationspeed(i+1);//changing emojis
        i--;

    }, 200);
    setTimeout(()=>{
        if(value1.innerText==value2.innerText && value2.innerText==value3.innerText)
    {
        console.log("Winner Winner Chicken Dinner");
        result.innerText="Winner Winner Chicken Dinner";
    }
    else
    {
        console.log("Better Luck Next Time!");
        result.innerText="Better Luck Next Time!";
    }
    },4700);
}
