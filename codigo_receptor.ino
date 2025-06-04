//===================================================== RECEPTOR ======================================================

// Bibliotecas
#include <ESP32Servo.h>
#include <IOXhop_FirebaseESP32.h>
#include <WiFiManager.h>

// Variáveis
#define pinServo 2    // Pino do servo
#define pinMosfet 4   // Pino do MOSFET

// Caminho do banco
#define FIREBASE_HOST "microcontroladores-45c55-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "e2PUt2uIYR0qZU8YAZa1kVuR2P7mSJ6imJyyuHt6"

// Funções
void abrirRegistro();
void fecharRegistro();
void monitorarDados();
bool conectarWifi();

// Objetos
Servo registro;

// Estado atual do servo (0 = aberto, 1 = fechado). Começa indefinido (-1)
int estadoAtual = -1;

void setup() {
  conectarWifi();

  pinMode(pinMosfet, OUTPUT);
  digitalWrite(pinMosfet, LOW); // Garante que o MOSFET inicie desligado

  registro.attach(pinServo);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  monitorarDados();
  delay(2000); // Verifica a cada 3 segundos
}

void monitorarDados() {
  bool posicao = Firebase.getBool("/Posicao");

  if (posicao != estadoAtual) {
    // Houve mudança
    if (posicao == 0) {
      abrirRegistro();

    }
    else if (posicao == 1) {
      fecharRegistro();
    }
    estadoAtual = posicao; // Atualiza estado atual
  } 
  else {
   // nao faz nada
  }
}

bool conectarWifi() {
  WiFiManager wm;
  return wm.autoConnect("Receptor");
}

void abrirRegistro() {
  digitalWrite(pinMosfet, HIGH);
  delay(150);
  registro.write(0);
  delay(1000);
  digitalWrite(pinMosfet, LOW);
}

void fecharRegistro() {
  digitalWrite(pinMosfet, HIGH);
  delay(150);
  registro.write(180);
  delay(1000);
  digitalWrite(pinMosfet, LOW);
}
