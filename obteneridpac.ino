#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <RTCZero.h>

void setup() {
  // Configuraci�n del monitor serie
  Serial.begin(9600);
  delay(1000);
  
  // Iniciamos m�dulo Sigfox
  if(!SigFox.begin()){
    Serial.println("Error al iniciar m�dulo Sigfox");
    return;
  }

  // Mostramos la informaci�n del ID y de PAC
  Serial.println("ID = " + SigFox.ID());
  Serial.println("PAC = " + SigFox.PAC());

  // Apagamos el m�dulo
  SigFox.end();
}

void loop() {
  // En el loop no hacemos nada

}