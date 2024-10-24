# MQTT

<BR>Comunicação de dados IOT utilizando protocolo MQTT
<img src=imagens/mqtt-publish-subscribe.png><br>Mqtt.org
<img src=imagens/mqtt_mensagem.png><BR>

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

Exemplo Wokwi, com tópico em IFSP/led<BR>

https://wokwi.com/projects/347942096378790483
