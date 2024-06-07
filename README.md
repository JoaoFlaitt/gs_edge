# gs_edge

João Víctor Flaitt - RM553888
Lucas Bertolasi - RM553183
Miguel Leal - RM553009

Este projeto utiliza um ESP32 para monitorar o pH da água, detectar presença,
medir distâncias, e registrar a temperatura e umidade. Este sistema pode ser
utilizado em várias aplicações, como monitoramento ambiental, automação residencial, entre outros.

Descrição do Projeto
O projeto integra diversos sensores com um ESP32:
• Sensor de pH para medir a acidez da água.
• Sensor ultrassônico para medir a distância de objetos.
• Sensor PIR para detectar presença de movimento.
• Sensor DHT22 para medir temperatura e umidade.

Estrutura do Código
O código realiza as seguintes funções:
1. Leitura do valor de pH e impressão no monitor serial.
2. Detecção de presença usando um sensor PIR.
3. Medição de distância usando um sensor ultrassônico, que é ativada
somente quando o sensor PIR detecta movimento.
4. Leitura e impressão dos valores de temperatura e umidade do sensor
DHT22.

Componentes Utilizados
• ESP32
• Potenciômetro
• Sensor Ultrassônico (HC-SR04)
• Sensor de Movimento PIR
• Sensor de Temperatura e Umidade DHT22
• Jumpers e protoboard

Requisitos e Dependências
• Plataforma de desenvolvimento Arduino IDE
• Biblioteca DHTesp para o sensor DHT22

Instruções de Uso
1. Configuração do Hardware
Conecte os sensores ao ESP32 conforme o seguinte esquema de pinos:
• Potenciômetro: pino de saída no pino 12 do ESP32.
• Sensor Ultrassônico (HC-SR04): TRIG no pino 14, ECHO no pino 15.
• Sensor de Movimento PIR: pino de saída no pino 21.
• Sensor DHT22: pino de saída no pino 19.
2. Instalação da Biblioteca DHTesp
Abra a Arduino IDE e vá para Sketch -> Include Library -> Manage
Libraries. Procure por DHTesp e instale a biblioteca.
3. Upload do Código
Carregue o código fornecido para o seu ESP32. Certifique-se de selecionar a
placa correta (ESP32 Dev Module) e a porta serial correta na Arduino IDE.
4. Monitoramento
Após carregar o código, abra o Monitor Serial na Arduino IDE para ver as
leituras dos sensores. O monitor serial deve ser configurado para uma taxa de
9600 baud.
