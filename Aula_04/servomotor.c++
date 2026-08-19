// C++ code
#include <Servo.h>

Servo servoMotor1;

int potenciometro = A0;
int valorLido;
int angulo;

void setup() {
  servoMotor1.attach(9);
}

void loop() {
  valorLido = analogRead(potenciometro);

  angulo = map(valorLido, 0, 1023, 0, 180);

  servoMotor1.write(angulo);

  delay(15);
}
