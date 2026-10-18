## Caracterização experimental das faixas de transimpedância e linearidade do sistema de aquisição

A caracterização do estágio de medição de corrente do potenciostato foi realizada utilizando células resistivas de valores conhecidos, possibilitando relacionar a tensão efetivamente aplicada à carga com a corrente teórica correspondente. Essa abordagem permitiu avaliar experimentalmente não apenas os valores nominais dos resistores de realimentação, mas o comportamento da **cadeia completa de aquisição**, incluindo o amplificador de transimpedância, a chave analógica ADG444, o estágio de condicionamento e a tensão apresentada à entrada do conversor ADS1115.

A corrente de referência foi determinada pela Lei de Ohm:

\[
I=\frac{V_{\mathrm{carga}}}{R_{\mathrm{carga}}}
\]

em que \(V_{\mathrm{carga}}\) corresponde à tensão medida externamente sobre a carga resistiva. Para cada configuração de ganho, essa corrente foi correlacionada à tensão \(V_{ADS}\), medida diretamente na entrada do ADS1115. As curvas foram ajustadas pelo modelo linear:

\[
I_{nA}=aV_{ADS}+b
\]

sendo \(I_{nA}\) a corrente em nanoampères.

O resistor de transimpedância base foi definido em **10 MΩ**. As demais faixas são obtidas pela conexão de resistores adicionais em paralelo, por meio do ADG444:

\[
R_{TIA0}=10\,M\Omega
\]

\[
R_{TIA1}=10\,M\Omega\parallel15\,k\Omega
\approx14,98\,k\Omega
\]

\[
R_{TIA2}=10\,M\Omega\parallel150\,k\Omega
\approx147,78\,k\Omega
\]

\[
R_{TIA3}=10\,M\Omega\parallel2\,M\Omega
\approx1,667\,M\Omega
\]

Para os ganhos 1, 2 e 3 foi utilizada uma célula resistiva de **9,426 MΩ**. No ganho 0, de maior sensibilidade, os melhores resultados foram obtidos utilizando uma carga de **14,1004 MΩ** e restringindo a análise à região aproximadamente compreendida entre 0,5 V e 4,1 V na entrada do ADS1115.

### Ganho 1 — menor transimpedância

O ganho 1 corresponde à associação de 10 MΩ com 15 kΩ, resultando em aproximadamente 14,98 kΩ de transimpedância nominal. A relação experimental obtida foi:

\[
\boxed{
I_{nA}=-69464,57V_{ADS}+171958,74
}
\]

com:

\[
\boxed{R^2=0,999899}
\]

A transimpedância efetiva experimental calculada a partir da inclinação da curva foi de aproximadamente:

\[
\boxed{R_{TIA,\mathrm{exp}}\approx14,40\,k\Omega}
\]

valor bastante próximo dos 14,98 kΩ previstos teoricamente.

A faixa de tensão sobre a célula caracterizada foi aproximadamente:

\[
-1,272\;V \leq V_{\mathrm{carga}}\leq+2,935\;V
\]

correspondendo a uma faixa aproximada de corrente de:

\[
-135,0\;nA\leq I\leq+311,4\;nA
\]

Essa configuração apresenta a menor sensibilidade entre as quatro faixas e, portanto, é a mais apropriada para correntes relativamente maiores ou para condições nas quais é necessária maior margem contra saturação.

### Ganho 2 — faixa intermediária

No ganho 2, o resistor de 150 kΩ é colocado em paralelo com o resistor base de 10 MΩ, resultando em uma transimpedância nominal de aproximadamente 147,78 kΩ.

A regressão experimental foi:

\[
\boxed{
I_{nA}=-6950,04V_{ADS}+17204,02
}
\]

com:

\[
\boxed{
R^2=0,999998
}
\]

A transimpedância efetiva experimental foi estimada em:

\[
\boxed{
R_{TIA,\mathrm{exp}}\approx143,88\,k\Omega
}
\]

demonstrando excelente concordância com o valor nominal.

A tensão aplicada sobre a carga durante a caracterização esteve aproximadamente entre:

\[
-2,499\;V\leq V_{\mathrm{carga}}\leq+2,938\;V
\]

correspondendo aproximadamente a:

\[
-265,1\;nA\leq I\leq+311,7\;nA
\]

Essa faixa apresentou excelente linearidade e constitui um bom compromisso entre sensibilidade e faixa dinâmica, sendo adequada para utilização geral do instrumento.

### Ganho 3 — alta sensibilidade

O ganho 3 é obtido pela associação do resistor de 2 MΩ com os 10 MΩ da realimentação principal:

\[
R_{TIA3}\approx1,667\,M\Omega
\]

Considerando os pontos experimentais consistentes, obteve-se:

\[
\boxed{
I_{nA}=-613,001V_{ADS}+1517,193
}
\]

com:

\[
\boxed{
R^2=0,99999997
}
\]

A transimpedância efetiva experimental foi:

\[
\boxed{
R_{TIA,\mathrm{exp}}\approx1,631\,M\Omega
}
\]

novamente muito próxima do valor nominal.

A faixa caracterizada sobre a carga resistiva foi:

\[
-2,499\;V\leq V_{\mathrm{carga}}\leq+2,939\;V
\]

correspondendo aproximadamente a:

\[
-265,1\;nA\leq I\leq+311,8\;nA
\]

Entre as três faixas comutadas pelo ADG444, essa configuração apresentou a maior sensibilidade e excelente linearidade, sendo particularmente adequada para correntes reduzidas.

### Ganho 0 — máxima sensibilidade

No ganho 0, nenhuma chave do ADG444 é ativada, permanecendo somente o resistor de realimentação de 10 MΩ. Por apresentar a maior transimpedância nominal, essa configuração é também a mais sensível a correntes pequenas e a mais suscetível à aproximação dos limites de excursão da cadeia analógica.

Os melhores resultados experimentais foram obtidos com uma carga de **14,1004 MΩ**, restringindo a operação à região aproximadamente compreendida entre:

\[
0,5\;V\lesssim V_{ADS}\lesssim4,1\;V
\]

A faixa correspondente de tensão sobre a carga foi aproximadamente:

\[
\boxed{
-0,859\;V\lesssim V_{\mathrm{carga}}\lesssim+1,137\;V
}
\]

e a faixa de corrente:

\[
\boxed{
-60,9\;nA\lesssim I\lesssim+80,6\;nA
}
\]

A regressão experimental resultou em:

\[
\boxed{
I_{nA}=-43,2972V_{ADS}+106,9020
}
\]

com:

\[
\boxed{
R^2=0,999984
}
\]

e erro RMS de apenas aproximadamente:

\[
\boxed{0,177\;nA}
\]

O ponto correspondente à corrente nula foi:

\[
\boxed{
V_{ADS}(I=0)\approx2,469\;V
}
\]

A transimpedância efetiva da cadeia completa foi estimada em:

\[
\boxed{
R_{TIA,\mathrm{exp}}\approx23,10\,M\Omega
}
\]

Esse valor é superior aos 10 MΩ do resistor físico de realimentação. Portanto, deve ser interpretado como uma **transimpedância experimental efetiva da cadeia TIA + condicionamento**, e não simplesmente como o valor de R15.

O resultado demonstra que a faixa de maior ganho apresenta elevada linearidade quando operada dentro de uma janela restrita e é particularmente interessante para medições de correntes da ordem de dezenas de nanoampères.

### Síntese dos melhores resultados experimentais

| Ganho | \(R_{TIA}\) nominal | Carga resistiva | Faixa de tensão sobre a carga | Faixa de corrente | Equação experimental | \(R^2\) | \(R_{TIA}\) efetiva experimental | Variação aproximada por 1 nA | Aplicação recomendada |
|---|---:|---:|---:|---:|---|---:|---:|---:|---|
| **0** | 10 MΩ | **14,1004 MΩ** | **−0,859 a +1,137 V** | **−60,9 a +80,6 nA** | \(I=-43,2972V_{ADS}+106,9020\) | **0,999984** | **23,10 MΩ** | **≈23,1 mV/nA** | Máxima sensibilidade; baixas correntes e soluções de baixa concentração; operar em faixa restrita |
| **1** | 14,98 kΩ | 9,426 MΩ | −1,272 a +2,935 V | −135,0 a +311,4 nA | \(I=-69464,57V_{ADS}+171958,74\) | **0,999899** | **14,40 kΩ** | ≈0,0144 mV/nA | Correntes maiores e maior margem contra saturação |
| **2** | 147,78 kΩ | 9,426 MΩ | −2,499 a +2,938 V | −265,1 a +311,7 nA | \(I=-6950,04V_{ADS}+17204,02\) | **0,999998** | **143,88 kΩ** | ≈0,144 mV/nA | Faixa intermediária e uso geral |
| **3** | 1,667 MΩ | 9,426 MΩ | −2,499 a +2,939 V | −265,1 a +311,8 nA | \(I=-613,001V_{ADS}+1517,193\) | **0,99999997** | **1,631 MΩ** | ≈1,63 mV/nA | Alta sensibilidade com ampla região linear |

### Comparação da sensibilidade

A sensibilidade experimental aumenta progressivamente na sequência:

\[
G_1<G_2<G_3<G_0
\]

A variação aproximada da tensão observada na cadeia de aquisição para uma alteração de corrente de apenas 1 nA foi de aproximadamente:

\[
G_1\approx0,0144\;mV/nA
\]

\[
G_2\approx0,144\;mV/nA
\]

\[
G_3\approx1,63\;mV/nA
\]

\[
G_0\approx23,1\;mV/nA
\]

Dessa forma, o ganho 0 apresenta sensibilidade experimental aproximadamente três ordens de grandeza superior à faixa de menor ganho, sendo particularmente relevante para correntes reduzidas.

Essa elevada sensibilidade, entretanto, reduz a faixa dinâmica disponível. Por esse motivo, o ganho 0 deve ser utilizado prioritariamente enquanto a tensão na entrada do ADS1115 permanecer aproximadamente entre:

\[
\boxed{0,5\;V<V_{ADS}<4,1\;V}
\]

Quando o sinal se aproximar dos extremos dessa janela, torna-se recomendável reduzir a transimpedância.

### Estratégia de utilização das faixas

Os resultados experimentais permitem estabelecer uma estratégia de seleção de ganho baseada na magnitude do sinal. O ganho 0 deve ser priorizado para as menores correntes, particularmente abaixo da ordem de \(100\,nA\). Quando a tensão do estágio de leitura se aproximar dos limites da região linear, pode-se realizar a comutação para o ganho 3. Para correntes progressivamente maiores, os ganhos 2 e 1 oferecem maior margem de excursão.

Uma futura rotina de seleção automática poderá, portanto, seguir conceitualmente:

\[
G_0\rightarrow G_3\rightarrow G_2\rightarrow G_1
\]

à medida que a corrente aumenta, realizando o processo inverso quando a amplitude diminui.

É preferível utilizar a própria tensão medida pelo ADS1115 como critério de comutação, pois ela representa diretamente a proximidade da saturação da cadeia analógica.

### Considerações sobre medições de baixa concentração

O desempenho obtido no ganho 0 é especialmente relevante para futuras aplicações envolvendo soluções de baixa concentração. A caracterização experimental demonstrou resposta altamente linear para correntes compreendidas aproximadamente entre **−61 nA e +81 nA**, com coeficiente de determinação de aproximadamente 0,999984.

Esse resultado indica que o sistema possui capacidade de resolver variações de corrente na ordem de nanoampères quando operado na faixa de máxima sensibilidade.

Entretanto, essa capacidade elétrica não deve ser interpretada diretamente como limite de detecção de concentração. A determinação do limite de detecção analítico exigirá posteriormente ensaios com soluções de concentrações conhecidas, medições repetidas do branco e determinação da dispersão do sinal de fundo.

### Conclusão da caracterização

Os ensaios realizados demonstraram que a arquitetura com múltiplas transimpedâncias permite ao potenciostato operar em diferentes ordens de grandeza de corrente, mantendo elevada linearidade quando cada faixa é utilizada dentro de sua região apropriada.

Os ganhos 1, 2 e 3 apresentaram coeficientes de determinação superiores a 0,9998, enquanto o ganho 0, quando restrito à sua região de operação recomendada e utilizando uma carga de maior resistência, apresentou:

\[
\boxed{R^2=0,999984}
\]

para correntes da ordem de dezenas de nanoampères.

Dessa forma, os resultados experimentais sustentam o emprego de uma estratégia de múltiplas faixas de ganho no potenciostato, permitindo conciliar **ampla faixa dinâmica** e **alta sensibilidade**, além de oferecer uma base experimental para a implementação futura de autorange e para investigações voltamétricas envolvendo diferentes níveis de concentração.


https://chatgpt.com/s/t_6ad539dba1f08191a31a3c36a75181e0
