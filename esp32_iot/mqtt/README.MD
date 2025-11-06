# MQTT

<BR>Comunicação de dados IOT utilizando protocolo MQTT
<img src=../imagens/mqtt-publish-subscribe.png><br>Mqtt.org
<img src=../imagens/mqtt_mensagem.png><BR>

O MQTT (Message Queuing Telemetry Transport) é um protocolo de comunicação leve e eficiente, projetado para conectar dispositivos em redes com largura de banda limitada ou conexões instáveis, como em aplicações de Internet das Coisas (IoT). Ele utiliza o modelo de publicação/assinatura, onde os clientes podem publicar mensagens em tópicos específicos ou assinar tópicos para receber atualizações, com a intermediação de um servidor central chamado "broker". O MQTT é otimizado para minimizar o uso de recursos, sendo ideal para dispositivos com pouca capacidade de processamento e energia, como sensores e atuadores.

Saiba mais:  https://www.gta.ufrj.br/ensino/eel878/redes1-2019-1/vf/mqtt/


## Broker:

Utilizando um broker MQTT publico
	  http://www.hivemq.com/demos/websocket-client/
   <P><P>
Referências:<BR>
https://wiki.foz.ifpr.edu.br/wiki/index.php/Arduino:_MQTT
https://mqtt.org/
https://embarcados.com.br/mqtt-protocolos-para-iot/
https://aws.amazon.com/pt/what-is/mqtt/
https://embarcados.com.br/mqtt-protocolos-para-iot/


 
## O Protocolo MQTT em IOT
aula <BR>  http://smartcampus.ctd.ifsp.edu.br/blog/index.php?IDselecionado=48

Aplicativo: Dash MQTT  
https://play.google.com/store/apps/details?id=net.routix.mqttdash

Exemplo utilizando broker MQTT Público:  http://www.hivemq.com/demos/websocket-client/<BR>
Configure os campos:<BR>
host:  broker.hivemq.com<BR>
username: mchavesferreira<BR>
password: Embar2022<BR>
topic: movel/acelerax<BR>

## Exemplo Wokwi, com tópico em IFSP/led<BR>

Acesse o seguinte exemplo como aplição do mqtt, onde um led pode ser controlado seu status com o envio de mensagens para um broker

https://wokwi.com/projects/347942096378790483

<img src=imagens/mqtt1.png>

# Formato Json

## JSON

O JSON (JavaScript Object Notation) é um formato leve de troca de dados, fácil de ler e escrever para humanos, e simples de analisar e gerar para máquinas. A estrutura de um JSON é construída com base em duas estruturas universais:

Objetos: Um objeto JSON é uma coleção de pares chave/valor delimitados por chaves {}. Cada chave é uma string e é seguida por dois pontos : e o valor correspondente. Os pares chave/valor são separados por vírgulas. Por exemplo:

{
  "nome": "João",
  "idade": 30,
  "casado": true
}

<a href=https://github.com/mchavesferreira/sebe/blob/main/flow_exemplos/json.md> Saiba Mais sobre o Json</a>

### exemplo mqtt com mensagem em json

Acesse o seguinte exemplo como aplição do mqtt com json


<img src=imagens/mqtt2mensagem.png>


https://wokwi.com/projects/412639452245191681


Configure no seu dashboard para android o Path do objeto da mensagem, exemplo 

Topic= esp32/out

path Json= $.analogico

# 06/11/2025 MQTT e Json

Seguindo as instruções sobre MQTT e Json nesta url

e o exemplo de código

https://wokwi.com/projects/412639452245191681


Crie um novo script no wokwi e publique neste trabalho que contenha 2 leds controlados através de dois botões pushbutton , enviando o "status" on ou off de cada led, e duas entradas analógicas em fornato json.

Cada botão conectado ao esp32 deve ligar e desligar cada led, e pelo aplicativo também deve desligar.


Mostre os valores em seu aplicativo dashboard




