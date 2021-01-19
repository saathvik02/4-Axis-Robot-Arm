#include <Servo.h>

int pot_pin_claw = A3;
int pot_pin_bottom = A1;
int pot_pin_joint1 = A2;
int pot_pin_joint2 = A0;

int value_claw;
int value_bottom;
int value_joint1;
int value_joint2;

Servo servo_claw;
Servo servo_bottom;
Servo servo_joint1;
Servo servo_joint2;

void setup() {
  servo_claw.attach(3);
  servo_bottom.attach(11);
  servo_joint1.attach(10);
  servo_joint2.attach(9);
  Serial.begin(9600);
}

void loop() {
  int pot_inputs[4];
  pot_inputs[0] = analogRead(pot_pin_claw);
  pot_inputs[1] = analogRead(pot_pin_bottom);
  pot_inputs[2] = analogRead(pot_pin_joint1);
  pot_inputs[3] = analogRead(pot_pin_joint2);

  if(pot_inputs[0] > 511) {
    value_claw = 1;
  } else {
    value_claw = 0;
  }
  
  value_bottom = map(pot_inputs[1], 100, 600, 180, 0);
  value_joint1 = map(pot_inputs[2], 1023, 600, 0, 180);
  value_joint2 = map(pot_inputs[3], 600, 1023, 180, 0);

  if(value_claw) {
    servo_claw.write(260);
  } else {
    servo_claw.write(120);
  }
  
  servo_bottom.write(value_bottom);
  servo_joint1.write(value_joint1);
  servo_joint2.write(value_joint2);

  delay(10);
}
