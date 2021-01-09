#include <SigFox.h>

void setup() {
  Serial.begin(9600);
  delay(1000);

  if (!SigFox.begin()) {
    Serial.println("Error placa");
    return;
  }

  SigFox.end();
  
  SigFox.debug();
  }
  
  void loop(){

  SigFox.begin();

  delay(200);

  byte temperatura = (int)SigFox.internalTemperature();

  Serial.print("La temperatura interna es de: ");
  Serial.println(temperatura);

  SigFox.status();
  delay(1);

  SigFox.beginPacket();

  SigFox.write(temperatura);

  int resultado = SigFox.endPacket();

  if(resultado == 0){
    Serial.println("Mensaje enviado !!!");
  }
  else{
    Serial.println("Error al enviar el mensaje");
    while(1);
  }

  SigFox.end();
  
  delay(900000);
  }