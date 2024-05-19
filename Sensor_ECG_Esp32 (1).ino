#include <WiFi.h>
#include <PubSubClient.h>
 
// Configurações de rede WiFi e MQTT
#define WIFISSID "NomeDaRede"           // Nome da rede WiFi
#define PASSWORD "SenhaDaRede"          // Senha da rede WiFi
#define TOKEN "TokenDaPlataformaUbidots" // Token da plataforma Ubidots
#define MQTT_CLIENT_NAME "NomeDoClienteMqtt" // Nome do cliente MQTT

// Configurações da plataforma Ubidots
#define VARIABLE_LABEL "sensor"         // Rótulo da variável no Ubidots
#define DEVICE_LABEL "esp32"            // Rótulo do dispositivo no Ubidots

// Pinos utilizados
#define SENSOR A0                       // Pino analógico para o sensor ECG
#define LED_PIN 18                      // Pino do LED (D18)

// Variáveis para conexão MQTT
char mqttBroker[]  = "industrial.api.ubidots.com"; // Endereço do broker MQTT
char payload[100];                                // Buffer para payload MQTT
char topic[150];                                  // Buffer para tópico MQTT
char str_sensor[10];                              // Buffer para valor do sensor em string

WiFiClient ubidots;       // Cliente WiFi
PubSubClient client(ubidots); // Cliente MQTT

// Função callback para recebimento de mensagens MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length); // Copia o payload para um buffer local
  p[length] = NULL;
  Serial.write(payload, length); // Escreve o payload no serial monitor
  Serial.println(topic);         // Escreve o tópico no serial monitor
}

// Função para reconectar ao broker MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.println("Tentando conexão MQTT...");
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 2 segundos");
      delay(2000);
    }
  }
}

// Função de setup inicial
void setup() {
  Serial.begin(115200);        // Inicializa a comunicação serial
  WiFi.begin(WIFISSID, PASSWORD); // Conecta ao WiFi
  
  pinMode(SENSOR, INPUT);      // Configura o pino do sensor como entrada
  pinMode(LED_PIN, OUTPUT);    // Configura o pino do LED como saída
  
  Serial.println();
  Serial.print("Aguardando WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("WiFi Conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP()); // Mostra o endereço IP obtido
  client.setServer(mqttBroker, 1883); // Configura o broker MQTT
  client.setCallback(callback);       // Define a função callback
}

// Função principal de loop
void loop() {
  if (!client.connected()) {
    reconnect(); // Reconecta ao broker MQTT se desconectado
  }
 
  // Configura o tópico e o payload para envio ao Ubidots
  sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
  sprintf(payload, "%s", ""); 
  sprintf(payload, "{\"%s\":", VARIABLE_LABEL); 
  
  float sensor = analogRead(SENSOR); // Lê o valor do sensor
  dtostrf(sensor, 4, 2, str_sensor); // Converte o valor do sensor para string
  sprintf(payload, "%s {\"value\": %s}}", payload, str_sensor); // Formata o payload
  Serial.println("Publicando dados na nuvem Ubidots");
  client.publish(topic, payload); // Publica os dados no tópico MQTT
  client.loop(); // Mantém a conexão MQTT ativa

  // Verifica se o sensor está recebendo valores
  if (sensor > 0) {
    digitalWrite(LED_PIN, HIGH); // Liga o LED se o valor do sensor for positivo
  } else {
    digitalWrite(LED_PIN, LOW);  // Desliga o LED se o valor do sensor for zero ou negativo
  }
  
  delay(500); // Aguarda 500 milissegundos antes de repetir o loop
}
