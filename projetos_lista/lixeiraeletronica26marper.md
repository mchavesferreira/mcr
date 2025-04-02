# Lixeiras Inteligentes: Uma Solução Sustentável para Gestão de Resíduos em Cidades Inteligentes

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

**Radio longa distância** 01 módulo SX1278 para comunicação LoRaWAN

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

Considerando o ciclo de 10 minutos em modo de baixo consumo, realiza-se a leitura do  módulo AJ-SR04M sensor de distancia( consumo de 30mA por 3 segundos) e transmite transmissao lorawan com sx1276 consumo 70 mA por 400ms.


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

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/85800/e532db48-b0de-44c3-8cdb-ae37b913eb71/pesquisalixeiragrok2603.md
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/85800/124964d4-2ff3-46ca-bf85-3b5d3673387d/lixeiras_inteligentes_pesquisa1-2.md
[3] https://ric.cps.sp.gov.br/bitstream/123456789/21480/1/eletroeletronica_2024_1_luciano_reis_lixeira_inteligente_iot.pdf
[4] https://ijrpr.com/uploads/V6ISSUE3/IJRPR40420.pdf
[5] https://github.com/Jovinull/IoT-Gestao-Residuos-Solidos-Urbanos
[6] https://www.rts.com/blog/smart-city-waste-management/
[7] https://revistaft.com.br/estudo-de-caso-de-automacao-residencial-baseada-em-internet-das-coisas/
[8] https://www.atlantis-press.com/article/125994179.pdf
[9] https://www.envacgroup.com/insights/smart-cities-setting-a-higher-standard-for-efficiency-cleanliness-and-sustainability/
[10] https://irjiet.com/common_src/article_file/1716107838_c691d0b2f3_8_irjiet.pdf
[11] http://smartcampus.ctd.ifsp.edu.br/paginas/index.php?idselecionado=6
[12] https://www.propulsiontechjournal.com/index.php/journal/article/download/5397/3689/9348
[13] https://www.youtube.com/watch?v=mLzEb_1i9UQ
[14] https://riunet.upv.es/bitstream/10251/180545/3/GarciaJimenezLloret%20-%20WiFi%20and%20LoRa%20Energy%20Consumption%20Comparison%20in%20IoT%20ESP%2032%20SX1278%20Devices.pdf
[15] https://www.mokolora.com/pt/waste-management-solution-with-lorawan/
[16] https://lcv.fee.unicamp.br/images/BTSym-22-Brasil/papers/BTSym2022_032.pdf
[17] https://github.com/amansharma7702/Smart-Dustbin-app
[18] https://pmc.ncbi.nlm.nih.gov/articles/PMC8071010/
[19] https://www.arduinoecia.com.br/product/sensor-ultrassonico-hc-sr04-plus/
[20] https://www.peteletricaufu.com.br/static/ceel/doc/artigos/artigos2015/ceel2015_artigo019_r01.pdf
[21] https://www.techtudo.com.br/listas/2024/09/lixeira-com-sensor-de-movimento-modelos-para-facilitar-o-dia-a-dia-edqualcomprar.ghtml
[22] https://www.youtube.com/watch?v=mEw1c6bvIrA
[23] https://smartcampus.prefeitura.unicamp.br/pub/artigos_relatorios/Lahis-Plataforma_Inteligente_de_Coleta_de_Residuos_baseda_em_Internet_das_Coisas_e_LPWAN.pdf
[24] https://recipp.ipp.pt/bitstream/10400.22/8059/1/DM_PauloGomes_2015_MEIM.pdf
[25] https://www.youtube.com/watch?v=uc-A4GclVrQ
[26] https://www.newtoncbraga.com.br/iot/19965-monitoramento-remoto-de-nivel-com-lorawan-mic572.html
[27] https://circuitdigest.com/microcontroller-projects/iot-based-smart-bin
[28] https://clubedomaker.com/esp32-pinout
[29] https://projectsfactory.in/product/smart-waste-management-using-lora/
[30] https://www.instructables.com/Waste-Bin-Monitoring-With-ESP32-CAM-and-Adafruit-I/
[31] https://naac.iem.edu.in/wp-content/uploads/2024/02/Smart-Waste-Bin-Sunando-Chowdhury.pdf
[32] https://www.makerhero.com/blog/atualizacao-de-software-ota-over-the-air-no-esp32/
[33] https://curtocircuito.com.br/blog/Categoria%20IoT/processamentos-e-ultra-low-power-do-esp32
[34] https://dev.to/adityabhuyan/designing-ultra-low-power-iot-devices-for-long-term-environmental-monitoring-challenges-and-solutions-502a
[35] https://github.com/douglaszuqueto/esp32-http-firmware
[36] https://www.fernandok.com/2018/07/economizando-bateria-com-deep-sleep.html
[37] https://pmc.ncbi.nlm.nih.gov/articles/PMC11290616/
[38] https://www.ufsm.br/app/uploads/sites/553/2020/07/91663-field_submission_abstract_file2.pdf
[39] https://www.ijltemas.in/DigitalLibrary/Vol.9Issue7/30-35.pdf
[40] https://www.nucleodoconhecimento.com.br/engenharia-eletrica/redes-de-lixeiras
[41] https://www.ecclo.com.br/post/jardins_de_tratamento_ods
[42] https://www.ibeas.org.br/conresol/conresol2023/VIII-006.pdf
[43] https://www.korewireless.com/news/benefits-of-smart-waste-management
[44] https://voluntariadoempresarial.com.br/ods-ideias-de-acoes-voluntarias/
[45] https://www.rts.com/blog/esg-waste-management/
[46] https://engemausp.submissao.com.br/22/arquivos/157.pdf
[47] https://www.link-labs.com/blog/top-5-reasons-to-use-smart-waste-management
[48] https://www.escoladereciclagem.com/lixeiras-inteligentes-revolucao-gerenciamento-residuos/
[49] https://citysolar.fi/waste-management-with-smart-bins/
[50] https://fablablivresp.prefeitura.sp.gov.br/projetos/robotica/lac-lixeira-inteligente
[51] https://www.gov.br/mdr/pt-br/noticias/parceria-com-o-ibge-resulta-em-novo-indicador-dos-objetivos-de-desenvolvimento-sustentavel
[52] https://blog.ecosoli.com.br/por-que-escolher-uma-lixeira-ecologica-beneficios-ambientais-e-economicos/
[53] https://www.linkedin.com/pulse/sustainability-through-smart-waste-management-zariot1-oofif
[54] https://capital.sp.gov.br/web/spregula/w/prefeitura-apresenta-mais-22-caminh%C3%B5es-da-coleta-de-lixo-movidos-%C3%A0-energia-limpa-para-reduzir-emiss%C3%A3o-de-poluentes-4
[55] https://www.sustentarewipis.com.br/wp-content/uploads/artigos/2021/431225.pdf
[56] https://saec.sp.gov.br/index.php/taxa-de-coleta-de-lixo-na-conta-de-agua/
[57] https://saec.sp.gov.br/wp-content/uploads/2023/06/Termo-de-Referencia-Especificacoes-Tecnicas.pdf
[58] https://saec.sp.gov.br/index.php/a-saec/
[59] https://www.catanduva.sp.gov.br/portal/noticias/3
[60] https://saec.sp.gov.br
[61] https://www.catanduva.sp.gov.br/portal/servicos_online
[62] https://saec.sp.gov.br/index.php/servicos/
[63] https://www.usinainfo.com.br/lora-613
[64] https://www.fundsforngos.org/proposals/sample-proposal-on-smart-waste-sorting-systems-for-effective-recycling-in-cities/
[65] https://lista.mercadolivre.com.br/heltec-esp32-lora
[66] https://ric.cps.sp.gov.br/bitstream/123456789/18987/1/eletronica_2022_2_davi_abreu_de_carvalho_biniot_a_lixeira_inteligente.pdf
[67] https://publikationen.bibliothek.kit.edu/1000134486/119146391
[68] https://www.youtube.com/watch?v=Q5Qkjljfilc
[69] https://bdta.abcd.usp.br/directbitstream/68494a95-b979-4032-9aea-10d202d4cb78/Almeida_HenriqueToledo_tcc.pdf
[70] https://repositorio.ufrn.br/bitstream/123456789/59648/1/MonitoramentoSalasLimpas_Neto_2024.pdf
[71] https://thinkz.ai/top-10-sustainable-cities-europe/
[72] http://biblioteca.ifce.edu.br/mobile/download.asp?idioma=ptbr&acesso=web&codigo=4799&tipo_midia=2&iUsuario=0&obra=88409&tipo=1&downloadApp=1
[73] https://core.ac.uk/download/571372853.pdf
[74] https://inatel.br/noticias/sistema-de-gerenciamento-de-residuos-usando-iot-pretende-solucionar-problemas-causados-pelo-acumulo-de-lixo-nas-vias-publicas
[75] https://www.circularinnovationlab.com/post/smart-cities-and-iot-the-future-of-waste-management
[76] https://repositorio.pucgoias.edu.br/jspui/bitstream/123456789/4355/1/TCC%20II%20-%20Wellington%20Alves%20dos%20Santos.pdf
[77] https://journals.sagepub.com/doi/full/10.3233/SCS-230007
[78] https://blog.saravati.com.br/explorando-o-potencial-do-esp32-em-projetos-iot/
[79] https://earth.org/smart-waste-management/
[80] https://www.jait.us/issues/JAIT-V13N6-569.pdf
[81] https://ojs.brazilianjournals.com.br/ojs/index.php/BRJD/article/download/53370/39675/131947
[82] https://ijaem.net/issue_dcp/Applying%20Esp32%20and%20Lora%20Ra%2002%20Module,%20Controlling%20and%20Monitoring%20Water%20Saving%20System%20in%20Agriculture.pdf
[83] https://www.arnabkumardas.com/platforms/everything-esp/iot-smart-dustbin-esp32-sim800l/
[84] https://gaotek.com/comparison-of-lorawan-and-wi-fi-halow/
[85] https://www.cin.ufpe.br/~tg/2019-1/TG_EC/tg-mhpr-final.pdf
[86] https://books-sol.sbc.org.br/index.php/sbc/catalog/download/88/386/657?inline=1
[87] https://randomnerdtutorials.com/esp32-lora-sensor-web-server/
[88] https://www.atbuftejoste.com.ng/index.php/joste/article/download/2172/pdf_1554
[89] https://news.rakwireless.com/lorawan-vs-zigbee-vs-ble-vs-wifi-vs-nb-iot/
[90] https://www.minew.com/pt/what-is-lorawan/
[91] https://www.makerhero.com/blog/o-que-e-lora/
[92] https://www.makerhero.com/blog/balanca-inteligente-com-sensor-de-peso-e-arduino-nano-esp32/
[93] https://www.makerhero.com/blog/sensor-ultrassonico-hc-sr04-ao-arduino/
[94] https://ambiental.t4h.com.br/em-foco/sensores-de-baixo-custo-contribuem-para-a-vigilancia-da-qualidade-do-ar/
[95] https://gustavocaetano.com.br/conheca-as-melhores-lixeiras-inteligentes-do-mercado-em-2024/
[96] https://ric.cps.sp.gov.br/handle/123456789/21480
[97] https://brcaptura.com.br/blog/a-chave-para-cidades-inteligentes-conectividade-iot-e-gestao-de-recursos/
[98] https://portal.vidadesilicio.com.br/hc-sr04-com-esp32/
[99] https://www.scielo.br/j/qn/a/GJctQLQ46TTw5v3fCmK3JCm/
[100] https://www.businessresearchinsights.com/pt/market-reports/smart-trash-bin-market-112325
[101] https://www.youtube.com/watch?v=7eweZU6JTbw
[102] https://www.fernandok.com/2017/12/sensor-ultrassonico-com-esp32.html
[103] https://www.hackster.io/simonepascucci/smart-dust-bin-with-riotos-and-esp-32-v3-5eb491
[104] https://blog.wjcomponentes.com.br/2022/04/20/esp32-lora-rede-lora/
[105] https://mjrobot.org/2017/09/26/iot-feito-facil-brincando-com-o-esp32-no-arduino-ide/
[106] https://projectsfactory.in/product/garbage-monitoring-system-using-lora-technology/
[107] https://www.makerguides.com/using-esp32-with-hc-sr04-ultrasonic-distance-sensor/
[108] https://www.youtube.com/watch?v=s3a2Gv3VuFQ
[109] https://curtocircuito.com.br/blog/Categoria%20IoT/conhecendo-esp32
[110] https://www.robocore.net/wifi/esp32-wifi-bluetooth
[111] https://www.manualdomaker.com/article/deep-sleep-no-esp32-esp32-ota-e-maquina-de-estado/
[112] https://www.mdpi.com/1424-8220/18/4/1282
[113] https://www.robocore.net/tutoriais/iot-devkit-introducao-wifi
[114] https://www.youtube.com/watch?v=J1hmD4m6ZD8
[115] https://sciendo.com/pdf/10.2478/sbeef-2024-0010
[116] https://www.mdpi.com/2673-4591/2/1/90
[117] https://repositorio.utfpr.edu.br/jspui/bitstream/1/25629/1/tecnicasgeolocalizacaoredeslorawan.pdf
[118] https://www.youtube.com/watch?v=fMGOr0kTcMw
[119] https://www.tandfonline.com/doi/full/10.1080/10962247.2022.2149636
[120] https://www.youtube.com/watch?v=J8m_ycEaxL0
[121] https://www.youtube.com/watch?v=cWfmJzzwIgA
[122] https://www.radioenge.com.br/wp-content/uploads/downloads-produtos/gateway-lorawan/tutorial-ttn.pdf
[123] https://www.iot.fizyka.pw.edu.pl/wp-content/uploads/2025/01/IoT4schools_smart_waste_bins_teacher_guide.pdf
[124] https://revistasmd.virtual.ufc.br/arquivos/volume-4/numero-2/rsmd-v4-n2-1.pdf
[125] https://www.ijstr.org/final-print/oct2017/Design-And-Development-Of-A-Smart-Waste-Bin.pdf
[126] https://wokwi.com/projects/380955141965929473
[127] https://tconline.feevale.br/tc/files/0001_5010.pdf
[128] https://www.instructables.com/Smart-Trash-Bin/
[129] https://www.h16b.com/en/news/sdg-ii
[130] https://www.tce.ms.gov.br/portal-modernizacao/assets/downloads/cartilha-ods/cartilha-ods-15-09-18.pdf
[131] https://brasil.un.org/pt-br/175171-gest%C3%A3o-dos-res%C3%ADduos-s%C3%B3lidos-%C3%A9-chave-para-desenvolvimento-sustent%C3%A1vel-da-am%C3%A9rica-latina
[132] https://smartwaste.co.za/reduce-your-environmental-impact-with-smart-waste/
[133] https://www.ipea.gov.br/ods/ods12.html
[134] https://sensoneo.com/how-smart-waste-fits-in-un-sustainable-development-goals-part-1/
[135] https://periodicos.puc-campinas.edu.br/sustentabilidade/article/download/5547/3501/27052
[136] https://sdgs.un.org/partnerships/household-waste-separation-initiate
[137] http://engemausp.submissao.com.br/21/anais/download.php?cod_trabalho=309
[138] https://www.mdpi.com/2071-1050/16/19/8486
[139] https://www.teraambiental.com.br/blog-da-tera-ambiental/como-a-gestao-de-residuos-colabora-com-o-cumprimento-dos-ods-da-onu
[140] https://www.h16b.com/en/news/sustainable-development-goals-im-detail---teil-iii
[141] https://exceedict.com/smart-bins-for-waste-management/
[142] https://www.green4t.com/arquivos/10129
[143] https://engemausp.submissao.com.br/25/anais/download.php?cod_trabalho=399
[144] https://ecocircuito.com.br/gestao-sustentavel-de-residuos-como-caminho-para-os-17-ods/
[145] https://revistaft.com.br/o-uso-do-lixo-e-impactos-gerados-com-a-sustentabilidade-como-forma-de-energia-inteligente/
[146] https://cestosdelixoelixeiras.com.br/blog-lixeiras/curiosidades-do-lixo-dados-e-estatisticas-sobre-o-descarte-correto
[147] https://g1.globo.com/pr/parana/especial-publicitario/composta-mais/residuo-nao-e-lixo-e-oportunidade/noticia/2023/11/28/12-praticas-de-reducao-de-carbono-para-empresas.ghtml
[148] https://www.ipea.gov.br/ods/ods11.html
[149] https://saec.sp.gov.br/index.php/plano-integrado-de-saneamento-basico-de-catanduva-revisao-e-atualizacao-2019/
[150] https://saec.sp.gov.br/index.php/2024/12/02/mudanca-para-melhor/
[151] https://saec.sp.gov.br/index.php/2024/07/01/coleta-seletiva-nos-bairros-2/
[152] https://saec.sp.gov.br/index.php/2024/05/23/saneamento-basico/
[153] https://www.instagram.com/interligando_/p/DDE_l2HRpHS/
[154] https://oregional.com.br/noticias/detalhes/saec-inicia-servico-gratuito-de-recolha-de-materiais-inserviveis
[155] https://www.aguaesaneamento.org.br/municipios-e-saneamento/sp/catanduva
[156] https://saec.sp.gov.br/index.php/informacoes-e-servicos/
[157] https://www.instagram.com/acordacatanduva/p/DDzh1FwO7L3/mudan%C3%A7a-para-melhor-aten%C3%A7%C3%A3o-catanduvenses-visando-melhorias-no-servi%C3%A7o-a-saec-mu/
[158] https://saec.sp.gov.br/index.php/2021/06/15/coleta-mantida/
[159] https://saec.sp.gov.br/wp-content/uploads/2019/09/PlanoSaneamentoAPENDICE_Relatori_-2_PrimeiraAudiencia-Publica.pdf
[160] https://www.catanduva.sp.gov.br/servicos
[161] https://catanduvashow.com.br/2024/12/02/saec-muda-horario-de-coleta-de-lixo-noturna-para-o-turno-diurno-para-oferecer-melhorias-no-servico-em-20-bairros-da-cidade/
[162] https://shopee.com.br/search
[163] https://lista.mercadolivre.com.br/modulo-lora-sx1278
[164] https://repositorio.ufpb.br/jspui/bitstream/123456789/15833/1/AMSN23112018.pdf
[165] https://www.superfy.com/key-steps-to-smart-waste-management-solution/
[166] https://shopee.com.br/Placa-LoRa-433MHz-SX1278-ESP32-Display-OLED-0.96-c-Bluetooth-i.624537268.23312849420
[167] http://www.jornacitec.fatecbt.edu.br/index.php/XIIJTC/XIIJTC/paper/view/2968/3315
[168] https://www.mdpi.com/1424-8220/22/3/1288
[169] https://www.ardurobotica.com.br/MLB-1343955447-hc-sr04-sensor-ultrassonico-arduino-esp8266-nodemcu-esp32-_JM

---
Resposta do Perplexity: pplx.ai/share
