# Funcionamento do AJAX no projeto com ESP32

## 1. Objetivo

Neste projeto, o ESP32 funciona como um pequeno **servidor Web**.  
Uma página HTML armazenada no próprio microcontrolador é enviada ao navegador do usuário.

A página permite:

- visualizar os valores analógicos dos GPIOs 32, 33 e 34;
- atualizar esses valores automaticamente;
- receber mensagens enviadas pelo ESP32;
- ligar uma saída digital;
- desligar uma saída digital.

A principal característica do projeto é que essas operações acontecem **sem recarregar completamente a página Web**.

Isso é realizado utilizando **AJAX**.

---

# 2. O que é AJAX?

AJAX significa:

**Asynchronous JavaScript and XML**

ou, em português:

**JavaScript Assíncrono e XML**.

Apesar do nome mencionar XML, atualmente AJAX pode ser utilizado para receber vários tipos de dados, como:

- texto;
- JSON;
- XML;
- HTML;
- valores numéricos.

Neste projeto, o ESP32 retorna principalmente **texto simples**, como:

```text
2450
```

ou:

```text
LIGADO
```

O AJAX permite que o navegador envie uma requisição ao ESP32 e receba apenas o dado necessário, sem precisar carregar novamente todo o arquivo HTML.

---

# 3. Funcionamento geral

O sistema pode ser representado da seguinte forma:

```text
┌─────────────────────────┐
│       Navegador         │
│                         │
│ HTML + CSS + JavaScript │
└────────────┬────────────┘
             │
             │ Requisição HTTP
             │ AJAX
             ▼
┌─────────────────────────┐
│          ESP32          │
│                         │
│      WebServer          │
└────────────┬────────────┘
             │
             ▼
      Leitura ou ação
             │
             ▼
┌─────────────────────────┐
│ GPIO / ADC / Variáveis  │
└─────────────────────────┘
```

O navegador solicita informações ao ESP32 por meio de diferentes URLs.

Exemplos:

```text
/readADC
/readgpio1
/readgpio2
/msgoled
/ligar
/desligar
```

Cada URL é associada a uma função no programa do ESP32.

---

# 4. Servidor Web no ESP32

O programa utiliza a biblioteca:

```cpp
#include <WebServer.h>
```

e cria um servidor HTTP na porta 80:

```cpp
WebServer server(80);
```

A porta 80 é a porta padrão utilizada pelo protocolo HTTP.

Assim, quando o navegador acessa:

```text
http://IP_DO_ESP32/
```

o navegador estabelece uma comunicação HTTP com o ESP32.

---

# 5. Página principal

No programa principal existe a função:

```cpp
void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}
```

A rota correspondente é registrada com:

```cpp
server.on("/", handleRoot);
```

Quando o navegador solicita:

```text
/
```

o ESP32 executa:

```cpp
handleRoot()
```

e retorna a página HTML armazenada na variável:

```cpp
MAIN_page
```

que está no arquivo:

```text
index.h
```

---

# 6. Atualização sem refresh

Sem AJAX, para visualizar um novo valor do ADC seria necessário atualizar toda a página.

O processo seria:

```text
Navegador
    ↓
Solicita página completa
    ↓
ESP32 envia HTML completo
    ↓
Navegador redesenha a página
```

Com AJAX, somente o valor necessário é solicitado.

Por exemplo:

```text
Navegador
    ↓
GET /readADC
    ↓
ESP32 lê GPIO 32
    ↓
ESP32 responde "2478"
    ↓
JavaScript altera apenas o valor mostrado na tela
```

Isso torna a comunicação mais rápida e reduz a quantidade de dados transmitidos.

---

# 7. XMLHttpRequest

Neste projeto, o AJAX é implementado utilizando o objeto JavaScript:

```javascript
XMLHttpRequest
```

Por exemplo:

```javascript
var xhttp = new XMLHttpRequest();
```

Esse objeto permite que o JavaScript faça uma requisição HTTP ao ESP32.

---

# 8. Exemplo: leitura do GPIO 32

A função JavaScript utilizada é:

```javascript
function getData() {

  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("ADCValue").innerHTML =
      this.responseText;

    }

  };

  xhttp.open("GET", "/readADC", true);

  xhttp.send();
}
```

Vamos analisar cada parte.

---

## 8.1 Criação da requisição

```javascript
var xhttp = new XMLHttpRequest();
```

Cria um objeto responsável pela comunicação HTTP.

---

## 8.2 Monitoramento da resposta

```javascript
xhttp.onreadystatechange = function() {
```

Essa função é executada sempre que o estado da requisição muda.

---

## 8.3 Verificação da resposta

```javascript
if (this.readyState == 4 && this.status == 200)
```

Existem duas verificações importantes.

### readyState

O valor:

```text
4
```

significa que a requisição foi concluída.

Os principais valores de `readyState` são:

| Valor | Significado |
|---:|---|
| 0 | requisição ainda não inicializada |
| 1 | conexão configurada |
| 2 | requisição recebida pelo servidor |
| 3 | resposta sendo recebida |
| 4 | operação concluída |

### status

O valor:

```text
200
```

é um código HTTP que significa:

```text
OK
```

Portanto:

```javascript
if (this.readyState == 4 && this.status == 200)
```

significa:

> Se a requisição terminou corretamente e o servidor respondeu com sucesso.

---

# 9. Solicitando uma URL ao ESP32

A linha:

```javascript
xhttp.open("GET", "/readADC", true);
```

configura a requisição.

Os parâmetros são:

```javascript
xhttp.open(metodo, URL, assincrono);
```

Neste projeto:

```javascript
"GET"
```

é o método HTTP utilizado.

```javascript
"/readADC"
```

é a URL solicitada.

```javascript
true
```

indica que a comunicação será assíncrona.

---

# 10. Enviando a requisição

Depois de configurar a requisição, ela é enviada com:

```javascript
xhttp.send();
```

Nesse momento o navegador envia aproximadamente:

```text
GET /readADC HTTP/1.1
```

para o ESP32.

---

# 11. Tratamento da requisição no ESP32

No `setup()` existe:

```cpp
server.on("/readADC", handleADC);
```

Isso significa:

> Quando o navegador solicitar `/readADC`, execute a função `handleADC()`.

A função é:

```cpp
void handleADC() {

  int a = analogRead(32);

  String adcValue = String(a);

  server.send(200, "text/plain", adcValue);
}
```

O ESP32:

1. realiza a leitura analógica;
2. converte o valor para uma `String`;
3. responde ao navegador.

---

# 12. Resposta HTTP do ESP32

A instrução:

```cpp
server.send(200, "text/plain", adcValue);
```

possui três parâmetros principais:

```cpp
server.send(codigo, tipo, conteudo);
```

Neste exemplo:

```cpp
200
```

significa:

```text
HTTP OK
```

O parâmetro:

```cpp
"text/plain"
```

indica que o conteúdo enviado é texto simples.

E:

```cpp
adcValue
```

contém o valor convertido do ADC.

Uma resposta poderia ser:

```text
2876
```

---

# 13. Atualização de apenas um elemento da página

Depois que o valor retorna ao navegador, o JavaScript executa:

```javascript
document.getElementById("ADCValue").innerHTML =
this.responseText;
```

Na página existe:

```html
<span id="ADCValue"></span>
```

O JavaScript localiza esse elemento utilizando:

```javascript
document.getElementById("ADCValue")
```

e altera apenas o seu conteúdo.

Se o ESP32 respondeu:

```text
2876
```

o navegador passa a exibir:

```text
GPIO 32: 2876
```

sem carregar novamente toda a página.

---

# 14. Atualização automática usando setInterval()

As leituras analógicas são atualizadas utilizando:

```javascript
setInterval(function() {

  getData();
  getgpio1();
  getgpio2();

}, 2000);
```

O valor:

```text
2000
```

está em milissegundos.

Portanto:

```text
2000 ms = 2 segundos
```

A cada 2 segundos são chamadas as funções:

```javascript
getData();
getgpio1();
getgpio2();
```

Assim, o navegador solicita automaticamente os valores dos três ADCs.

---

# 15. Fluxo completo da leitura do GPIO 32

O processo completo é:

```text
A cada 2 segundos
       │
       ▼
JavaScript chama getData()
       │
       ▼
Cria XMLHttpRequest
       │
       ▼
GET /readADC
       │
       ▼
ESP32 recebe requisição
       │
       ▼
handleADC()
       │
       ▼
analogRead(32)
       │
       ▼
server.send(...)
       │
       ▼
Navegador recebe o valor
       │
       ▼
responseText
       │
       ▼
innerHTML
       │
       ▼
Valor aparece na página
```

---

# 16. Leitura dos GPIOs 33 e 34

O funcionamento das outras entradas analógicas é semelhante.

Para o GPIO 33:

```javascript
xhttp.open("GET", "/readgpio1", true);
```

No ESP32:

```cpp
server.on("/readgpio1", handlegpio1);
```

A função executada é:

```cpp
void handlegpio1() {

  int b = analogRead(33);

  String adcValue = String(b);

  server.send(200, "text/plain", adcValue);
}
```

Para o GPIO 34:

```javascript
xhttp.open("GET", "/readgpio2", true);
```

No ESP32:

```cpp
server.on("/readgpio2", handlegpio2);
```

---

# 17. Botão LIGAR

O botão HTML é definido como:

```html
<button class="botaoLigar" onclick="ligarSaida()">
  LIGAR
</button>
```

Quando o usuário clica no botão, é chamada:

```javascript
ligarSaida()
```

A função realiza:

```javascript
xhttp.open("GET", "/ligar", true);
xhttp.send();
```

O navegador solicita:

```text
/ligar
```

---

# 18. Rota /ligar no ESP32

No ESP32:

```cpp
server.on("/ligar", handleLigar);
```

Ao receber a requisição, é executada:

```cpp
void handleLigar() {

  digitalWrite(SAIDA, HIGH);

  server.send(200, "text/plain", "LIGADO");
}
```

A saída digital é colocada em nível lógico alto:

```cpp
HIGH
```

Depois o ESP32 responde:

```text
LIGADO
```

---

# 19. Atualizando o estado da saída

A resposta é recebida pelo JavaScript:

```javascript
document.getElementById("estadoSaida").innerHTML =
this.responseText;
```

Na página existe:

```html
<span id="estadoSaida">DESLIGADO</span>
```

Depois do clique, esse elemento passa a apresentar:

```text
LIGADO
```

---

# 20. Botão DESLIGAR

O botão:

```html
<button class="botaoDesligar" onclick="desligarSaida()">
  DESLIGAR
</button>
```

chama:

```javascript
desligarSaida()
```

que solicita:

```text
/desligar
```

No ESP32:

```cpp
server.on("/desligar", handleDesligar);
```

A função:

```cpp
void handleDesligar() {

  digitalWrite(SAIDA, LOW);

  server.send(200, "text/plain", "DESLIGADO");
}
```

coloca a saída em nível lógico baixo.

---

# 21. Fluxo do botão LIGAR

```text
Usuário clica em LIGAR
          │
          ▼
onclick="ligarSaida()"
          │
          ▼
JavaScript
          │
          ▼
GET /ligar
          │
          ▼
ESP32 WebServer
          │
          ▼
handleLigar()
          │
          ▼
digitalWrite(GPIO, HIGH)
          │
          ▼
Resposta "LIGADO"
          │
          ▼
JavaScript recebe responseText
          │
          ▼
Atualiza estadoSaida
```

---

# 22. Comparação: página tradicional e AJAX

## Página tradicional

```text
Usuário solicita informação
        ↓
Servidor gera página completa
        ↓
HTML completo é transmitido
        ↓
Página inteira é atualizada
```

## Utilizando AJAX

```text
JavaScript solicita apenas um dado
        ↓
Servidor responde apenas aquele dado
        ↓
JavaScript altera somente parte da página
```

Isso reduz:

- tráfego de rede;
- tempo de atualização;
- processamento;
- quantidade de dados enviados pelo ESP32.

---

# 23. Por que AJAX é interessante em sistemas embarcados?

Microcontroladores possuem recursos limitados quando comparados a computadores convencionais.

O ESP32 possui limitações de:

- memória RAM;
- processamento;
- armazenamento;
- largura de banda;
- número simultâneo de conexões.

Por isso, transmitir somente as informações necessárias é vantajoso.

AJAX permite construir interfaces Web relativamente dinâmicas sem exigir que o ESP32 gere repetidamente uma página inteira.

---

# 24. Estrutura cliente-servidor

Neste projeto existem dois elementos principais.

## Cliente

O navegador Web.

Exemplos:

```text
Chrome
Firefox
Edge
Safari
```

O cliente executa:

- HTML;
- CSS;
- JavaScript;
- AJAX.

## Servidor

O ESP32.

Ele executa:

- leitura dos ADCs;
- controle das saídas;
- processamento das rotas HTTP;
- envio das respostas.

---

# 25. Relação entre URL e função

Cada URL solicitada pelo navegador está associada a uma função no ESP32.

| URL | Função ESP32 | Operação |
|---|---|---|
| `/` | `handleRoot()` | envia a página Web |
| `/readADC` | `handleADC()` | lê GPIO 32 |
| `/readgpio1` | `handlegpio1()` | lê GPIO 33 |
| `/readgpio2` | `handlegpio2()` | lê GPIO 34 |
| `/msgoled` | `handlemsgoled()` | envia uma mensagem |
| `/ligar` | `handleLigar()` | liga a saída |
| `/desligar` | `handleDesligar()` | desliga a saída |

Esse mapeamento é realizado com:

```cpp
server.on(URL, funcao);
```

Por exemplo:

```cpp
server.on("/ligar", handleLigar);
```

---

# 26. O papel de server.handleClient()

Dentro do `loop()` existe:

```cpp
void loop() {

  server.handleClient();

  delay(1);
}
```

A função:

```cpp
server.handleClient();
```

verifica constantemente se algum navegador enviou uma nova requisição HTTP.

Quando uma requisição chega, o servidor identifica a URL e executa a função correspondente.

Por isso essa instrução precisa ser executada repetidamente.

---

# 27. Conceito de comunicação assíncrona

No comando:

```javascript
xhttp.open("GET", "/readADC", true);
```

o último parâmetro:

```javascript
true
```

indica funcionamento assíncrono.

Isso significa que o navegador não precisa interromper toda a execução da página enquanto aguarda a resposta do ESP32.

Enquanto a requisição é processada, a interface continua funcionando.

Quando a resposta chega, a função:

```javascript
onreadystatechange
```

é executada.

---

# 28. Resumo do projeto

O funcionamento geral pode ser resumido em cinco etapas:

```text
1. JavaScript gera a requisição
              ↓
2. AJAX envia GET para o ESP32
              ↓
3. WebServer identifica a rota
              ↓
4. ESP32 executa a função
              ↓
5. Resposta altera parte da página
```

Exemplo:

```text
getData()
    ↓
GET /readADC
    ↓
handleADC()
    ↓
analogRead(32)
    ↓
"2456"
    ↓
ADCValue.innerHTML = "2456"
```

---

# 29. Conceitos estudados neste experimento

Este projeto permite estudar simultaneamente vários conceitos importantes:

- arquitetura cliente-servidor;
- servidor Web embarcado;
- protocolo HTTP;
- método HTTP GET;
- códigos de resposta HTTP;
- HTML;
- CSS;
- JavaScript;
- AJAX;
- XMLHttpRequest;
- atualização dinâmica do DOM;
- temporização com `setInterval()`;
- conversão analógico-digital;
- GPIO;
- controle remoto de saídas digitais;
- sistemas embarcados conectados à rede.

---

# 30. Conclusão

O AJAX permite criar uma interface Web dinâmica para o ESP32 sem a necessidade de atualizar completamente a página a cada nova leitura ou comando.

No projeto apresentado, o navegador funciona como cliente e o ESP32 como servidor.

O JavaScript envia requisições HTTP utilizando `XMLHttpRequest`, enquanto o ESP32 identifica cada URL através da função:

```cpp
server.on()
```

As leituras dos ADCs são enviadas periodicamente ao navegador e os comandos dos botões são convertidos em requisições HTTP.

Dessa maneira, o projeto demonstra de forma prática a integração entre:

```text
HTML
   +
CSS
   +
JavaScript
   +
AJAX
   +
HTTP
   +
ESP32
   +
GPIO / ADC
```

criando uma pequena **Interface Homem-Máquina Web embarcada**.
