const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
.card{
    max-width: 400px;
     min-height: 250px;
     background: #02b875;
     padding: 30px;
     box-sizing: border-box;
     color: #FFF;
     margin:20px;
     box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>

<div class="card">
  <h4>Atualizacao da webpage ESP32 sem refresh utilizando ajax</h4><br>
  <h1>GPIO 32:<span id="ADCValue"></span></h1><br>
  <h1>GPIO 33:<span id="gpio1"></span></h1><br>
  <h1>GPIO 34:<span id="gpio2"></span></h1><br>
  <h1>Status:<span id="textoserial"></span></h1><br>

</div>
<script>

setInterval(function() {
  // chama cada função repetidamente a cada 2 segundos
  getData();
  getgpio1();
  getgpio2();
}, 2000); //2000mSeconds taxa de atualização

setInterval(function() {
  getgtexto();  // busca a url e substitui no ElementById
}, 5000); //5000mSeconds taxa de atualização


// funcoes de busca a url e substitui o valor retornado no campo ID no corpo do html
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    // verifica se url esta disponivel (cod. 200), bustitui o valor lido  no ID  ADCValue do html
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readADC", true);  // busca a url readADC por meio do metodo GET
  xhttp.send();
}

function getgpio1() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("gpio1").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "/readgpio1", true);
  xhttp.send();
}

function getgpio2() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("gpio2").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "/readgpio2", true);
  xhttp.send();
}

function  getgtexto() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    // verifica se url esta disponivel (cod. 200), bustitui o valor lido  no ID  textoserial do html
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("textoserial").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "/msgoled", true);  // busca a url readADC por meio do metodo GET
  xhttp.send();
}


</script>
</body>
</html>
)=====";