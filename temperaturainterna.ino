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

  Serial.print("Temperatura interna actual: ");
  Serial.println(temperatura);

  SigFox.status();
  delay(1);

  SigFox.beginPacket();

  SigFox.write(temperatura);

  int resultado = SigFox.endPacket();

  if(resultado == 0){
    Serial.println("Missatge enviat !!!");
  }
  else{
    Serial.println("Error en enviar el missatge");
    while(1);
  }

  SigFox.end();
  
  delay(900000);
  }