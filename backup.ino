#define POT_PIN A0

#define BUTAO_PIN_PWM 9

#define PONTE_H_1 5  // 7
#define PONTE_H_2 6
#define PONTE_H_ENABLE 55  // 5

#define CANAL_ENCODER_B 4
#define CANAL_ENCODER_A 3

#define PULSOS_POR_VOLTA (float)2091

#define PERIODO 50  // ms

//=====================================================
//  VARIAVEIS GLOBAIS
//=====================================================

struct controle_t {
  float erro;
  float Kp;
  float Ki;

  float controle;
} controlador;

struct motor_t {
  volatile long PulsosCanalA = 0;
  long QtdPulsosCanalA = 0;

  long QtdPulsoPorPeriodo = 0;
  volatile long PulsosPorPeriodo = 0;

  float theta = 0;
  float omega = 0;
} motor;

int PWM = 0;

static float acaoP = 0.;
static float acaoI = 0.;

volatile long long ultimoTempo = 0;

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

  // Iniciando as variaveis do controlador
  controlador.erro = 0;
  controlador.Ki = 0.02;
  controlador.Kp = 0.5;

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

  sp = map(analogRead(POT_PIN), 0, 1023, -160, 160);
  unsigned long tempo = millis();

  if ((tempo - ultimoTempo) >= PERIODO || ultimoTempo == 0) {
    ultimoTempo = tempo;
    detachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A));

    TempoInicialCalculo = micros();

    QtdPulsosCanalA = PulsosCanalA;
    QtdPulsoPorPeriodo = PulsosPorPeriodo;

    motor.theta = motor.PulsosCanalA / PULSOS_POR_VOLTA * 360.f;
    motor.omega = (motor.PulsosPorPeriodo / PULSOS_POR_VOLTA) * (60000 / PERIODO);

    controlador.erro = sp - motor.omega;
    acaoP = controlador.Kp * controlador.erro;
    acaoI += controlador.Ki * controlador.erro * (float)PERIODO / 1000.;

    motor.PulsosPorPeriodo = 0;

    TempoTotalCalculo = float(micros() - TempoInicialCalculo);

    show_data();

    attachInterrupt(digitalPinToInterrupt(CANAL_ENCODER_A),
                    atualizaEncoder, FALLING);
  }

  controle = acaoP + acaoI;

  PWM = min(abs(controle), 160);
  aciona_motor(controle, PWM);
}

//=====================================================
//  FUNCS
//=====================================================

void atualizaEncoder(void) {
  if (digitalRead(CANAL_ENCODER_A) == digitalRead(CANAL_ENCODER_B)) {
    motor.PulsosCanalA++;
    motor.PulsosPorPeriodo++;
  } else {
    motor.PulsosCanalA--;
    motor.PulsosPorPeriodo--;
  }
}

void aciona_motor(float controle, int PWM) {
  if (controle >= 0) {
    digitalWrite(PONTE_H_1, LOW);
    analogWrite(PONTE_H_2, PWM);
  } else {
    analogWrite(PONTE_H_1, PWM);
    digitalWrite(PONTE_H_2, LOW);
  }
  // analogWrite(PONTE_H_ENABLE, PWM);
}

void show_data(void) {
  Serial.print((float)ultimoTempo / 1000, 3);
  Serial.print("\t");
  Serial.print(sp);
  Serial.print("\t");
  // Serial.print(TempoTotalCalculo);
  // Serial.print("\t");
  // Serial.print(PWM);
  // Serial.print("\t");
  // Serial.print(QtdPulsosCanalA);
  // Serial.print("\t");
  Serial.print(motor.QtdPulsoPorPeriodo);
  Serial.print("\t");
  // Serial.print(theta);
  // Serial.print("\t");
  Serial.print(motor.omega);
  Serial.print("\t");
  Serial.print(controlador.erro);
  Serial.print("\t");
  Serial.print(acaoP);
  Serial.print("\t");
  Serial.print(acaoI, 4);
  Serial.print("\t");
  Serial.print(controle);

  Serial.print("\n");
}