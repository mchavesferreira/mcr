Perfeito, Marcos!
Transformei o seu texto em **formato Markdown estruturado**, mantendo as instruções bem organizadas para que sirva como roteiro didático de programação em Arduino/ESP32.

---

# Exemplo de Programação para ESP32 em Automação de Processos

## Descrição Geral

O objetivo é elaborar um exemplo de **programação em Arduino IDE para ESP32**, utilizando **máquina de estados** para automação de um processo industrial.

* Comunicação inicial pela **porta serial**.
* Em cada etapa, publicar o **status do processo**.
* Utilizar **display OLED** para exibir as mensagens de cada etapa.
* Implementar a lógica com **`millis()`** (exemplo: [Wokwi](https://wokwi.com/projects/411388408286145537)).
* Implementar **botão de emergência (botão2)** para desligar todas as saídas e retornar ao estado inicial.

---

## Sequência de Etapas

1. **Tarefa 0** – Estado inicial

   * Ao ligar a máquina, aguarda-se o **pressionamento do botão1** (`sensor`).

2. **Tarefa 1** – Controle de válvula V1

   * A válvula **V4 é fechada (HIGH)**.
   * A válvula **V1 é acionada por 4 segundos** (`tempo`).

3. **Tarefa 2** – Enchimento com sensor de nível

   * A válvula **V2 é acionada até que o sensor nível1 seja acionado** (`sensor`).

4. **Tarefa 3** – Válvula V3

   * A válvula **V3 é acionada por 10 segundos** (`tempo`).

5. **Tarefa 4** – Misturador M1

   * O misturador **M1 é acionado por 30 segundos** (`tempo`).

6. **Tarefa 5** – Esvaziamento parcial

   * A válvula **V4 é acionada por 20 segundos** (`tempo`).

7. **Tarefa 6** – Diluição

   * A válvula **V2 é acionada por 5 segundos** (`tempo`).

8. **Tarefa 7** – Mistura complementar

   * O misturador **M1 é acionado por 15 segundos** (`tempo`).

9. **Tarefa 8** – Esvaziamento total

   * A válvula **V4 é aberta até que o sensor nível0 seja acionado** (`sensor`).
   * Retorna ao estado inicial → **`tarefa0()`**.

---

## Botão de Emergência

* **Botão2**: usado como **emergência em qualquer etapa**.
* Se pressionado:

  * Todas as saídas são desligadas.
  * Retorna ao **estado inicial**.
* Implementação no **`loop()` fora do `switch()`**.

---

## Entradas e Saídas

Utilizar **GPIOs entre 4 e 27**. As entradas devem ser configuradas com **`INPUT_PULLUP`**.

| Componente      | Tipo          | GPIO sugerido |
| --------------- | ------------- | ------------- |
| Botão1 (start)  | Entrada       | GPIO 4        |
| Botão2 (emerg.) | Entrada       | GPIO 5        |
| Sensor nível0   | Entrada       | GPIO 12       |
| Sensor nível1   | Entrada       | GPIO 13       |
| Válvula V1      | Saída         | GPIO 14       |
| Válvula V2      | Saída         | GPIO 15       |
| Válvula V3      | Saída         | GPIO 16       |
| Válvula V4      | Saída         | GPIO 17       |
| Misturador M1   | Saída         | GPIO 18       |
| Display OLED    | I²C (SDA/SCL) | GPIO 21/22    |

---

## Implementação Recomendada

* Utilizar **`switch(state)`** para a **máquina de estados**.
* Controle de tempo com **`millis()`**.
* Mensagens em cada etapa:

  * **Serial Monitor**
  * **Display OLED**

---



---

👉 Deseja que eu **complete todas as tarefas (T3 até T8)** no código já pronto em `switch(state)` ou prefere que eu deixe só a **estrutura-base para os alunos completarem**?
