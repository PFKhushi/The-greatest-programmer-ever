console.log("Hello, dude")

const fs = require('fs');
fs.writeFile(__dirname + "/index.html", "<h1>Html is gsssead<h1>", function (error) {
        if(error){
                return console.log(error);
        }else{
                return console.log("Deu tudo certo" + error);
        }        

});
