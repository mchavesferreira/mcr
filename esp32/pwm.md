
 ## Continuação Porta Serial
 
 Vamos completar os conhecimentos da aula anterior:
 
 Imprimindo e lendo na porta serial (UART)<BR>


<details><summary>Codigo Serial</summary>
<p>

```ruby
   Serial.begin(115200);
   Serial.println("Por favor qual o seu nome:");
   while (!Serial.available()); // Wait for input
   String name = Serial.readStringUntil('\n');
   Serial.print("Olá, ");
   Serial.print(name);
```

</p>
</details>


# PWM
<P>PWM - Simulando saída analógica
  
![Captura de tela 2024-05-15 234655](https://github.com/mchavesferreira/mcr/assets/63993080/4e8acc44-cb38-40cf-b4f8-5a76b4ce5f42)



![Captura de tela 2024-05-15 234802](https://github.com/mchavesferreira/mcr/assets/63993080/b953ab88-53c1-40ef-a830-76fd8ecae712)



02: <a href=https://wokwi.com/projects/341562296506516051>LED RGB e uso de analog_write() para PWM</a>
<P>Função Debounce e uso de condição de fluxo IF
<BR>03: <a href=https://wokwi.com/projects/341562149868405330>Alternando cores em LEDS</a>
<P>PWM e leitura analógia alterando RGB
<BR><a href=https://wokwi.com/projects/341599671301440083>PWM-Analog</a><P>


<P><a href=http://www.cdme.im-uff.mat.br/matrix/matrix-html/matrix_color_cube/matrix_color_cube_br.html>Tabela de cores RGB</a>
<P> 	




Exemplo da comunicação serial: https://wokwi.com/projects/397406587999082497


# TAREFA SUAP16/05/2024:

Exemplo:  https://wokwi.com/projects/397413115618262017

Utilize o exemplo da tarefa anterior, porém substititua apaneas ligar os LED por controle de intensidade PWM.

Criar o seguinte projeto com simulação ESP32, salve e envie a URL(endereço wokwi do projeto) em tarefa.

 - 4 Leds estão ligados respectivamente no pinos GPIO 21, 19, 18 e 5.
 - As 4 letras respectivamente Z, X, C e V acionam respectivamente cada um dos leds, devendo permanecer aceso o led da respectiva letra.
 - As letras estabelecem o tempo quando utilizadas na entrada serial: T <1000ms>, t <500 ms>  e U <100 ms>
 - A letra 'S' estabelece que o programa executará a sequência de pinos acionados e tempos
GPIO21, delay(300) GPIO18 delay(200) GPIO5
- A letra 'B' apaga todos os leds.
- A letra 'A' acende todos os leds.
