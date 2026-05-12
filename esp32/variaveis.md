# Variáveis e Tipos de Dados no Arduino

As variáveis são utilizadas para armazenar informações temporariamente na memória do microcontrolador, permitindo manipular valores numéricos, caracteres, textos e estados lógicos durante a execução do programa. O Arduino possui diversos tipos de dados, cada um adequado para uma finalidade específica.


---

## `bool`

O tipo `bool` armazena apenas dois estados lógicos: `true` (verdadeiro) ou `false` (falso). É muito utilizado em controle de estados, acionamento de dispositivos e verificações condicionais em sistemas embarcados.

```cpp
bool ledLigado = true;

void setup() {
  Serial.begin(115200);

  if(ledLigado) {
    Serial.println("LED ligado");
  }
}

void loop() {
}
```

---

## `boolean`

`boolean` possui a mesma finalidade do tipo `bool`, sendo utilizado para armazenar valores lógicos. Historicamente era muito usado em versões antigas do Arduino, porém atualmente recomenda-se utilizar `bool`.

```cpp
boolean sensorAtivo = false;

void setup() {
  Serial.begin(115200);

  Serial.println(sensorAtivo);
}

void loop() {
}
```

---

## `byte`

O tipo `byte` armazena números inteiros sem sinal de 0 até 255 utilizando apenas 8 bits. É muito utilizado em registradores, comunicação I2C, SPI e manipulação de portas digitais.

```cpp
byte valor = 255;

void setup() {
  Serial.begin(115200);

  Serial.println(valor);
}

void loop() {
}
```

---

## `char`

O tipo `char` armazena um único caractere ASCII utilizando 8 bits. É amplamente utilizado em comunicação serial, manipulação de strings e protocolos de comunicação.

```cpp
char letra = 'A';

void setup() {
  Serial.begin(115200);

  Serial.println(letra);
}

void loop() {
}
```

---

## `double`

O tipo `double` armazena números de ponto flutuante com maior precisão. Em placas AVR como ATmega328P o `double` possui a mesma precisão do `float` (32 bits), enquanto no ESP32 ele utiliza 64 bits.

```cpp
double temperatura = 25.78;

void setup() {
  Serial.begin(115200);

  Serial.println(temperatura);
}

void loop() {
}
```

---

## `float`

O tipo `float` é utilizado para armazenar números reais com casas decimais. É muito usado em cálculos matemáticos, sensores analógicos e processamento de sinais.

```cpp
float tensao = 3.3;

void setup() {
  Serial.begin(115200);

  Serial.println(tensao);
}

void loop() {
}
```

---

## `int`

O tipo `int` armazena números inteiros positivos e negativos. Em AVR geralmente possui 16 bits, enquanto no ESP32 possui 32 bits.

```cpp
int contador = -100;

void setup() {
  Serial.begin(115200);

  Serial.println(contador);
}

void loop() {
}
```

---

## `long`

O tipo `long` armazena números inteiros maiores utilizando 32 bits. É muito utilizado em temporizações, contadores e medições.

```cpp
long distancia = 150000;

void setup() {
  Serial.begin(115200);

  Serial.println(distancia);
}

void loop() {
}
```

---

## `short`

O tipo `short` armazena números inteiros utilizando menos memória que um `int` em algumas arquiteturas. Em muitos microcontroladores embarcados possui 16 bits.

```cpp
short valor = 32000;

void setup() {
  Serial.begin(115200);

  Serial.println(valor);
}

void loop() {
}
```

---

## `size_t`

O tipo `size_t` é utilizado para armazenar tamanhos de memória e índices de arrays. Ele sempre possui tamanho suficiente para representar o maior endereço da arquitetura.

```cpp
char texto[] = "ESP32";

void setup() {
  Serial.begin(115200);

  size_t tamanho = sizeof(texto);

  Serial.println(tamanho);
}

void loop() {
}
```

---

## `string`

O termo `string` normalmente refere-se a cadeias de caracteres em linguagem C utilizando arrays de `char`.

```cpp
char texto[] = "Arduino";

void setup() {
  Serial.begin(115200);

  Serial.println(texto);
}

void loop() {
}
```

---

## `String()`

`String` é uma classe do Arduino utilizada para manipular textos de forma mais simples e intuitiva que arrays de caracteres.

```cpp
String nome = "ESP32";

void setup() {
  Serial.begin(115200);

  Serial.println(nome);
}

void loop() {
}
```

---

## `unsigned char`

O tipo `unsigned char` armazena números inteiros positivos de 0 até 255 utilizando 8 bits.

```cpp
unsigned char valor = 200;

void setup() {
  Serial.begin(115200);

  Serial.println(valor);
}

void loop() {
}
```

---

## `unsigned int`

O tipo `unsigned int` armazena números inteiros positivos sem sinal.

```cpp
unsigned int velocidade = 65000;

void setup() {
  Serial.begin(115200);

  Serial.println(velocidade);
}

void loop() {
}
```

---

## `unsigned long`

O tipo `unsigned long` armazena números inteiros positivos grandes utilizando 32 bits. Muito utilizado com `millis()`.

```cpp
unsigned long tempo = millis();

void setup() {
  Serial.begin(115200);

  Serial.println(tempo);
}

void loop() {
}
```

---

## `void`

O tipo `void` indica ausência de retorno em funções.

```cpp
void ligarLed() {
  digitalWrite(2, HIGH);
}

void setup() {
  pinMode(2, OUTPUT);

  ligarLed();
}

void loop() {
}
```

---

## `word`

O tipo `word` armazena valores inteiros sem sinal de 16 bits.

```cpp
word valor = 65535;

void setup() {
  Serial.begin(115200);

  Serial.println(valor);
}

void loop() {
}
```

## `array`

Um `array` é uma estrutura utilizada para armazenar vários valores do mesmo tipo em uma única variável organizada por índices. É muito utilizado para armazenar leituras de sensores, sequências de LEDs, tabelas e buffers de comunicação serial. Os índices começam em zero, portanto o primeiro elemento sempre será acessado pela posição `[0]`.

```cpp
int numeros[5] = {10, 20, 30, 40, 50};

void setup() {
  Serial.begin(115200);

  Serial.println(numeros[2]); // Exibe 30
}

void loop() {
}
```

