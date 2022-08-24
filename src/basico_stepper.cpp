/*
=======================================
Ejemplo basico de manejo de motor paso a paso (stepper)
Usa tres señales:
pulso: cada paso del motor stepper.
dir: determina sentido horario (CW) o antihorario (CCW).
enable: Habiltación de la corriente del motor. 

=========================================
*/
#include <Arduino.h>
#define pulse 5
#define dir 6
#define enable 7
int retardo;

void setup() {
  pinMode(pulse, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(enable, HIGH);
  digitalWrite(dir, LOW);
}

void loop() {
  retardo = 600;
  for (register int i=0; i<800; i++){
  digitalWrite(pulse, LOW);
  delayMicroseconds(retardo);
  digitalWrite(pulse, HIGH);
  delayMicroseconds(retardo);

  }
delay(300);
  digitalWrite(dir, HIGH);
delay(300);

for (register int i=0; i<4000; i++){
  if (retardo >= 300) retardo -= 5;
  digitalWrite(pulse, LOW);
  delayMicroseconds(retardo);
  digitalWrite(pulse, HIGH);
  delayMicroseconds(retardo);
}
delay(300);
  digitalWrite(dir, LOW);
delay(300);

} 