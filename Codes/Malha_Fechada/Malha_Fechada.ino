#define POT_PIN A0

#define BUTAO_PIN_PWM 9

#define PONTE_H_1 7
#define PONTE_H_2 6
#define PONTE_H_ENABLE 5

#define CANAL_ENCODER_B 4
#define CANAL_ENCODER_A 3

#define PULSOS_POR_VOLTA (float)341.2

#define PERIODO 50  // ms

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

int PWM = 0;

static float controle = 0;

float teste_controle = 0;

volatile long PulsosCanalA = 0;
long QtdPulsosCanalA = 0;
long QtdPulsoPorPeriodo = 0;
volatile long PulsosPorPeriodo = 0;
volatile long long ultimoTempo = 0;
float theta = 0;
float omega = 0;

static float acaoP = 0.;
static float acaoI = 0.;
static float erro = 0.;
static float Kp = 0.5;
static float Ki = 0.02;

unsigned long long TempoInicialCalculo = 0;
unsigned long TempoTotalCalculo = 0;

//=====================================================
//  FUNCS
//=====================================================

void atualizaEncoder(void);
void aciona_motor(float controle, int PWM);

//=====================================================
//  SETUP E LOOP
//=====================================================

void setup() {
  Serial.begin(115200);

  pinMode(PONTE_H_1, OUTPUT);
  pinMode(PONTE_H_1, OUTPUT);
  pinMode(PONTE_H_ENABLE, OUTPUT);

  pinMode(CANAL_ENCODER_A, INPUT_PULLUP);
  pinMode(CANAL_ENCODER_B, INPUT_PULLUP);

  pinMode(BUTAO_PIN_PWM, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A),
                  atualizaEncoder, FALLING);
}

void loop() {

  int sp = map(analogRead(POT_PIN), 0, 1023, -180, 180);
  unsigned long tempo = millis();

  if ((tempo - ultimoTempo) >= PERIODO || ultimoTempo == 0) {
    ultimoTempo = tempo;
    detachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A));

    TempoInicialCalculo = micros();

    QtdPulsosCanalA = PulsosCanalA;
    QtdPulsoPorPeriodo = PulsosPorPeriodo;

    theta = PulsosCanalA / PULSOS_POR_VOLTA * 360;
    omega = (PulsosPorPeriodo / PULSOS_POR_VOLTA) * (60000 / PERIODO);

    erro = sp - omega;
    acaoP = Kp * erro;
    acaoI += Ki * erro * PERIODO / 1000;

    PulsosPorPeriodo = 0;

    TempoTotalCalculo = float(micros() - TempoInicialCalculo);

    attachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A),
                    atualizaEncoder, FALLING);
  }

    controle = acaoP + acaoI;

  if (digitalRead(BUTAO_PIN_PWM) == 0) {
    PWM = min(controle, 255);
    aciona_motor(controle, PWM);
  }


  Serial.print((float)ultimoTempo / 1000, 3);
  Serial.print("\t");
  Serial.print(sp);
  Serial.print("\t");
  // Serial.print(TempoTotalCalculo);
  // Serial.print("\t");
  Serial.print(PWM);
  Serial.print("\t");
  // Serial.print(QtdPulsosCanalA);
  // Serial.print("\t");
  // Serial.print(QtdPulsoPorPeriodo);
  // Serial.print("\t");
  // Serial.print(theta);
  // Serial.print("\t");
  Serial.print(omega);
  Serial.print("\t");
  Serial.print(erro);
  Serial.print("\t");
  Serial.print(acaoP);
  Serial.print("\t");
  Serial.print(acaoI);
  Serial.print("\t");
  Serial.print(controle);

  Serial.print("\n");
}

//=====================================================
//  FUNCS
//=====================================================

void atualizaEncoder(void) {
  if (digitalRead(CANAL_ENCODER_A) == digitalRead(CANAL_ENCODER_B)) {
    PulsosCanalA++;
    PulsosPorPeriodo++;
  } else {
    PulsosCanalA--;
    PulsosPorPeriodo--;
  }
}

void aciona_motor(float controle, int PWM) {
  if (controle >= 0) {
    digitalWrite(PONTE_H_1, LOW);
    digitalWrite(PONTE_H_2, HIGH);
  } else {
    digitalWrite(PONTE_H_1, HIGH);
    digitalWrite(PONTE_H_2, LOW);
  }
  analogWrite(PONTE_H_ENABLE, PWM);
}