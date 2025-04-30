#define POT_PIN A0

#define BUTAO_PIN_PWM 9

#define PONTE_H_1 7  // 7
#define PONTE_H_2 6
#define PONTE_H_ENABLE 5  // 5

#define CANAL_ENCODER_B 4
#define CANAL_ENCODER_A 3

#define PULSOS_POR_VOLTA (float)341.2

#define PI 3.1415

#define PERIODO 100  // ms

#define RPM_MAX_LIMIT 160

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
static float acaoD = 0.;
static float erro = 0.;
static float erro_anterior = 0.;
static float Kp = 0.8;
static float Ki = 0.0;
static float Kd = 0.0;

unsigned long long TempoInicialCalculo = 0;
unsigned long TempoTotalCalculo = 0;

int sp = 0;

//=====================================================
//  FUNCS
//=====================================================

void atualizaEncoder(void);
void aciona_motor(float controle, int PWM);
void show_data(void);

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
                  atualizaEncoder, CHANGE);
}

void loop() {

  sp = map(analogRead(POT_PIN), 0, 1023, -RPM_MAX_LIMIT, RPM_MAX_LIMIT);
  unsigned long tempo = millis();

  if ((tempo - ultimoTempo) >= PERIODO || ultimoTempo == 0) {
    ultimoTempo = tempo;
    detachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A));

    TempoInicialCalculo = micros();

    QtdPulsosCanalA = PulsosCanalA;
    QtdPulsoPorPeriodo = PulsosPorPeriodo;

    theta = PulsosCanalA / PULSOS_POR_VOLTA * 360.f;
    //theta = PulsosPorPeriodo * 2 * PI / PULSOS_POR_VOLTA;
    omega = (PulsosPorPeriodo / PULSOS_POR_VOLTA) * (60000 / PERIODO);
    //omega = theta / (PERIODO / 1000.0f) * (60 / (2 * PI));

    erro = sp - omega;
    acaoP = Kp * erro;
    acaoI += Ki * erro * (float)PERIODO;
    acaoD = Kd * (erro - erro_anterior) / ((float)PERIODO / 1000.0);

    PulsosPorPeriodo = 0;

    erro_anterior = erro;

    TempoTotalCalculo = float(micros() - TempoInicialCalculo);


    attachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A),
                    atualizaEncoder, FALLING);
    show_data();
  }

  // anti-windup (para nao ficar
  // incrementando a integração infinitamente)
  if (acaoI > RPM_MAX_LIMIT)
    acaoI = RPM_MAX_LIMIT;
  if (acaoI < -RPM_MAX_LIMIT)
    acaoI = -RPM_MAX_LIMIT;


  controle = acaoP + acaoI + acaoD;

  // anti-windup (para nao ficar
  // incrementando a integração infinitamente)
  //if (controle > 255)
  //controle = 255;
  //if (controle < -255)
  //controle = -255;
  
  // if (digitalRead(BUTAO_PIN_PWM) == 0) {
    PWM = min(abs(controle), 255);
    aciona_motor(controle, PWM);
  // }
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
    digitalWrite(PONTE_H_1, HIGH);
    digitalWrite(PONTE_H_2, LOW);
  } else {
    digitalWrite(PONTE_H_1, LOW);
    digitalWrite(PONTE_H_2, HIGH);
  }
  analogWrite(PONTE_H_ENABLE, PWM);
}

void show_data(void) {
  //Serial.print("tempo:");
  Serial.print((float)ultimoTempo / 1000, 3);
  Serial.print("\t");
  Serial.print(TempoTotalCalculo);
  Serial.print("\t");
  // Serial.print("setpoint:");
  Serial.print(sp);
  Serial.print("\t");
  // Serial.print("PWM:");
  Serial.print(PWM);
  Serial.print("\t");
  Serial.print(QtdPulsosCanalA);
  Serial.print("\t");
  // Serial.print("pulsos periodo:");
  Serial.print(QtdPulsoPorPeriodo);
  Serial.print("\t");
  Serial.print(theta);
  Serial.print("\t");
  // Serial.print("velocidade rpm:");
  Serial.print(omega);
  Serial.print("\t");
  // Serial.print("erro:");
  Serial.print(erro, 2);
  Serial.print("\t");
  // Serial.print("acao p:");
  Serial.print(acaoP, 3);
  Serial.print("\t");
  // Serial.print("acao i:");
  Serial.print(acaoI, 3);
  Serial.print("\t");
  Serial.print(acaoD, 3);
  Serial.print("\t");
  // Serial.print("controle:");
  Serial.print(controle, 2);

  Serial.print("\n");
}
