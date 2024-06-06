// Incluímos a biblioteca
#include "DHTesp.h"

// Definimos os pinos para os sensores
#define POTPIN 12       // Pino do potenciômetro
#define TRIG_PIN 14     // Pino Trig do sensor ultrassônico
#define ECHO_PIN 15     // Pino Echo do sensor ultrassônico
#define PIR_PIN 21      // Pino do sensor de movimento PIR
#define PIN_DHT 19      // Pino do sensor de temperatura e umidade DHT22

// Instanciamos o sensor DHT
DHTesp dht;

void setup() {
  // Configuramos os pinos dos sensores
  pinMode(POTPIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  // Inicializamos a comunicação serial
  Serial.begin(9600);

  // Inicializamos o sensor DHT
  dht.setup(PIN_DHT, DHTesp::DHT22);
}

void loop() {
  // Leitura e impressão do valor de pH
  float pHValue = map(analogRead(POTPIN), 0, 4095, 0.0, 14.0);  // Mapeia a leitura analógica para a faixa de pH 0-14
  Serial.print("pH Value: ");
  Serial.println(pHValue, 2); // Imprime o valor de pH com 2 casas decimais

  // Leitura do sensor de presença PIR
  int pirValue = digitalRead(PIR_PIN);

  if (pirValue == 1) {
    // Leitura e impressão da distância do sensor ultrassônico se houver presença
    long duration, distance;

    // Emitir um pulso ultrassônico
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Medir o tempo de retorno do eco
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calcular a distância em centímetros
    distance = (duration / 2) * 0.0343;

    // Exibir a distância e a informação de presença no monitor serial
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("REDE DE PESCA LOCALIZADA!");
  } else {
    // Exibir apenas o pH e a informação de ausência de presença
    Serial.println("Sem nenhuma rede de pesca!");
  }

  // Leitura e impressão dos valores de temperatura e umidade do sensor DHT
  TempAndHumidity data = dht.getTempAndHumidity();
  Serial.println("Temperatura: " + String(data.temperature, 2) + "°C");
  Serial.println("Umidade: " + String(data.humidity, 1) + "%");
  Serial.println("---");

  delay(2000);  // Aguarda 1 segundo antes de fazer a próxima leitura
}