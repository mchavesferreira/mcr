# Popoposta 1: Lixeiras Inteligentes: Uma Solução Sustentável para Gestão de Resíduos em Cidades Inteligentes



O projeto "Smart Waste Solutions for Sustainable Cities" (Soluções Inteligentes de Resíduos para Cidades Sustentáveis) visa desenvolver lixeiras equipadas com tecnologia IoT para monitoramento em tempo real dos níveis de preenchimento. Serão implementadas duas unidades: uma com comunicação WiFi no IFSP Catanduva e outra com LoRaWAN para o centro da cidade, integradas à infraestrutura do SMART CAMPUS. Esta iniciativa alinha-se aos Objetivos de Desenvolvimento Sustentável e promove a inserção do IFSP na comunidade por meio de soluções tecnológicas que otimizam a gestão de resíduos urbanos.

## Introdução e Contextualização

A gestão eficiente de resíduos sólidos representa um dos maiores desafios para administrações municipais, impactando diretamente a qualidade de vida urbana, o meio ambiente e os custos operacionais das cidades. Diante desse cenário, as tecnologias IoT (Internet das Coisas) surgem como ferramentas promissoras para transformar o gerenciamento de resíduos, tornando-o mais inteligente, econômico e sustentável[1].

Este projeto propõe o desenvolvimento de lixeiras inteligentes equipadas com sensores e conectividade para monitoramento em tempo real dos níveis de enchimento, implementando duas abordagens tecnológicas complementares: uma unidade WiFi para o ambiente controlado do IFSP Catanduva e outra unidade LoRaWAN para instalação em área urbana central, demonstrando diferentes soluções para variados contextos de aplicação.

## Justificativa

A gestão de resíduos é um problema global com impactos ambientais, econômicos e sociais significativos. Sistemas inteligentes baseados em IoT podem reduzir custos operacionais em até 30% e o consumo de combustível em até 50%, conforme estudos realizados sobre soluções de gerenciamento inteligente de resíduos[2].

Otimizando rotas com dados em tempo real, essas soluções diminuem emissões de carbono, melhoram a qualidade do ar e reduzem o uso de aterros, preservando habitats naturais e minimizando emissões de metano. Para Catanduva, o projeto pode trazer benefícios concretos:

- Redução de custos operacionais para a SAEC através da otimização das rotas de coleta
- Diminuição de lixeiras transbordantes e lixo nas vias públicas
- Melhoria da experiência urbana para moradores e visitantes
- Desenvolvimento de expertise local em tecnologias IoT para cidades inteligentes

Para o IFSP Catanduva, o projeto promove engajamento comunitário, demonstrando o compromisso institucional com a sustentabilidade. Alinha-se diretamente aos Objetivos de Desenvolvimento Sustentável (ODS):

- ODS 11 (Cidades e Comunidades Sustentáveis): através da otimização da gestão de resíduos urbanos
- ODS 12 (Consumo e Produção Responsáveis): promovendo práticas sustentáveis de gestão de lixo
- ODS 13 (Ação Contra a Mudança do Clima): reduzindo emissões através de rotas otimizadas
- ODS 9 (Indústria, Inovação e Infraestrutura): implementando tecnologias inovadoras
- ODS 17 (Parcerias para os Objetivos): estabelecendo colaboração entre IFSP, SAEC e comunidade

A parceria com a SAEC, responsável pela coleta de lixo em Catanduva, potencializa o alcance do projeto, promovendo desenvolvimento urbano sustentável e alinhando-se aos objetivos globais de sustentabilidade.

## Pesquisa Bibliográfica

### Tecnologias IoT para Gestão de Resíduos

A literatura recente sobre gestão inteligente de resíduos demonstra a consolidação de arquiteturas baseadas em sensores para detecção de nível, conectividade sem fio e plataformas em nuvem para análise e otimização.

Estudos como o de Addas et al. (2024) propuseram um sistema com sensor ultrassônico para medir o nível de enchimento, conectividade híbrida LoRaWAN/celular, e algoritmos de otimização de rotas que reduziram em 32% o tempo de coleta e 29% o consumo de combustível em pilotos realizados[1].

Sensores ultrassônicos são amplamente utilizados por sua robustez em ambientes sujos, embora sensores infravermelhos ou de peso também apareçam em protótipos. Há uma preferência por sensores ultrassônicos à prova d'água (como o modelo JSN-SR04T) para suportar a lavagem dos contêineres e garantir medições confiáveis do nível de lixo[1][2].

### Plataformas de Hardware e Comunicação

No que tange a plataformas de hardware, a comunidade tem favorecido placas microcontroladoras com conectividade integrada. O ESP32 (que oferece WiFi/Bluetooth embarcados) e a família Arduino (com módulos de rádio acoplados) são opções comuns para implementação[2].

As redes de conectividade IoT escolhidas variam conforme o alcance e a infraestrutura disponível:

- **WiFi**: Adequado para ambientes com infraestrutura existente, como o campus do IFSP. Oferece alta taxa de transferência mas consome mais energia e tem alcance limitado.
- **LoRaWAN**: Rede de longa distância operando em faixa não licenciada sub-GHz, típica para IoT urbano. Estudos destacam seu alcance de 2–5 km em ambientes urbanos com baixo consumo de energia, sendo ideal para conectar sensores distribuídos pela cidade[1].

### Casos de Implementação

Diversos projetos-piloto apresentam resultados promissores:

- Em Praga, um projeto co-financiado pelo programa Horizon 2020 implementou sensores Sensoneo em lixeiras, resultando em rotas dinâmicas de coleta que reduziram significativamente os impactos ambientais[2].

- A cidade de San Francisco implementou lixeiras inteligentes com sensores que monitoram níveis de enchimento, temperatura e taxas de preenchimento. Durante o programa piloto em 2018, houve redução de 80% nos casos de lixeiras transbordantes, 64% em despejos ilegais e 66% nas solicitações de limpeza de ruas[6].

- Em Nova York, tecnologias de gerenciamento inteligente de resíduos estão sendo implementadas como parte do objetivo da cidade de enviar zero resíduos para aterros até 2030, com uso de caminhões automatizados e insights baseados em dados para otimizar coletas[6].

No Brasil, iniciativas semelhantes começam a ganhar espaço. Um estudo recente publicado pela RIC-CPS apresenta o desenvolvimento de uma lixeira inteligente IoT utilizando ESP32 e sensor ultrassônico, demonstrando a viabilidade técnica e econômica para implementação em contextos brasileiros[3].

## Metodologia

Considerando o nível técnico dos alunos, a metodologia priorizará acessibilidade e praticidade, utilizando sensores disponíveis no mercado e ESP32. O projeto será dividido nas seguintes etapas:

### 1. Análise de Requisitos

Definir funcionalidades essenciais:
- Monitorar níveis de preenchimento das lixeiras
- Enviar alertas quando atingirem capacidade predefinida
- Comunicar dados via WiFi (unidade IFSP) e LoRaWAN (unidade centro)
- Integrar com plataforma do SMART CAMPUS para visualização e análise

O sistema adaptará lixeiras existentes, minimizando modificações estruturais e priorizando a instalação não-invasiva de sensores e módulos de comunicação.

### 2. Seleção de Materiais

**Sensores**: Ultrassônicos AJ-SR04M ou JSN-SR04T, ambos a prova d'água) para medir o nível de enchimento, devido ao baixo custo e disponibilidade. Se a lixeira eletrônica for para materiais recicláveis, prever 4 sensores para cada.

**Microcontrolador**: Especificar a vesão ESP32S3 ideal para aplicações futuras com machine learningn (IA),  flexibilidade e suporte nativo a WiFi e bluethoo BLE.

**Radio longa distância** módulo SX1278 para comunicação LoRaWAN

**Alimentação**:

Este item merece maior atenção, no item a seguir discutimos melhor as opções.

- 3 Baterias LiPo 3.7V recarregável (para compor 12V)
- 01 pilna Lithium LS14500 AA 3,6V 2400mAh não recarregável
- 1 painel solar 10W/18V
- 5 painéis solar 200mA/5V
- Placa Proteção Bateria Lítio 18650 3s 11,1v 10a Bms
- Controlador Carga Painel Solar Pwm 12v / 24v 10a

##### Características dos materiais

Segue características de escolha para o sensor de distância, compatilidade para ESP32S3, e o custo de 4 unidades para cada lixeira, escolha AJ-SR04M

| Característica              | **AJ-SR04M**                          | **JSN-SR04M-2**                        |
|----------------------------|----------------------------------------|----------------------------------------|
| **Tipo de Interface**      | Trigger e Echo separados               | Trigger e Echo unificados (mesmo pino) |
| **Alimentação**            | 3.0V – 5.5V                            | 5V                                     |
| **Compatibilidade ESP32**  | Totalmente compatível                  | Requer divisor de tensão               |
| **Alcance de Medição**     | ~20 cm a 600 cm                        | ~30 cm a 450 cm                        |
| **Precisão**               | Boa até 4 m                            | Menor precisão em longas distâncias    |
| **Filtro/Estabilidade**    | Menos protegido contra ruído EMI       | Melhor filtragem e estabilidade        |
| **Resistência à água**     | IP66 (à prova d'água)                  | IP66 (à prova d'água)                  |
| **Facilidade de uso**      | Fácil (sem adaptações no código)       | Exige código adaptado (pino único)     |
| **Custo**                  | Geralmente mais barato                 | Levemente mais caro                    |
| **Aplicações típicas**     | Irrigação, controle de nível, portões  | Robótica, ESP32, medição externa       |


Para escolha do microcontrolador, a melhor opção é ESP32S3

| Característica                | **ESP32-WROOM-32**                 | **ESP32-S3**                            | **ESP32-C3**                          |
|------------------------------|------------------------------------|-----------------------------------------|---------------------------------------|
| **CPU**                      | Dual-core Xtensa LX6               | Dual-core Xtensa LX7                    | Single-core RISC-V                    |
| **Frequência**               | Até 240 MHz                        | Até 240 MHz                             | Até 160 MHz                           |
| **RAM interna**              | 520 KB                             | Até 512 KB SRAM + 384 KB ROM            | 400 KB SRAM + 384 KB ROM              |
| **Flash**                    | Até 16 MB (4 MB comum)             | Até 16 MB                               | Até 4 MB                              |
| **Conectividade Wi-Fi**      | 802.11 b/g/n                       | 802.11 b/g/n                            | 802.11 b/g/n                          |
| **Bluetooth**                | BT v4.2 (Classic + BLE)            | BLE v5.0 (LE Only)                      | BLE v5.0 (LE Only)                    |
| **USB nativo**               | ❌ Não                             | ✅ Sim (USB OTG)                        | ✅ Sim (USB CDC/JTAG)                 |
| **Pinos GPIO disponíveis**   | ~34                                | ~45                                     | ~22                                   |
| **Aceleração por IA**        | ❌ Não                             | ✅ Sim (TensorFlow Lite / Vector Unit) | ❌ Não                                |
| **Segurança (cripto/hardware)** | Secure Boot, Flash Encryption     | Secure Boot v2, HMAC, AES, RSA          | Secure Boot, AES-128, SHA-2, RNG     |
| **Consumo energético**       | Moderado                           | Médio                                   | Muito baixo (ideal para baterias)     |
| **Arquitetura de CPU**       | Xtensa LX6                         | Xtensa LX7                              | RISC-V 32 bits                        |
| **Ideal para**               | Projetos gerais com Wi-Fi/Bluetooth| Visão computacional, IA, USB e periféricos | Baixo consumo, dispositivos compactos |


Aqui está uma análise atualizada das três versões com os componentes especificados e cálculo detalhado de autonomia:

## **Versão 1 - Sistema Portátil de Longa Duração**
**Componentes Principais:**
- **Bateria:** Xeno Lithium LS14500 AA 3,6V 2400mAh (R$80)
- **Regulador:** HT7333 (3.3V 250mA)
- **Consumo/Ciclo:** 0.0484mAh

**Cálculo de Autonomia:**
1. Capacidade efetiva (considerando eficiência LDO 90%):
   $$ \frac{2400mAh \times 3,6V}{3,3V} \times 0,9 = 2378mAh $$

2. Ciclos totais:
   $$ \frac{2378mAh}{0,0484mAh/ciclo} = 49.132 $$ ciclos

3. Autonomia total:
   $$ 49.132 \times 10 \text{ min} = 491.320 \text{ min} \approx 341 \text{ dias} $$

**Vantagens:**
- Compacto e à prova de intempéries
- Operação estável entre -40°C e 60°C

---

## **Versão 2 - Solar Compacta (Médio Porte)**
**Componentes Principais:**
- **Bateria:** LiPo 3.7V 2000mAh (mantido)
- **Painel Solar:** 1W/5V
- **Controlador:** TP4056

**Cálculo de Autonomia:**
1. Autonomia sem sol:
   $$ \frac{2000mAh}{0,0484mAh/ciclo} \times 10 \text{ min} \approx 287 \text{ dias} $$

2. Recarga diária:
   $$ \frac{1W \times 4h}{3,7V} = 1081mAh/dia $$
   (Cobre consumo diário de 69,6mAh)

**Custo Total:** R$170 (bateria R$40 + painel R$50 + controlador R$80)

---

## **Versão 3 - Sistema Híbrido Industrial**
**Componentes Principais:**
- **Bateria:** VRLA 12V 9Ah (R$110)
- **Painel Solar:** 10W/19,5V (R$150)
- **Controlador:** PWM 10A (R$80)

**Cálculo de Autonomia:**
1. Capacidade útil (considerando 50% DoD):
   $$ \frac{9Ah \times 12V \times 0,5}{5V} \times 0,85 = 9.180mAh $$

2. Ciclos totais:
   $$ \frac{9180mAh}{0,0484mAh/ciclo} = 189.669 $$ ciclos

3. Autonomia:
   $$ 189.669 \times 10 \text{ min} \approx 3,6 \text{ anos} $$

**Recarga Solar:**
$$ \frac{10W \times 4h}{12V} = 3,33Ah/dia $$ (37% da capacidade diária)

---

### **Comparativo Técnico**

| Parâmetro          | Versão 1       | Versão 2       | Versão 3       |
|--------------------|----------------|----------------|----------------|
| Investimento       | R$ 120         | R$ 170         | R$ 340         |
| Autonomia (sem sol)| 341 dias       | 287 dias       | 3,6 anos       |
| Faixa de Temp.     | -40°C ~ 60°C   | 0°C ~ 45°C     | 15°C ~ 35°C    |
| Eficiência         | 89%            | 78%            | 82%            |
| Peso               | 150g           | 300g           | 2.800g         |
| Manutenção         | Troca anual    | Recarga solar  | Verificação bienal |

---

### **Recomendações por Cenário**
1. **Ambientes Remotos Severos** (estações de montanha):  
   Versão 1 - Resistente a temperaturas extremas

2. **Áreas Urbanas com Insolação** (parques públicos):  
   Versão 2 - Autossustentável com baixa pegada ecológica

3. **Centros de Coleta Massiva** (terminais de ônibus):  
   Versão 3 - Alta capacidade com redundância energética

**Nota Técnica:**  
Para a Versão 3, o controlador PWM de 10A permite expandir o sistema para até 120W de painéis solares, possibilitando futura integração com sistemas adicionais como compactadores ou displays LCD.



### 3. Desenvolvimento de Software e Firmware

Programação do ESP32 no Arduino IDE, com código estruturado em módulos:
- Leitura de sensores (ultrassônico)
- Gerenciamento de energia (especialmente importante para unidade LoRaWAN)
- Comunicação (WiFi ou LoRaWAN, dependendo da unidade)
- Integração com servidor (envio e armazenamento de dados)

Para a unidade WiFi, a implementação conectará à rede do IFSP, enviando dados diretamente à plataforma SMART CAMPUS. A unidade LoRaWAN comunicará com o gateway já existente no projeto SMART CAMPUS, utilizando o protocolo LoRaWAN para transmissão eficiente de dados.

### 4. Integração e Testes

- Montar hardware com sensores, microcontroladores e módulos de comunicação
- Criar estrutura de fixação nas lixeiras existentes
- Realizar testes em ambiente controlado para calibrar sensores e validar comunicação
- Implementar correções e ajustes baseados nos resultados dos testes

### 5. Implantação

- Instalação da unidade WiFi no IFSP Catanduva, utilizando infraestrutura existente
- Coordenação com SAEC para instalação da unidade LoRaWAN no centro da cidade
- Configuração da integração com plataforma SMART CAMPUS para visualização e análise

### 6. Monitoramento e Dashboard

Desenvolvimento de interface de visualização na plataforma SMART CAMPUS, incluindo:
- Mapa de localização das lixeiras
- Gráficos de nível de enchimento em tempo real
- Histórico de dados de enchimento
- Sistema de alertas para níveis críticos
- Estatísticas de coleta e impacto ambiental
- Métricas de sustentabilidade alinhadas aos ODS

### 7. Manutenção e Evolução

Planejamento de manutenção periódica:
- Verificação física das lixeiras inteligentes mensalmente
- Limpeza de sensores
- Verificação de baterias e painéis solares
- Atualização de software conforme necessário

## Resultados Esperados

Com a implementação do projeto, espera-se obter:

1. **Eficiência operacional**: Redução no número de coletas desnecessárias, otimização de rotas e economia de recursos.

2. **Impacto ambiental positivo**: Diminuição de emissões de CO₂ pela redução no tráfego de caminhões de coleta, prevenção de transbordamento de lixeiras e melhoria na higiene urbana.

3. **Desenvolvimento tecnológico local**: Capacitação de estudantes em IoT e cidades inteligentes, criando base para futuros projetos.

4. **Engajamento comunitário**: Fortalecimento da relação entre IFSP, poder público (SAEC) e comunidade, com demonstração prática de tecnologias sustentáveis.

5. **Alinhamento com ODS**: Contribuição mensurável para objetivos globais de sustentabilidade, especialmente os ODS 11, 12 e 13.

## Cronograma de Implementação Sugerido

1. **Meses 1-2**: Estudo de viabilidade, definição de requisitos e projeto preliminar
2. **Meses 3-4**: Aquisição de componentes e desenvolvimento de hardware
3. **Meses 5-6**: Programação de firmware e desenvolvimento de software
4. **Meses 7-8**: Integração, testes e refinamento
5. **Meses 9-10**: Implantação piloto e monitoramento inicial
6. **Meses 11-12**: Avaliação, documentação e apresentação final

## Conclusão

O projeto "Smart Waste Solutions for Sustainable Cities" representa uma oportunidade significativa para o IFSP Catanduva demonstrar sua capacidade de desenvolver soluções tecnológicas aplicadas a problemas reais da comunidade. Ao implementar lixeiras inteligentes usando tecnologias IoT acessíveis (WiFi e LoRaWAN), o projeto não apenas atende às necessidades práticas de gestão de resíduos urbanos, mas também se alinha aos objetivos globais de sustentabilidade.

A parceria com a SAEC potencializa o impacto do projeto, permitindo que uma solução desenvolvida academicamente seja aplicada no contexto real da cidade. Os benefícios esperados incluem redução de custos operacionais, diminuição de impactos ambientais e melhoria da qualidade de vida urbana.

Por fim, o projeto cria uma base tecnológica que pode ser expandida para outras aplicações de cidades inteligentes, integrando-se ao ecossistema maior do SMART CAMPUS e inspirando futuras iniciativas. A abordagem modular e de baixo custo garante que, mesmo desenvolvido por estudantes de nível técnico, o sistema possa oferecer valor real e mensurável para a comunidade, exemplificando como a tecnologia pode ser uma aliada poderosa na construção de cidades mais sustentáveis e inteligentes.

## Referências[1] Waste management 2.0 leveraging internet of things for an efficient and eco-friendly smart city solution. PMC, 2024.[2] A Multi-Layer LoRaWAN Infrastructure for Smart Waste Management. Sensors, 21(8):2600, 2021. Smart waste management solution. Ecube Labs, 2023. IoT-Based Garbage Container System Using NodeMCU ESP32 Microcontroller. Research Gate, 2022. An internet of things based smart waste system. Research Gate, 2021. Waste Management in Green and Smart Cities: A Case Study of Russia. MDPI, 2020. On Demand Waste Collection for Smart Cities: A Case Study. Research Gate, 2021. The Innovative Benefits Of Smart Waste Management Solutions. Kore Wireless, 2023. Top US Cities for Smart Waste Management. RTS, 2023.[3] Lixeira inteligente IOT: Integrando a eficiência da IoT na gestão de resíduos. RIC-CPS, 2024.[4] Next-Gen Water Waste Management Using ESP32 and Ultra Sonic. IJRPR, 2025.[5] Projeto de Gestão de Resíduos Sólidos Urbanos com IoT e MQTT. GitHub, 2024.[6] Smart cities – setting a higher standard for efficiency, cleanliness and sustainability. Envac Group, 2025.


# Popoposta 2:  Projeto Lixeira Eletrônica


---
#### Grupo:

 -Camily Pereira Alberganti
 
 -Fernando Henrique das Neves de Albuquerque
 
 -João Henrique da Silva Santana
 
 -Kaynã Ademir Tinel Andreotti
 
 -Leonardo Oliveira da Silva
 
 -Miguel Antonio de Francisco
 
#### Orientação:  Prof. Dr. Marcos Aparecido Chaves Ferreira (IFSP Catanduva)

### Resumo
O projeto "Lixeira Eletrônica" ou "Smart Waste Solutions for Sustainable Cities" visa desenvolver lixeiras inteligentes com comunicação IoT para otimizar o gerenciamento de resíduos no IFSP Catanduva e no centro da cidade. Uma unidade usará WiFi para a escola, e outra, LoRaWAN, para o centro, monitorando níveis de preenchimento em tempo real. Alinhado ao projeto SMART CAMPUS, o trabalho será apresentado à SAEC para instalação no município, promovendo sustentabilidade e engajamento comunitário com base nos ODS.

### Justificativa
A gestão inteligente de resíduos é essencial para reduzir custos, otimizar coletas e promover a sustentabilidade, alinhando-se aos ODS 11 (Cidades Sustentáveis) e 12 (Consumo Responsável). Estudos indicam potencial de economia de até 30% nos custos operacionais e 50% no consumo de combustível [The Innovative Benefits Of Smart Waste Management Solutions](https://www.korewireless.com/news/benefits-of-smart-waste-management). Este projeto reforça o papel do IFSP na comunidade, contribuindo para um ambiente mais limpo e eficiente.

### Metodologia
Desenvolvido por alunos de Mecatrônica, o projeto usará sensores disponíveis (como ultrassônicos HC-SR04), ESP32 e adaptará lixeiras existentes. Inclui:  
1. Análise de requisitos para monitorar níveis e enviar alertas.  
2. Configuração de WiFi para a unidade escolar e LoRaWAN para o centro, possivelmente exigindo gateway próprio.  
3. Programação no Arduino IDE, testes em ambiente controlado e implantação, com coordenação com a SAEC para instalação no centro.  
4. Monitoramento via app, com manutenção planejada, especialmente para baterias da unidade LoRaWAN.

### Conclusão
O projeto promete reduzir custos, melhorar eficiência e engajar a comunidade, integrando-se ao SMART CAMPUS. Apresentado à SAEC, pode ampliar seu impacto, promovendo cidades sustentáveis e alinhando-se às diretrizes globais.

---

### Survey Note: Pesquisa Profunda sobre o Projeto "Smart Lixeira" para Cidades Inteligentes

Este documento apresenta uma pesquisa detalhada sobre o projeto "Smart Lixeira" ou "Smart Waste Solutions for Sustainable Cities", desenvolvido como iniciativa de formatura para alunos do curso técnico de Mecatrônica do IFSP Catanduva. O foco é criar lixeiras inteligentes com comunicação IoT, utilizando WiFi para uma unidade na escola e LoRaWAN para outra no centro da cidade, integrando-se ao projeto maior SMART CAMPUS Catanduva (http://smartcampus.ctd.ifsp.edu.br). Abaixo, detalham-se resumo, justificativa, pesquisa bibliográfica, metodologia e conclusão, com base em estudos e casos relevantes.

#### Resumo
O projeto propõe o desenvolvimento de lixeiras inteligentes equipadas com tecnologia IoT para aprimorar o gerenciamento de resíduos no IFSP Catanduva e no centro de Catanduva. Uma unidade será instalada na escola usando comunicação WiFi, enquanto outra, no centro da cidade, utilizará LoRaWAN, permitindo monitoramento em tempo real dos níveis de preenchimento para otimizar a coleta de lixo e promover a sustentabilidade. Esta iniciativa integra-se ao projeto SMART CAMPUS, que reúne diversas soluções para o campus e cidades inteligentes.

#### Justificativa
A gestão de resíduos é um desafio global com impactos ambientais, econômicos e sociais significativos. Sistemas inteligentes baseados em IoT podem reduzir custos operacionais em até 30% e o consumo de combustível em até 50%, conforme estudos como [The Innovative Benefits Of Smart Waste Management Solutions](https://www.korewireless.com/news/benefits-of-smart-waste-management). Otimizando rotas com dados em tempo real, essas soluções diminuem emissões de carbono, melhoram a qualidade do ar e reduzem o uso de aterros, preservando habitats naturais e minimizando emissões de metano.

Para o IFSP Catanduva, o projeto promove engajamento comunitário, demonstrando o compromisso institucional com a sustentabilidade. Alinha-se aos Objetivos de Desenvolvimento Sustentável (ODS), especialmente o ODS 11 (Cidades e Comunidades Sustentáveis) e o ODS 12 (Consumo e Produção Responsáveis), contribuindo para um ambiente urbano mais limpo e eficiente. A apresentação à SAEC, empresa responsável pela coleta na cidade, pode facilitar a instalação no centro da cidade em uma área de grande circulação, potencialmente reduzindo gastos públicos com coletas desnecessárias.

#### Pesquisa Bibliográfica
A pesquisa abrangeu artigos, estudos de caso e publicações técnicas sobre gestão inteligente de resíduos com IoT, com ênfase em WiFi, LoRaWAN e ESP32. Recursos-chave incluem:

- [Smart Waste Management Systems Using IoT: Revolutionize Waste Collection](https://bridgera.com/iot-based-smart-waste-management-system/), explorando como IoT otimiza rotas e reduz custos.
- [IoT-Based Smart Waste Management Systems for Revolutionary Changes](https://evreka.co/blog/iot-based-smart-waste-management-systems/), detalhando exemplos de lixeiras inteligentes.
- [Top 13 IoT Examples of Smart Waste Management](https://freeeway.com/top-13-iot-examples-of-smart-waste-management/), destacando monitoramento em tempo real.
- [(PDF) IoT-Based Garbage Container System Using NodeMCU ESP32 Microcontroller](https://www.researchgate.net/publication/365721127_IoT-Based_Garbage_Container_System_Using_NodeMCU_ESP32_Microcontroller), focando no uso de ESP32.
- [(PDF) An internet of things based smart waste system](https://www.researchgate.net/publication/352031168_An_internet_of_things_based_smart_waste_system), abordando implementações com múltiplos sensores.
- [Waste Management in Green and Smart Cities: A Case Study of Russia](https://www.mdpi.com/2071-1050/12/1/94), analisando estratégias descentralizadas.
- [On Demand Waste Collection for Smart Cities: A Case Study](https://www.researchgate.net/publication/363490421_On_Demand_Waste_Collection_for_Smart_Cities_A_Case_Study), com foco em otimização de rotas em Ålesund, Noruega.

Estudos como [Waste management 2.0 leveraging internet of things for an efficient and eco-friendly smart city solution](https://pmc.ncbi.nlm.nih.gov/articles/PMC11290616/) mostram melhorias de 32% na eficiência de rotas e 29% na redução de consumo de combustível em Lahore, Paquistão, validando a viabilidade de ESP32 para WiFi e LoRaWAN.

#### Metodologia
Considerando o nível técnico dos alunos, a metodologia prioriza acessibilidade e praticidade, utilizando sensores de mercado e ESP32. As etapas incluem:

1. **Análise de Requisitos:** Definir funcionalidades, como monitorar níveis de preenchimento, enviar alertas quando cheios, e comunicar via WiFi (escola) e LoRaWAN (centro da cidade). O sistema integrará lixeiras existentes, minimizando modificações.

2. **Seleção de Hardware:** Sensores ultrassônicos (e.g., HC-SR04) para níveis, econômicos e acessíveis. ESP32 suporta WiFi nativamente; para LoRaWAN, requer módulo como SX1276. Considerar suprimento de energia, especialmente para a unidade LoRaWAN, que pode operar a bateria com modos de baixo consumo.

3. **Desenvolvimento de Software:** Programar ESP32 no Arduino IDE. Unidade WiFi conecta à rede da escola, enviando dados a plataformas como ThingSpeak. Unidade LoRaWAN comunica-se com gateway, possivelmente via The Things Network (TTN), dado que a cobertura em Catanduva pode exigir instalação de gateway próprio, conforme verificado em pesquisas sobre redes LoRaWAN no Brasil. Será utilizada a mesma rede Lorawan do projeto de extensão Miniestações meterológicas do professor orientador.

4. **Integração e Testes:** Montar hardware, integrar sensores e módulos, testar em ambiente controlado para garantir precisão e confiabilidade. Resolver problemas como conectividade ou falhas de sensor.

5. **Implantação:** Instalar unidade WiFi no IFSP, usando infraestrutura escolar. Para o centro, coordenar com SAEC, assegurando conformidade local e para ambas unidades contar adaptar a uma lixeira fornecida pela SAEC.

6. **Monitoramento e Manutenção:** Criar sistema de visualização (app web/mobile) simples utilizando Node-red acompanhamento de níveis e alertas. Planejar manutenção, como troca de baterias ou instalação de painel solar para LoRaWAN, e garantir segurança de dados contra acessos não autorizados.

#### Tabela de Comparação: Tecnologias WiFi vs. LoRaWAN

| **Aspecto**            | **WiFi**                                      | **LoRaWAN**                                   |
|-------------------------|-----------------------------------------------|-----------------------------------------------|
| **Alcance**            | Limitado, ideal para áreas com cobertura (escola) | Longo alcance, adequado para áreas urbanas amplas |
| **Consumo de Energia** | Alto, requer fonte constante (tomada)         | Baixo, suporta operação a bateria por anos    |
| **Custo Inicial**      | Baixo, usa infraestrutura existente           | Pode exigir gateway, aumentando custo inicial |
| **Segurança**          | Boa, com configurações adequadas              | Alta, com protocolo LoRaWAN seguro            |
| **Aplicação**          | Monitoramento local, como campus escolar      | Monitoramento em larga escala, como centro da cidade |

#### Conclusão
Este projeto oferece solução prática para gestão de resíduos no IFSP Catanduva e centro da cidade, usando IoT para monitorar e otimizar coletas. Espera-se redução de custos, maior eficiência e menor impacto ambiental, integrando-se ao SMART CAMPUS. A parceria com SAEC pode ampliar o alcance, promovendo desenvolvimento urbano sustentável e alinhando-se aos ODS. O projeto aproveitará a estrutura de servidor web e gateway em andamento no campus.

#### Key Citations
- [Smart Waste Management Systems Using IoT: Revolutionize Waste Collection](https://bridgera.com/iot-based-smart-waste-management-system/)
- [IoT-Based Smart Waste Management Systems for Revolutionary Changes](https://evreka.co/blog/iot-based-smart-waste-management-systems/)
- [Top 13 IoT Examples of Smart Waste Management](https://freeeway.com/top-13-iot-examples-of-smart-waste-management/)
- [IoT-Based Garbage Container System Using NodeMCU ESP32 Microcontroller PDF](https://www.researchgate.net/publication/365721127_IoT-Based_Garbage_Container_System_Using_NodeMCU_ESP32_Microcontroller)
- [An internet of things based smart waste system PDF](https://www.researchgate.net/publication/352031168_An_internet_of_things_based_smart_waste_system)
- [Waste Management in Green and Smart Cities: A Case Study of Russia](https://www.mdpi.com/2071-1050/12/1/94)
- [On Demand Waste Collection for Smart Cities: A Case Study](https://www.researchgate.net/publication/363490421_On_Demand_Waste_Collection_for_Smart_Cities_A_Case_Study)
- [The Innovative Benefits Of Smart Waste Management Solutions](https://www.korewireless.com/news/benefits-of-smart-waste-management)
- [Waste management 2.0 leveraging internet of things for an efficient and eco-friendly smart city solution](https://pmc.ncbi.nlm.nih.gov/articles/PMC11290616/)


https://www.nucleodoconhecimento.com.br/engenharia-eletrica/redes-de-lixeiras


