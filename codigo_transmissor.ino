//===================================================== TRANSMISSOR ======================================================

// Bibliotecas
#include <IOXhop_FirebaseESP32.h>
#include <WiFiManager.h>


//========== variaveis====================================

#define botaoFechar 5
#define botaoAbrir 4


// Caminho do banco
#define FIREBASE_HOST "microcontroladores-45c55-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "e2PUt2uIYR0qZU8YAZa1kVuR2P7mSJ6imJyyuHt6"



// funções
bool conectarWifi();
void enviarComando();



void setup() {
  Serial.begin(115200);
  conectarWifi();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // definições dos pinos 

  pinMode(botaoAbrir, INPUT_PULLUP);
  pinMode(botaoFechar, INPUT_PULLUP);



}

void loop() {
  enviarComando();

}

bool conectarWifi(){

  WiFiManager wm;
  return wm.autoConnect("Transmissor");

}

void enviarComando(){
  bool abrir;
  bool fechar;


  abrir = digitalRead(botaoAbrir);
  fechar = digitalRead(botaoFechar);

  if(abrir == 0){
    Firebase.setBool("/Posicao", false);
    Serial.println(abrir);
    delay(1000);

  }

  if(fechar == 0){
    Firebase.setBool("/Posicao", true);
    Serial.println(fechar);
    delay(1000);

  }

}