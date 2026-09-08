const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
<meta name="viewport" content="width=device-width, initial-scale=1">

<style>
body{
    font-family: Arial, Helvetica, sans-serif;
    background-color: #f7e9f2;
}

.card{
    max-width: 520px;
    min-height: 420px;
    background: #ffffff;
    padding: 25px;
    box-sizing: border-box;
    color: #402c45;
    margin: 20px auto;
    border-radius: 15px;
    box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.35);
}

h1{
    color: #7b2c83;
    text-align: center;
}

.status{
    background-color: #fff0f6;
    border-left: 6px solid #db3f8d;
    padding: 12px;
    margin-bottom: 15px;
}

.resumo{
    background-color: #f3f3f3;
    padding: 12px;
    border-radius: 8px;
    line-height: 1.7;
}

.grupoBotoes{
    display: none;
    margin-top: 18px;
    text-align: center;
}

button{
    padding: 12px 18px;
    margin: 6px;
    font-size: 16px;
    border: none;
    border-radius: 6px;
    cursor: pointer;
    background-color: #7b2c83;
    color: white;
}

.verde{ background-color: #18864b; }
.rosa{ background-color: #db3f8d; }
.amarelo{ background-color: #cf9400; }
.cinza{ background-color: #646464; }

#processo{
    display: none;
    margin-top: 20px;
    padding: 18px;
    background-color: #fff4cf;
    border-radius: 8px;
    text-align: center;
    font-weight: bold;
}

.controlePedido{
    margin-top: 18px;
    text-align: center;
}

#novoPedido{
    display: none;
}
</style>
</head>

<body>

<div class="card">
  <h1>Sorveteria Doce Sabor</h1>

  <div class="status">
    <h2 id="tituloEtapa">Carregando...</h2>
    <span id="mensagem">Aguardando o ESP32</span>
  </div>

  <div class="resumo">
    <b>Numero de bolas:</b> <span id="bolas">1</span><br>
    <b>Sabor:</b> <span id="sabor">-</span><br>
    <b>Cobertura:</b> <span id="cobertura">-</span><br>
    <b>Recipiente:</b> <span id="recipiente">-</span>
  </div>

  <div id="pergunta1" class="grupoBotoes">
    <button class="cinza" onclick="enviarComando('/menos')">- 1 bola</button>
    <button class="verde" onclick="enviarComando('/mais')">+ 1 bola</button>
    <button class="rosa" onclick="enviarComando('/confirmar')">Confirmar</button>
  </div>

  <div id="pergunta2" class="grupoBotoes">
    <button class="amarelo" onclick="enviarComando('/sabor1')">Ovomaltine</button>
    <button class="rosa" onclick="enviarComando('/sabor2')">Mamao</button>
    <button class="verde" onclick="enviarComando('/sabor3')">Tutti-frutti</button>
  </div>

  <div id="pergunta3" class="grupoBotoes">
    <button class="amarelo" onclick="enviarComando('/cobertura1')">Chocolate</button>
    <button class="rosa" onclick="enviarComando('/cobertura2')">Chiclete</button>
    <button class="verde" onclick="enviarComando('/cobertura3')">Doce de leite</button>
  </div>

  <div id="pergunta4" class="grupoBotoes">
    <button class="verde" onclick="enviarComando('/recipiente1')">Pequeno</button>
    <button class="rosa" onclick="enviarComando('/recipiente2')">Medio</button>
    <button class="amarelo" onclick="enviarComando('/recipiente3')">Grande</button>
  </div>

  <div id="processo">
    Pedido em processamento. Acompanhe a etapa acima.
  </div>

  <div id="reiniciarPedido" class="controlePedido">
    <button class="cinza" onclick="enviarComando('/reiniciar')">
      Reiniciar escolhas ou pedido
    </button>
  </div>

  <div id="novoPedido" class="controlePedido">
    <button class="verde" onclick="enviarComando('/reiniciar')">
      Fazer novo pedido
    </button>
  </div>
</div>


<script>

// Atualiza as informacoes sem recarregar a pagina
setInterval(function() {
  getEstado();
  getBolas();
  getSabor();
  getCobertura();
  getRecipiente();
  getMensagem();
}, 500);


function getEstado() {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {

      var estado = parseInt(this.responseText);

      document.getElementById("pergunta1").style.display = "none";
      document.getElementById("pergunta2").style.display = "none";
      document.getElementById("pergunta3").style.display = "none";
      document.getElementById("pergunta4").style.display = "none";
      document.getElementById("processo").style.display = "none";
      document.getElementById("reiniciarPedido").style.display = "block";
      document.getElementById("novoPedido").style.display = "none";

      if (estado == 0) {
        document.getElementById("tituloEtapa").innerHTML = "1 - Numero de bolas";
        document.getElementById("pergunta1").style.display = "block";
      }

      if (estado == 1) {
        document.getElementById("tituloEtapa").innerHTML = "2 - Escolha do sabor";
        document.getElementById("pergunta2").style.display = "block";
      }

      if (estado == 2) {
        document.getElementById("tituloEtapa").innerHTML = "3 - Escolha da cobertura";
        document.getElementById("pergunta3").style.display = "block";
      }

      if (estado == 3) {
        document.getElementById("tituloEtapa").innerHTML = "4 - Escolha do recipiente";
        document.getElementById("pergunta4").style.display = "block";
      }

      if (estado >= 4) {
        document.getElementById("processo").style.display = "block";
      }

      if (estado == 4) document.getElementById("tituloEtapa").innerHTML = "Adicionando as bolas";
      if (estado == 5) document.getElementById("tituloEtapa").innerHTML = "Adicionando o sabor";
      if (estado == 6) document.getElementById("tituloEtapa").innerHTML = "Adicionando a cobertura";
      if (estado == 7) {
        document.getElementById("tituloEtapa").innerHTML = "Pedido pronto";
        document.getElementById("reiniciarPedido").style.display = "none";
        document.getElementById("novoPedido").style.display = "block";
      }
    }
  };

  xhttp.open("GET", "/estado", true);
  xhttp.send();
}


function atualizarCampo(url, campo) {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {
      document.getElementById(campo).innerHTML = this.responseText;
    }
  };

  xhttp.open("GET", url, true);
  xhttp.send();
}


function getBolas() {
  atualizarCampo("/bolas", "bolas");
}

function getSabor() {
  atualizarCampo("/sabor", "sabor");
}

function getCobertura() {
  atualizarCampo("/cobertura", "cobertura");
}

function getRecipiente() {
  atualizarCampo("/recipiente", "recipiente");
}

function getMensagem() {
  atualizarCampo("/mensagem", "mensagem");
}


function enviarComando(url) {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {
      getEstado();
      getBolas();
      getSabor();
      getCobertura();
      getRecipiente();
      getMensagem();
    }
  };

  xhttp.open("GET", url, true);
  xhttp.send();
}


getEstado();
getBolas();
getSabor();
getCobertura();
getRecipiente();
getMensagem();

</script>

</body>
</html>

)=====";
