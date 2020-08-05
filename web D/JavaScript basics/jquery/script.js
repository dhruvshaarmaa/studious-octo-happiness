//console.log($("list")); empty object as window is not loaded
$(()=>{
    let list=$("#list");
    let item=$('#item');
    let append=$("#append");
    let prepend=$("#prepend");
    append.click(()=>{
        let text=item.val();
        list.append($(`<li>${text}</li>`));
    })
    prepend.click(()=>{
        let text=item.val();
        list.prepend($('<li>').text(text));
    })
})