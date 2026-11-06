//MAIN FUNCTION
document.addEventListener("DOMContentLoaded" , () => {
    var btn = document.getElementById("change");
    var box = document.getElementById('box') ;
    var visible = true;

    btn.addEventListener ('click' , ()=>{

        let student = {
            "name" : "Ali",
            "age" : 22
        }

        for(let i = 0 ; i <= 10 ; i++){

        }

        var x = 10;
        while(x > 0){
            // logic
            x--;
        }
//  >    >=    <    <=     == ('10'==10)T   !=      &&    ||      ===('10'===10)F
        const name = ["One" , "Two" , "Three"]
        for (let i = 0 ; i < 3 ; i++){
            console.log("Element = "+ name[i]);
        }


        // Change any property of box
        if(visible){
            box.style.display = 'none';
            btn.innerText = "SHOW";
        }else{
            box.style.display = 'block';
            btn.innerText = "HIDE";
            box.style.backgroundColor = 'red';
        }
        visible = !visible;
        console.log(name);
    });
});