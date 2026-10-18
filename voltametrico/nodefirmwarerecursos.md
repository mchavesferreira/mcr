## Recursos da interface e do firmware do potenciostato didático

https://chatgpt.com/s/t_6ad53ddb53008191a816770421ce80ca


A interface desenvolvida em **Node-RED Dashboard 2.0** permite configurar, acompanhar e registrar ensaios de voltametria cíclica realizados pelo potenciostato microcontrolado. O usuário pode definir os principais parâmetros experimentais, incluindo **potencial inicial, potenciais de vértice, potencial final, passo de tensão, velocidade de varredura, número de ciclos, tempo de estabilização inicial, intervalo entre aquisições e número de amostras utilizadas na leitura do ADC**.

A interface também permite a seleção manual de uma das **quatro faixas de transimpedância** do equipamento. Cada faixa é associada à sua região experimentalmente validada, permitindo impedir a configuração de tensões incompatíveis com a faixa escolhida. O ganho 0 é destinado às menores correntes e apresenta a maior sensibilidade, enquanto os ganhos 1, 2 e 3 permitem progressivamente ampliar a faixa dinâmica do instrumento.

Durante a execução da voltametria, o Dashboard apresenta em tempo real o **estado do ensaio**, o potencial aplicado, a corrente calculada, a tensão na entrada do ADS1115, o ganho ativo, o ciclo atual e indicadores da qualidade da aquisição. O voltamograma é construído dinamicamente como gráfico de **corrente em função do potencial**, permitindo acompanhar visualmente o desenvolvimento dos ciclos e comparar suas repetições.

A interface também dispõe de comandos para **interromper o ensaio**, retornar o potencial para zero e selecionar se os resultados serão armazenados no banco de dados. Para cada experimento é possível informar o nome da amostra e observações, permitindo a organização dos ensaios realizados em atividades didáticas ou experimentais.

### Firmware embarcado

O firmware desenvolvido para o **ESP32-S3** realiza o controle dos conversores MCP4725 e ADS1115, das faixas de ganho do amplificador de transimpedância e da comunicação MQTT com o Node-RED.

A rotina de voltametria cíclica foi implementada utilizando uma **máquina de estados não bloqueante**, permitindo que a comunicação MQTT continue ativa durante todo o experimento. Dessa forma, comandos de interrupção podem ser recebidos mesmo durante uma varredura em andamento.

A sequência de potencial é executada segundo os parâmetros definidos pelo usuário:

\[
V_{start}\rightarrow V_{vertex1}\rightarrow V_{vertex2}
\rightarrow V_{vertex1}\rightarrow \cdots \rightarrow V_{end}
\]

permitindo a realização de múltiplos ciclos consecutivos.

O intervalo temporal entre os pontos é calculado a partir do passo de tensão e da velocidade de varredura:

\[
\Delta t=\frac{\Delta V}{v}
\]

sendo respeitado também um intervalo mínimo definido na interface. Após cada alteração do DAC, o firmware aguarda um tempo de acomodação configurável antes da aquisição do sinal.

### Aquisição e tratamento dos sinais

Em cada ponto da varredura são realizadas múltiplas leituras do ADS1115. A partir dessas amostras são calculados:

- valor RAW médio;
- valor RAW mínimo e máximo;
- desvio padrão;
- tensão correspondente na entrada do ADC;
- corrente obtida pela calibração experimental da faixa ativa.

A utilização do desvio padrão permite identificar leituras instáveis ou excessivamente ruidosas. O firmware também verifica se a tensão medida permanece dentro da região segura da cadeia analógica, classificando cada ponto como normal, ruidoso ou próximo da saturação.

A corrente não é calculada apenas pelos valores nominais dos resistores. Para cada uma das quatro faixas são utilizadas as **equações experimentais obtidas durante a caracterização do circuito**, permitindo incorporar os efeitos reais do TIA, dos resistores, do ADG444, dos amplificadores e do estágio de condicionamento.

### Controle das faixas de ganho

O firmware controla três entradas digitais do ESP32-S3 conectadas ao ADG444 por meio de optoacopladores. A configuração sem chave ativada utiliza o resistor base de **10 MΩ**, enquanto as demais faixas são obtidas pela associação paralela dos resistores de 15 kΩ, 150 kΩ e 2 MΩ.

As quatro configurações disponíveis são aproximadamente:

\[
G_0=10\,M\Omega
\]

\[
G_1\approx14,98\,k\Omega
\]

\[
G_2\approx147,78\,k\Omega
\]

\[
G_3\approx1,667\,M\Omega
\]

Essa arquitetura permite conciliar alta sensibilidade para correntes da ordem de nanoampères com faixas de menor ganho destinadas a sinais de maior amplitude.

### Comunicação MQTT

A comunicação entre o ESP32-S3 e o Node-RED é realizada por MQTT. O sistema utiliza tópicos específicos para:

```text
comandos
leituras
status
```

Os comandos são enviados em formato JSON, enquanto cada ponto adquirido é publicado juntamente com informações experimentais como ciclo, segmento da varredura, potencial aplicado, DAC RAW, ADC RAW, corrente, ganho utilizado e indicadores de qualidade.

Cada ensaio recebe um identificador único, permitindo relacionar todas as amostras ao experimento correspondente.

### Armazenamento dos experimentos

O sistema permite salvar os ensaios em banco de dados **MySQL**. A estrutura foi dividida em duas tabelas principais.

A primeira registra as informações gerais do ensaio, incluindo:

```text
identificação da amostra
parâmetros da voltametria
faixa de ganho
número de ciclos
velocidade de varredura
data e horário
estado do experimento
```

A segunda registra individualmente cada ponto da curva, armazenando:

```text
potencial
corrente
DAC RAW
ADC RAW
tensão do ADC
desvio padrão
ganho
ciclo
segmento
tempo decorrido
qualidade da leitura
```

Essa organização permite reconstruir posteriormente qualquer voltamograma e facilita análises comparativas entre diferentes amostras, concentrações, eletrodos e condições experimentais.

### Síntese

A combinação do firmware embarcado com a interface Node-RED transforma o protótipo em uma plataforma experimental didática capaz de realizar voltametria cíclica configurável, acompanhar os resultados em tempo real e registrar integralmente os dados obtidos. A arquitetura permite explorar conceitos de **eletroquímica, instrumentação analógica, conversão A/D e D/A, sistemas embarcados, comunicação MQTT, bancos de dados e processamento de sinais**, mantendo ainda a possibilidade de futuras extensões, como seleção automática de ganho, novas técnicas voltamétricas e aplicação de métodos de aprendizado de máquina aos sinais eletroquímicos.
