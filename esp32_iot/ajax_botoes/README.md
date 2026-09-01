# AJAX no ESP32

## Objetivo

Neste projeto, o ESP32 funciona como um **servidor Web**. A página HTML permite:

* visualizar as entradas analógicas dos GPIOs 32, 33 e 34;
* atualizar os valores automaticamente;
* ligar e desligar uma saída digital;
* realizar essas ações sem recarregar toda a página.

Isso é feito utilizando **AJAX**.

---

## O que é AJAX?

AJAX significa:

**Asynchronous JavaScript and XML**

Ele permite que o navegador envie requisições ao ESP32 e atualize apenas uma parte da página.

Por exemplo:

```text
Navegador → GET /readADC → ESP32 → valor ADC → navegador
```

Assim, somente o dado necessário é transmitido.

---

## Servidor Web no ESP32

O servidor é criado com:

```cpp
WebServer server(80);
```

As URLs são associadas a funções:

```cpp
server.on("/", handleRoot);

server.on("/readADC", handleADC);

server.on("/readgpio1", handlegpio1);

server.on("/readgpio2", handlegpio2);

server.on("/ligar", handleLigar);

server.on("/desligar", handleDesligar);
```

Por exemplo:

```cpp
server.on("/readADC", handleADC);
```

significa:

> Quando o navegador solicitar `/readADC`, execute `handleADC()`.

---

## Leitura do ADC

No JavaScript:

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

A linha:

```javascript
xhttp.open("GET", "/readADC", true);
```

configura uma requisição HTTP do tipo `GET`.

A linha:

```javascript
xhttp.send();
```

envia a requisição ao ESP32.

---

## Resposta do ESP32

O ESP32 recebe a solicitação e executa:

```cpp
void handleADC() {

  int a = analogRead(32);

  String adcValue = String(a);

  server.send(200, "text/plain", adcValue);
}
```

O valor do ADC é enviado ao navegador como texto.

Exemplo:

```text
2785
```

---

## Atualização da página

Quando a resposta chega, o JavaScript executa:

```javascript
document.getElementById("ADCValue").innerHTML =
this.responseText;
```

Na página existe:

```html
<span id="ADCValue"></span>
```

Somente esse elemento é alterado.

A página inteira não é recarregada.

---

## Atualização automática

As entradas analógicas são atualizadas a cada 2 segundos:

```javascript
setInterval(function() {

  getData();
  getgpio1();
  getgpio2();

}, 2000);
```

Portanto:

```text
2000 ms = 2 segundos
```

---

## Botões LIGAR e DESLIGAR

O botão:

```html
<button onclick="ligarSaida()">
  LIGAR
</button>
```

chama uma função JavaScript que envia:

```javascript
xhttp.open("GET", "/ligar", true);
```

O ESP32 recebe:

```text
GET /ligar
```

e executa:

```cpp
void handleLigar() {

  digitalWrite(SAIDA, HIGH);

  server.send(200, "text/plain", "LIGADO");
}
```

Para desligar:

```cpp
void handleDesligar() {

  digitalWrite(SAIDA, LOW);

  server.send(200, "text/plain", "DESLIGADO");
}
```

---

## Fluxo geral

```text
Página Web
    │
    ▼
JavaScript
    │
    ▼
AJAX / HTTP GET
    │
    ▼
ESP32 WebServer
    │
    ▼
Função correspondente
    │
    ├── analogRead()
    │
    └── digitalWrite()
    │
    ▼
Resposta HTTP
    │
    ▼
JavaScript atualiza a página
```

---

## Papel de `server.handleClient()`

No programa principal:

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

verifica continuamente se chegou uma nova requisição HTTP.

---

## Principais conceitos

Este projeto permite estudar:

* ESP32 como servidor Web;
* protocolo HTTP;
* método `GET`;
* HTML;
* JavaScript;
* AJAX;
* `XMLHttpRequest`;
* atualização dinâmica da página;
* leitura de ADC;
* controle de GPIO;
* arquitetura cliente-servidor.

---

## Resumo

O AJAX permite que o navegador troque pequenas quantidades de dados com o ESP32 sem recarregar toda a página.

Exemplo de leitura:

```text
getData()
   ↓
GET /readADC
   ↓
handleADC()
   ↓
analogRead(32)
   ↓
valor ADC
   ↓
atualização do HTML
```

Exemplo de comando:

```text
Botão LIGAR
   ↓
GET /ligar
   ↓
handleLigar()
   ↓
digitalWrite(SAIDA, HIGH)
```

Dessa forma, o ESP32 pode fornecer uma interface Web simples e dinâmica para monitoramento e controle de entradas e saídas.
