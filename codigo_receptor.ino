// ==================================== RECEPTOR ===========================================


//bibliotecas necessárias

#include <ESP32Servo.h>
#include <PubSubClient.h>
#include <WifiManager.h>

// variaveis para o controle do Servo

#define pinRegistro 2 // pino do sinal PWM
#define chave 4 // pino do mosfet


// funções auxiliares para o servo
bool abrirRegistro();
bool fecharRegistro();


// funções auxiliares para o MQTT

void recebeDados();
void enviaDados();

// funções auxiliares para a conexão

void conectaWifi();
void conectaMQTT();
void mantemConexao();


//objetos

Servo registro;

void setup() {
 registro.attach(pinRegistro); // atribui ao objeto o pino de pwm









}

void loop() {
  






}

bool abrirRegistro(){
  bool confirmar = 1;
  int i = 180;

  for(i = 180; i >= 0; i--){
    registro.write(i);
    delay(15);
  }

  return confirmar;
}


bool fecharRegistro(){
  bool confirmar = 1;
  int i = 0;

  for(i = 0; i <= 180; i++){
    registro.write(i);
    delay(15);
  }

  return confirmar;
}

