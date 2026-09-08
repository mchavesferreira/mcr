# Projeto 3° Bimestre

## Projeto Sorveteria com ESP32 e AJAX

## Objetivo

Este projeto simula o funcionamento de uma sorveteria automatizada. O usuário monta o pedido utilizando botões em uma página web e acompanha o preparo pela própria página e por um display OLED conectado ao ESP32.

## Arquivos do projeto

- **`sorveteriaweb.ino`**: contém a programação do ESP32, o servidor web e a máquina de estados.
- **`index.h`**: contém a página HTML, os botões e as funções AJAX.

## Funcionamento

O ESP32 conecta-se à rede Wi-Fi e cria um servidor web. Ao acessar o endereço IP mostrado no Monitor Serial, o usuário pode escolher:

1. Número de bolas;
2. Sabor;
3. Cobertura;
4. Tamanho do recipiente.

Depois da última escolha, o preparo começa automaticamente. Cada etapa é mostrada na página web e no display OLED.

## Máquina de estados

A variável `estado` determina a etapa atual:

| Estado | Etapa |
|---:|---|
| 0 | Escolha do número de bolas |
| 1 | Escolha do sabor |
| 2 | Escolha da cobertura |
| 3 | Escolha do recipiente |
| 4 | Adição das bolas |
| 5 | Adição do sabor |
| 6 | Adição da cobertura |
| 7 | Pedido pronto |

No `loop()`, o comando `switch` chama a função correspondente ao estado atual. As etapas do preparo utilizam `millis()`, permitindo controlar o tempo sem interromper o servidor web.

O botão **Reiniciar escolhas ou pedido** pode ser utilizado durante as escolhas ou durante o preparo. Ao final, aparece o botão **Fazer novo pedido**.

Os LEDs representam as etapas do preparo

## Comunicação AJAX

A página usa AJAX com `XMLHttpRequest` para enviar comandos e consultar o ESP32 sem recarregar a página.

As rotas `/estado`, `/bolas`, `/sabor`, `/cobertura`, `/recipiente` e `/mensagem` retornam informações em texto simples. Outras rotas representam os botões, como `/mais`, `/sabor1` e `/recipiente1`.


