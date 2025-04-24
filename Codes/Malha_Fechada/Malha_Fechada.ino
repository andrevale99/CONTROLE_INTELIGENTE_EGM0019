#define POT_PIN A0

#define PONTE_H_1 7
#define PONTE_H_2 6
#define PONTE_H_ENABLE 5

#define CANAL_ENCODER_B 4
#define CANAL_ENCODER_A 3

#define PULSOS_POR_VOLTA (float)341.2

#define PERIODO 100 // ms

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

volatile long PulsosCanalA = 0;
long QtdPulsosCanalA = 0;
long QtdPulsoPorPeriodo = 0;
volatile long PulsosPorPeriodo = 0;
volatile long long ultimoTempo = 0;
float theta = 0;
float omega = 0;

unsigned long long TempoInicialCalculo = 0;
unsigned long TempoTotalCalculo = 0;

//=====================================================
//  FUNCS
//=====================================================

void atualizaEncoder(void);

//=====================================================
//  SETUP E LOOP
//=====================================================

void setup()
{
  Serial.begin(115200);

  pinMode(PONTE_H_1, OUTPUT);
  pinMode(PONTE_H_1, OUTPUT);
  pinMode(PONTE_H_ENABLE, OUTPUT);

  pinMode(CANAL_ENCODER_A, INPUT_PULLUP);
  pinMode(CANAL_ENCODER_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A),
                  atualizaEncoder, FALLING);
}

void loop()
{
  static float erro = 0.;
  static float Kp = 0.2;
  static float Ki = 0.005;
  static float acaoP = 0.;
  static float acaoI = 0.;
  static float controle = acaoP + acaoI;

  int sp = map(analogRead(POT_PIN), 0, 1023, -160, 160);
  unsigned long tempo = millis();

  if ((tempo - ultimoTempo) >= PERIODO || ultimoTempo == 0)
  {
    ultimoTempo = tempo;
    detachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A));

    TempoInicialCalculo = micros();

    QtdPulsosCanalA = PulsosCanalA;
    QtdPulsoPorPeriodo = PulsosPorPeriodo;

    theta = PulsosCanalA / PULSOS_POR_VOLTA * 360;
    omega = (PulsosPorPeriodo / PULSOS_POR_VOLTA) * (60000 / PERIODO);

    erro = sp - omega;
    acaoP = Kp * erro;
    acaoI += Ki * erro * PERIODO;

    PulsosPorPeriodo = 0;

    TempoTotalCalculo = float(micros() - TempoInicialCalculo);

    attachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A),
                    atualizaEncoder, FALLING);
  }

  controle = acaoP + acaoI;
  int PWM = min(abs(controle), 255);

  if (vel >= 0)
  {
    digitalWrite(PONTE_H_1, LOW);
    digitalWrite(PONTE_H_2, HIGH);
  }
  else
  {
    digitalWrite(PONTE_H_1, HIGH);
    digitalWrite(PONTE_H_2, LOW);
  }
  analogWrite(PONTE_H_ENABLE, PWM);

  Serial.print((float)ultimoTempo / 1000, 3);
  Serial.print("\t");
  Serial.print(TempoTotalCalculo);
  Serial.print("\t");
  Serial.print(valPot);
  Serial.print("\t");
  Serial.print(vel);
  Serial.print("\t");
  Serial.print(PWM);
  Serial.print("\t");
  Serial.print(QtdPulsosCanalA);
  Serial.print("\t");
  Serial.print(QtdPulsoPorPeriodo);
  Serial.print("\t");
  Serial.print(theta);
  Serial.print("\t");
  Serial.println(omega);
  Serial.print("\t");
  Serial.println(erro);
  Serial.print("\t");
  Serial.println(acaoP);
  Serial.print("\t");
  Serial.println(acaoI);
  Serial.print("\t");
  Serial.println(controle);
}

//=====================================================
//  FUNCS
//=====================================================

void atualizaEncoder(void)
{
  if (digitalRead(CANAL_ENCODER_A) == digitalRead(CANAL_ENCODER_B))
  {
    PulsosCanalA++;
    PulsosPorPeriodo++;
  }
  else
  {
    PulsosCanalA--;
    PulsosPorPeriodo--;
  }
}
