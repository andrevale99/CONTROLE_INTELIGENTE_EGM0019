#define POT_GPIO_INPUT A0

#define GPIO_PONTE_H_1 7
#define GPIO_PONTE_H_2 6
#define GPIO_PONTE_H_ENABLE 5

#define ENCODER_GPIO_A 4
#define ENCODER_GPIO_B 3

#define PULSOS_POR_VOLTA 341.2

#define PERIODO 100 // ms

volatile long PulsosEncoderA = 0;
volatile long PulsosPorPeriodo = 0;
volatile long long ultimoTempo = 0;

void atualizaEncoder(void)
{
  if (digitalRead(ENCODER_GPIO_A) == digitalRead(ENCODER_GPIO_B))
  {
    PulsosEncoderA++;
    PulsosPorPeriodo++;
  }
  else
  {
    PulsosEncoderA--;
    PulsosPorPeriodo--;
  }
}

void setup()
{
  pinMode(GPIO_PONTE_H_1, OUTPUT);
  pinMode(GPIO_PONTE_H_2, OUTPUT);
  pinMode(GPIO_PONTE_H_ENABLE, OUTPUT);

  pinMode(ENCODER_GPIO_A, INPUT_PULLUP);
  pinMode(ENCODER_GPIO_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_GPIO_A),
                  atualizaEncoder, FALLING);
}

void loop()
{
  int valPot = analogRead(POT_GPIO_INPUT);
  int vel = map(valPot, 0, 1023, -255, 255);
  int PWM = min(abs(vel), 255);
  unsigned long tempo = millis();

  if ((tempo - ultimoTempo) >= PERIODO || ultimoTempo == 0)
  {
    ultimoTempo = tempo;
    detachInterrupt(digitalPinToInterrupt(ENCODER_GPIO_A));
    float theta = PulsosEncoderA / PulsosPorPeriodo * 360;
    float omega = (PulsosEncoderA / PULSOS_POR_VOLTA) * (60000 / PERIODO);
    PulsosPorPeriodo = 0;
    attachInterrupt(digitalPinToInterrupt(ENCODER_GPIO_A),
                    atualizaEncoder, FALLING);
  }

  if (vel >= 0)
  {
    digitalWrite(GPIO_PONTE_H_1, LOW);
    digitalWrite(GPIO_PONTE_H_2, HIGH);
  }
  else
  {
    digitalWrite(GPIO_PONTE_H_1, HIGH);
    digitalWrite(GPIO_PONTE_H_2, LOW);
  }
  analogWrite(GPIO_PONTE_H_ENABLE, PWM);
}
