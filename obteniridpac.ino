#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <RTCZero.h>

void setup() {
  // Configurar monitor serial
  Serial.begin(9600);
  delay(1000);
  
  // Iniciem Sigfox
  if(!SigFox.begin()){
    Serial.println("Error inici Sigfox");
    return;
  }

  // Mostrem ID i PAC
  Serial.println("ID = " + SigFox.ID());
  Serial.println("PAC = " + SigFox.PAC());

  // Apaguem Sigfox
  SigFox.end();
}

void loop() {
  // Al loop no fem res 

}