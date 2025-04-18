#define POT_PIN A0
#define PONTE_H_1 7
#define PONTE_H_2 6
#define ENABLE_PONTE_H 5

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

//=====================================================
//  FUNCS
//=====================================================

//=====================================================
//  SETUP E LOOP
//=====================================================
void setup() 
{
  Serial.begin(115200);

  pinMode(PONTE_H_1, OUTPUT);
  pinMode(PONTE_H_2, OUTPUT);
  pinMode(ENABLE_PONTE_H, OUTPUT);
}

void loop() 
{
  int valPot = analogRead(POT_PIN);
  int vel = map(valPot, 0, 1023, -255, 255);
  int PWM = min(abs(vel), 255);
  long long tempo = millis();

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

  // PRint das variaveis do sistema
  Serial.print((float)tempo / 1000, 3);
  Serial.print("\t");
  Serial.print(valPot);
  Serial.print("\t");
  Serial.print(vel);
  Serial.print("\t");
  Serial.println(PWM);

}

//=====================================================
//  FUNCS
//=====================================================