# Exemplo de tamanho de um pacote IP dentro de um Frame Ethernet

Um pacote IP normalmente é transportado dentro de um **frame Ethernet**. Assim, o pacote IP corresponde apenas a uma parte do frame transmitido pela rede local.

## Estrutura simplificada

```text
┌───────────────────────────────────────────────────────────────────────────────┐
│                              FRAME ETHERNET                                  │
├──────────────┬──────────────┬──────────┬───────────────────────────┬─────────┤
│ MAC Destino  │ MAC Origem   │ EtherType│        PACOTE IPv4        │   FCS   │
│   6 bytes    │   6 bytes    │  2 bytes │       até 1500 bytes      │ 4 bytes │
└──────────────┴──────────────┴──────────┴───────────────────────────┴─────────┘
```

O campo **EtherType** possui, por exemplo:

```text
0x0800 → IPv4
0x86DD → IPv6
0x0806 → ARP
```

---

# Estrutura do pacote IPv4

Considerando IPv4 sem opções:

```text
┌────────────────────────────────────────────────────────────────────┐
│                         PACOTE IPv4                                │
├──────────────────────┬─────────────────────────────────────────────┤
│ Cabeçalho IPv4       │                  Dados                      │
│ mínimo: 20 bytes     │              até 1480 bytes                 │
└──────────────────────┴─────────────────────────────────────────────┘
```

Portanto, para uma Ethernet cujo **MTU é 1500 bytes**:

[
Tamanho\ máximo\ do\ pacote\ IP = 1500\ bytes
]

Se o cabeçalho IPv4 tiver o tamanho mínimo de 20 bytes:

[
Dados = 1500 - 20
]

[
Dados = 1480\ bytes
]

---

# Exemplo com TCP

Quando o protocolo transportado pelo IPv4 é TCP, existe também o cabeçalho TCP.

```text
FRAME ETHERNET
│
├── Cabeçalho Ethernet .............. 14 bytes
│
└── Pacote IPv4 ..................... 1500 bytes
    │
    ├── Cabeçalho IPv4 .............. 20 bytes
    │
    └── Segmento TCP ................ 1480 bytes
        │
        ├── Cabeçalho TCP ........... 20 bytes
        │
        └── Dados da aplicação ...... 1460 bytes

+ FCS Ethernet ....................... 4 bytes
```

Assim:

[
1500 = 20_{IP} + 20_{TCP} + 1460_{dados}
]

Portanto, em uma conexão **IPv4 + TCP sem opções**, é comum aparecer:

```text
MSS TCP = 1460 bytes
```

---

# Visualização completa

```text
┌──────────────────────────────── FRAME ETHERNET ────────────────────────────────┐
│                                                                                │
│  Cabeçalho Ethernet                    Pacote IPv4                     FCS       │
│       14 bytes                          1500 bytes                    4 bytes    │
│                                                                                │
│ ┌────────────┬────────────┬──────────┬────────────────────────────┐ ┌────────┐ │
│ │MAC Destino │ MAC Origem │EtherType │          IPv4              │ │  FCS   │ │
│ │  6 bytes   │  6 bytes   │ 2 bytes  │        1500 bytes          │ │4 bytes │ │
│ └────────────┴────────────┴──────────┴────────────────────────────┘ └────────┘ │
│                                         │                                      │
│                                         ▼                                      │
│                         ┌──────────────────────────────────┐                     │
│                         │          PACOTE IPv4             │                     │
│                         ├───────────────┬──────────────────┤                     │
│                         │ Cabeçalho IP  │ Segmento TCP     │                     │
│                         │   20 bytes    │   1480 bytes     │                     │
│                         └───────────────┴──────────────────┘                     │
│                                               │                                │
│                                               ▼                                │
│                                ┌──────────────────────────┐                     │
│                                │       SEGMENTO TCP       │                     │
│                                ├─────────────┬────────────┤                     │
│                                │Cabeçalho TCP│   Dados    │                     │
│                                │  20 bytes   │ 1460 bytes │                     │
│                                └─────────────┴────────────┘                     │
└────────────────────────────────────────────────────────────────────────────────┘
```

## Resumo dos tamanhos

| Elemento                       | Tamanho típico |
| ------------------------------ | -------------: |
| MAC destino                    |        6 bytes |
| MAC origem                     |        6 bytes |
| EtherType                      |        2 bytes |
| Cabeçalho Ethernet             |       14 bytes |
| Pacote IPv4 máximo em Ethernet |     1500 bytes |
| Cabeçalho IPv4 mínimo          |       20 bytes |
| Cabeçalho TCP mínimo           |       20 bytes |
| Dados TCP típicos máximos      |     1460 bytes |
| FCS Ethernet                   |        4 bytes |

### Frame Ethernet

Considerando apenas:

```text
Cabeçalho Ethernet + pacote IP + FCS
```

temos:

[
14 + 1500 + 4 = 1518\ bytes
]

Portanto:

```text
Frame Ethernet máximo típico = 1518 bytes
```

---

## Observação importante

Na transmissão física Ethernet ainda existem campos adicionais utilizados pelo enlace:

```text
Preâmbulo ............... 7 bytes
SFD ..................... 1 byte
Frame Ethernet ........ 1518 bytes
Interframe Gap .......... 12 bytes-equivalentes
```

Por isso, o número de bytes efetivamente utilizado no meio físico é maior que os **1518 bytes** do frame Ethernet propriamente dito.
