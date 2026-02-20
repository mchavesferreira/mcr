

---

# 🔹 Como a Flash é organizada?

A Flash possui uma **Partition Table** (tabela de partições).

Exemplo típico para Flash de 4 MB:

```text
0x1000  - bootloader
0x8000  - partition table
0x9000  - nvs
0x10000 - firmware (app0)
0x210000 - spiffs
```

Cada região tem um propósito diferente.

---

# 📦 O que é cada tipo?

---

# 1️⃣ NVS (Non-Volatile Storage)

É uma partição especial para:

* Configurações
* WiFi SSID
* Senhas
* Pequenos parâmetros
* Flags
* Calibrações

Ela funciona como um banco chave-valor.

Exemplo:

```c
nvs_set_i32(handle, "contador", 10);
```

Características:

✔ Wear leveling automático
✔ Seguro contra corrupção
✔ Ideal para poucos dados
❌ Não é sistema de arquivos

---

# 2️⃣ SPIFFS

SPI Flash File System.

Foi o primeiro sistema de arquivos usado no ESP32.

Permite:

* Criar arquivos
* Salvar logs
* HTML para servidor web
* Configurações em JSON

Exemplo:

```c
File file = SPIFFS.open("/log.txt", FILE_APPEND);
```

Características:

✔ Simples
✔ Funciona bem em Flash pequena
⚠ Está sendo substituído
⚠ Não tem diretórios reais

---

# 3️⃣ LittleFS

Evolução do SPIFFS.

Hoje é o mais recomendado para:

* Logs
* Arquivos de configuração
* Servidores web embarcados

Vantagens sobre SPIFFS:

✔ Melhor resistência a falhas
✔ Diretórios reais
✔ Melhor gerenciamento de desgaste

---

# 4️⃣ FATFS

Sistema FAT tradicional (igual pendrive).

Usado principalmente quando:

* A Flash é grande
* Ou quando se usa microSD

Permite:

✔ Compatibilidade com PC
✔ Estrutura FAT padrão
✔ Diretórios

Mais pesado que LittleFS.

---

# 🧠 Conceito Fundamental

Esses nomes NÃO são memórias diferentes.

Todos ocupam regiões da mesma Flash SPI.

Visualmente:

```text
Flash 4MB
---------------------------------
| Bootloader                   |
| Partition Table              |
| NVS                          |
| Firmware                     |
| LittleFS / SPIFFS / FATFS    |
---------------------------------
```

---

# 🔬 Quem define isso?

A divisão é definida no:

* ESP-IDF → arquivo `partitions.csv`
* Arduino → configuração padrão (ou personalizada)

Exemplo simplificado de partição:

```csv
# Name,   Type, SubType, Offset,  Size
nvs,      data, nvs,     0x9000,  0x5000
app0,     app,  factory, 0x10000, 1M
spiffs,   data, spiffs,  0x110000,1M
```

---

# 📊 Quando usar cada um?

| Uso                | Melhor opção    |
| ------------------ | --------------- |
| Salvar senha WiFi  | NVS             |
| Salvar log pequeno | LittleFS        |
| Servidor web       | LittleFS        |
| Arquivos grandes   | microSD + FATFS |
| Banco chave-valor  | NVS             |

---

# ⚠ Importante para Data Logger

Se você grava dados frequentemente:

* Evite escrever a cada segundo
* Use buffer em RAM
* Grave em blocos
* Prefira microSD se for contínuo

Flash tem limite típico de:

~100.000 ciclos por setor

---


