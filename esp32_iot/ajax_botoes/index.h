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

button{
    padding: 12px 25px;
    margin: 8px;
    font-size: 18px;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}

.botaoLigar{
    background-color: #1b5e20;
    color: white;
}

.botaoDesligar{
    background-color: #b71c1c;
    color: white;
}

#estadoSaida{
    font-weight: bold;
}

</style>

<body>

<div class="card">

  <h4>Atualizacao da webpage ESP32 sem refresh utilizando AJAX</h4><br>

  <h1>GPIO 32:
    <span id="ADCValue"></span>
  </h1><br>

  <h1>GPIO 33:
    <span id="gpio1"></span>
  </h1><br>

  <h1>GPIO 34:
    <span id="gpio2"></span>
  </h1><br>

  <h1>Status:
    <span id="textoserial"></span>
  </h1><br>


  <!-- Controle da saída digital -->

  <h2>Controle GPIO 25</h2>

  <button class="botaoLigar" onclick="ligarSaida()">
    LIGAR
  </button>

  <button class="botaoDesligar" onclick="desligarSaida()">
    DESLIGAR
  </button>

  <h2>Saida:
    <span id="estadoSaida">DESLIGADO</span>
  </h2>

</div>


<script>


//=============================================================
// Atualização das entradas analógicas
//=============================================================

setInterval(function() {

  // chama cada função repetidamente a cada 2 segundos

  getData();
  getgpio1();
  getgpio2();

}, 2000);


//=============================================================
// Atualização do texto
//=============================================================

setInterval(function() {

  getgtexto();

}, 5000);


//=============================================================
// GPIO 32
//=============================================================

function getData() {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    // verifica se URL esta disponivel (cod. 200)

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("ADCValue").innerHTML =
      this.responseText;

    }

  };

  xhttp.open("GET", "/readADC", true);

  xhttp.send();
}


//=============================================================
// GPIO 33
//=============================================================

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


//=============================================================
// GPIO 34
//=============================================================

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


//=============================================================
// Texto de status
//=============================================================

function getgtexto() {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("textoserial").innerHTML =
      this.responseText;

    }

  };

  xhttp.open("GET", "/msgoled", true);

  xhttp.send();
}


//=============================================================
// Botão LIGAR
//=============================================================

function ligarSaida() {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("estadoSaida").innerHTML =
      this.responseText;

    }

  };

  xhttp.open("GET", "/ligar", true);

  xhttp.send();
}


//=============================================================
// Botão DESLIGAR
//=============================================================

function desligarSaida() {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("estadoSaida").innerHTML =
      this.responseText;

    }

  };

  xhttp.open("GET", "/desligar", true);

  xhttp.send();
}


</script>

</body>

</html>

)=====";
