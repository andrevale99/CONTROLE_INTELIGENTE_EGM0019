int POT_PIN = A0;
int PONTE_H_1 = 7;
int PONTE_H_2 = 6;
int ENABLE_PONTE_H = 5;

void setup() 
{
  pinMode(PONTE_H_1, OUTPUT);
  pinMode(PONTE_H_2, OUTPUT);
  pinMode(ENABLE_PONTE_H, OUTPUT);
}

void loop() 
{
  int valPot = analogRead(POT_PIN);
  int vel = map(valPot, 0, 1023, -255, 255);
  int PWM = min(abs(vel), 255);

  if (vel > 0)
  {
    digitalWrite(PONTE_H_1, LOW);
    digitalWrite(PONTE_H_2, HIGH);
  }
  else
  {
    digitalWrite(PONTE_H_1, HIGH);
    digitalWrite(PONTE_H_2, LOW);
  }

  analogWrite(ENABLE_PONTE_H, PWM);
}
