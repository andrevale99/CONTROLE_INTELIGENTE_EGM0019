/*  ---------------------------------------------
  Controle de Motor DC - Código 004
  -----------------------------------------------
  Motor Controlado por Arduino
  Malha Fechada para o Controle Fuzyy-PI
  da velocidade angular

  Material usando:
  1. 01x Palca Arduino MEGA2560
  2. 01x Protoboard Grande (830 pontos)
  3. 01x Fonte externa (12V 1A
  4. 01x Módulo Ponte H L298N
  5. 01x Motor DC 6v com Encoder
  6. 01x Regulador de tensão L7806 (6v/1A)
  7. 01x Capacitor Eletrolítico 10uF/25v
  8. 01x Capacitor cerâmico 100nF (104)
  9. 01x Potenciometro Rotativo Linear 10K
  10.Alguns Jumpers (15x M-M) e (03x M-F)

  -----------------------------------------------
  Criado por: Fábio Meneghetti Ugulino de Araújo
  Em: Abril de 2023
  -----------------------------------------------*/

#define BUTAO_PIN_PWM 8
#define MAX_RPM 140

unsigned long TempoCalc = 0;
const byte potPin = A0;                         // Usar pino analógico A0 para leitura do Potenciômetro
const byte in1PtHPin = 7;                       // Usar pino digital 7  p/ entrada 1 da Ponte H
const byte in2PtHPin = 6;                       // Usar pino digital 6 p/ entrada 2 da Ponte H
const byte enablePtHPin = 5;                    // Usar pino digital 12 para habilitar a Ponte H
const byte canalBPin = 4;                       // Usar pino digital 4 p/ Canal B do Encoder
const byte canalAPin = 3;                       // Usar pino digital 3 (c/Interrupção) p/ Canal A do Encoder
volatile bool estadoEnablePtH = 1;              // Variável usada para habilitar a Ponte H
const float pulsosPorVolta = 341.2;             // Número de Pulso que o encoder dá em uma volta (resolução)
const int periodo = 100;                        // Periodo de tempo entre medições (em milissegundos)
volatile long pulsosCanalA = 0;                 // Contador de pulsos TOTAIS do Canal A do Encoder
volatile long pulsosPorPeriodo = 0;             // Contador de pulsos POR PERÍODO do Canal A do Encoder
volatile static unsigned long ultimoTempo = 0;  // Variável usada para testar se o período foi atingido


// Valores para reazliar os testes
uint8_t idxRPMteste = 0;
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .02, 0.05, 0.0 },
                             { .02, 0.05, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .55, 0.1, 0.0 },
                             { 1.2, 0.2, 0.0 } };  // Parâmetros [p q r]
float erro = 0.0, erroAnt = 0.0, varErro = 0.0;   // Cria variáveis para: Erro, Erro Anterior e sua Variação
float miIn1[5], miIn2[2];                         // Cria variáveis para armazenar o resultado da fuzzificação
float mi[2][5];                                   // Cria variável para armazenar a compatibilidade global das regras
float outl[2][5];                                 // Cria variável para armazenar a saída (consequente) de cada regra
float outf;                                       // Cria variável para armazenar a saída do controlador fuzzy
float controle = 0.0;                             // Cria variável para armazenar o Sinal de Controle
int numMFsIn1 = 5;                                // Número de funções de pertinência da entrada 1
int numMFsIn2 = 2;                                // Número de funções de pertinência da entrada 2
int PWM = 0;                                      // Cria variável para armazenar o Sinal PWM de acion. do Controle
int sp = 0;

void setup() {
  Serial.begin(9600);                // initializa a comunicação com Monitor serial
  pinMode(in1PtHPin, OUTPUT);        // Configura o pino da entrada 1 da Ponte H como Saída
  pinMode(in2PtHPin, OUTPUT);        // Configura o pino da entrada 2 da Ponte H como Saída
  pinMode(enablePtHPin, OUTPUT);     // Configura o pino que habilita a Ponte H como Saída
  pinMode(canalAPin, INPUT_PULLUP);  // Configura o pino do Canal A do Encoder como entrada c/ Pullup
  pinMode(canalBPin, INPUT_PULLUP);  // Configura o pino do Canal B do Encoder como entrada c/ Pullup
  pinMode(BUTAO_PIN_PWM, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(canalAPin), atualizaEncoderA, FALLING);  // Ativa interrup CanalA
}

void loop() {
  // if (digitalRead(BUTAO_PIN_PWM) == 0)
  //   sp = map(analogRead(potPin), 0, 1023, -MAX_RPM, MAX_RPM);  // Converte leitura do pot. em setpoint, -160 à 160RPM

  unsigned long tempo = millis();  // Atualiza a variável tempo

  if (tempo < 10000)
    sp = RPMteste[0];

  else if (tempo >= 10000 && tempo < 20000)
    sp = RPMteste[1];

  else if (tempo >= 20000 && tempo < 30000)
    sp = RPMteste[2];

  else if (tempo >= 30000 && tempo < 40000)
    sp = RPMteste[3];

  else if (tempo >= 40000 && tempo < 50000)
    sp = RPMteste[4];

  else 
    sp = 0;

  if (tempo - ultimoTempo >= periodo || ultimoTempo == 0) {                   // SE já se passou pelo menos um "período"
    ultimoTempo = tempo;                                                      // ENTÃO: atualiza a variável "ultimoTempo"
    detachInterrupt(digitalPinToInterrupt(canalAPin));                        // para evitar interferências
    TempoCalc = micros();
    float theta = pulsosCanalA / pulsosPorVolta * 360;                        // Calcula a posição angular (Theta) em graus
    float omega = ((pulsosPorPeriodo / pulsosPorVolta) * (60000 / periodo));  // Calcula a velocidade angular
    erro = sp - omega;                                                        // Calcula o erro entre o SP e a PV
    varErro = erro - erroAnt;                                                 // Calcula a variação do erro
    // ETAPA DE FUZZYFICAÇÃO DAS ENTRADAS
    // Realiza a fuzzyficação da variável "erro", entrada 1 do Fuzzy-PI
    for (int MFsIN1 = 0; MFsIN1 < numMFsIn1; MFsIN1++) {
      miIn1[MFsIN1] = triangular(paramtersIn1[3 * MFsIN1], paramtersIn1[3 * MFsIN1 + 1], paramtersIn1[3 * MFsIN1 + 2], erro);
    }
    // Raliza a fuzzyficação da variável "erro", entrada 1 do Fuzzy-PI
    for (int MFsIN2 = 0; MFsIN2 < numMFsIn2; MFsIN2++) {
      miIn2[MFsIN2] = triangular(paramtersIn2[3 * MFsIN2], paramtersIn2[3 * MFsIN2 + 1], paramtersIn2[3 * MFsIN2 + 2], varErro);
    }
    // ETAPA DE INFERÊNCIA
    int contOut = 0;
    float somaMiOut = 0.0, somaMi = 0.0;
    for (int MFsIN2 = 0; MFsIN2 < numMFsIn2; MFsIN2++) {
      for (int MFsIN1 = 0; MFsIN1 < numMFsIn1; MFsIN1++) {
        // Calculo da T-Norma de Zadeh para o operador "E" das regras
        mi[MFsIN2][MFsIN1] = max(miIn1[MFsIN1], miIn2[MFsIN2]);
        // Calculo do Consequnte de cada regra, usando funções Sugeno lineares
        outl[MFsIN2][MFsIN1] = paramtersout[contOut][0] * erro + paramtersout[contOut][1] * varErro + paramtersout[contOut][2];
        contOut++;
        // Somatório do consequente ponderado pelo seu grau de compatibilidade geral de cada regra
        somaMiOut += mi[MFsIN2][MFsIN1] * outl[MFsIN2][MFsIN1];
        // Somatório do grau de compatibilidade geral de cada regra
        somaMi += mi[MFsIN2][MFsIN1];
      }
    }
    // Final da etapa de inferência: Média ponderada dos consequentes ponderados pelas compatibilidades gerais de todas as regras
    outf = somaMiOut / somaMi;  // Calcula a saída do fuzzy (Média ponderada das saídas das regras)
    erroAnt = erro;             // Atualiza o erro anterior
    pulsosPorPeriodo = 0;       // Reinicializa o número de pulsos por período
    if (!isnan(outf)) {
      controle += outf;
    }
    if (controle > 255)
      controle = 255;

    if (controle < -255)
      controle = -255;
    // Calcula o Sinal de Controle (a partir da saída do fuzzy)
    TempoCalc = micros() - TempoCalc;
    attachInterrupt(digitalPinToInterrupt(canalAPin), atualizaEncoderA, FALLING);  // Reabilita interrupção
    mostraDadosMotor(3, theta, omega, sp, erro, varErro, outf, controle, PWM);     // Chama função para exibição dos dados calculados
  }
  PWM = min(abs(controle), 255);  // Calcula o PWM entre 0 e 255, saturando o controle
  acionaMotor(controle, PWM);     // Chama função que aciona o Motor

}  // Fim da VOID LOOP

float triangular(float a, float b, float c, float x) {  // Função Matemática Triangular
  float mi = 0;                                         // Define mi = 0
  if (x >= a && x < b) {                                // SE x estiver entre a e b
    mi = (x - a) / (b - a);
  }                          // Usa a eq da reta de subida
  if (x >= b && x <= c) {    // SE x estiver entre b e c
    mi = (c - x) / (c - b);  // Usa a eq da reta de descida
  }                          // SENÃO, mantem o valor 0
  return mi;                 // Retorna o valor calculado
}

void acionaMotor(float controle, int PWM) {  // Função que comanda a Ponte H, p/ acionar o Motor
  if (controle >= 0) {                       // SE o controle for maior ou igual a 0
    digitalWrite(in1PtHPin, LOW);            // ENTÃO envia um nivel ALTO para a entrada 1,
    digitalWrite(in2PtHPin, HIGH);           // Envia um nivel BAIXO para a entrada 2,
  } else {                                   // SENÃO (variável controle < 0)
    digitalWrite(in1PtHPin, HIGH);           // ENTÃO envia um nivel BAIXO para a entrada 1,
    digitalWrite(in2PtHPin, LOW);            // Envia um nivel ALTO para a entrada 2,
  }                                          // Seja qual for o sentido de rotação,
  analogWrite(enablePtHPin, PWM);            // Envia o valor de PWM para o enable da Ponte H
}

void atualizaEncoderA() {                                  // ISR para contar os pulsos do encoder(Canal A)
  if (digitalRead(canalAPin) == digitalRead(canalBPin)) {  // SE os estados forem iguais
    pulsosCanalA++;                                        // Incrementa o contador de pulsos total do encoder
    pulsosPorPeriodo++;
  }                  // Incrementa o contador de pulsos por periodo
  else {             // SENÃO (estados diferentes)
    pulsosCanalA--;  // Decrementa o contador de pulsos total do encoder
    pulsosPorPeriodo--;
  }  // Decrementa o contador de pulsos por periodo
}

void mostraDadosMotor(int op, float theta, float omega, int sp, float erro, float varErro, float outf, float controle, int PWM) {  // Função para apresentação de informaçcões sobre o Motor
  switch (op) {                                                                                                                    // Verifica a opção escolhida
    case 1:                                                                                                                        // Se foi escolhida a opção 1,
      Serial.print("Tempo: ");                                                                                                     // Imprime mensagem no Monitor Serial
      Serial.print((float)ultimoTempo / 1000);                                                                                     // Imprime valor de ultimoTempo
      Serial.print("s");                                                                                                           // Imprime a unidade: Milisegundos
      Serial.print("\t");                                                                                                          // Imprime uma tabulação
      Serial.print("Posicao angular do Motor: ");                                                                                  // Imprime mensagem ...
      Serial.print(theta);                                                                                                         // Imprime valor de Theta
      Serial.print(" Graus");                                                                                                      // Imprime a unidade: Graus
      Serial.print("\t");                                                                                                          // Imprime uma tabulação
      Serial.print("Velocidade angular do Motor: ");                                                                               // Imprime mensagem ...
      Serial.print(omega, 0);                                                                                                      // Imprime valor de Omega
      Serial.println(" RPM");                                                                                                      // Imprime a unidade: RPM
      break;
    case 2:                   // Se foi escolhida a opção 2,
      Serial.print(sp);       // Imprime o SP
      Serial.print("\t");     // Imprime uma tabulação
      Serial.println(theta);  // Imprime apenas o valor de Theta
      break;
    case 3:                                     // Se foi escolhida a opção 3,
      Serial.print((float)ultimoTempo / 1000);  // Imprime valor de ultimoTempo
      Serial.print("\t");                       // Imprime uma tabulação
      Serial.print(sp);                         // Imprime o SP
      Serial.print("\t");                       // Imprime uma tabulação
      Serial.print(erro);                       // Imprime o erro
      Serial.print("\t");
      Serial.print(controle);  // Imprime o sinal de controle
      Serial.print("\t");
      Serial.print(omega, 4);  // Imprimeapenas  valor de Omega
      Serial.print("\t");
      Serial.println(TempoCalc);
      break;
    case 4:                                     // Se foi escolhida a opção 4,
      Serial.print("Tempo: ");                  // Imprime mensagem ...
      Serial.print((float)ultimoTempo / 1000);  // Imprime valor de ultimoTempo
      Serial.print("s");                        // Imprime a unidade: Milisegundos
      Serial.print("\t");                       // Imprime uma tabulação
      Serial.print("Setpoint: ");               // Imprime mensagem ...
      Serial.print(sp);                         // Imprime o SP
      Serial.print(" Graus");                   // Imprime a unidade: Graus
      Serial.print("\t");                       // Imprime uma tabulação
      //    Serial.print("\t");                               // Imprime uma tabulação
      Serial.print("Pos.: ");  // Imprime mensagem no Monitor Serial
      Serial.print(theta);     // Imprime valor de Theta no Monitor Serial
      Serial.print(" Graus");  // Imprime a unidade: Graus
      Serial.print("\t");      // Imprime uma tabulação
      //    Serial.print("\t");                               // Imprime uma tabulação
      Serial.print("erro: ");    // Imprime mensagem ...
      Serial.print(erro);        // Imprime o erro
      Serial.println(" Graus");  // Imprime a unidade: Graus
      break;
    case 5:                                        // Se foi escolhida a opção 5,
      Serial.print("Tempo: ");                     // Imprime mensagem ...
      Serial.print((float)ultimoTempo / 1000, 2);  // Imprime valor de ultimoTempo
      Serial.print("s");                           // Imprime a unidade: Milisegundos
      Serial.print("\t");                          // Imprime uma tabulação
      Serial.print("Setpoint: ");                  // Imprime mensagem ...
      Serial.print(sp);                            // Imprime o SP
      Serial.print(" RPM");                        // Imprime a unidade: RPM
      Serial.print("\t");                          // Imprime uma tabulação
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("Vel.: ");  // Imprime mensagem ...
      Serial.print(omega, 0);  // Imprime valor de Omega
      Serial.print(" RPM");    // Imprime a unidade: RPM
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");      // Imprime uma tabulação
      Serial.print("erro: ");  // Imprime mensagem ...
      Serial.print(erro);      // Imprime o erro
      Serial.print(" RPM");    // Imprime a unidade: RPM
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");          // Imprime uma tabulação
      Serial.print("Controle: ");  // Imprime mensagem ...
      Serial.println(controle);    // Imprime o sinal de controle
      break;
    case 6:                                        // Se foi escolhida a opção 6,
      Serial.print("Tempo: ");                     // Imprime mensagem ...
      Serial.print((float)ultimoTempo / 1000, 2);  // Imprime valor de ultimoTempo
      Serial.print("s");                           // Imprime a unidade: Milisegundos
      Serial.print("\t");                          // Imprime uma tabulação
      Serial.print("Setpoint: ");                  // Imprime mensagem ...
      Serial.print(sp);                            // Imprime o SP
      Serial.print(" RPM");                        // Imprime a unidade: RPM
      Serial.print("\t");                          // Imprime uma tabulação
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("Vel.: ");  // Imprime mensagem ...
      Serial.print(omega, 0);  // Imprime valor de Omega
      Serial.print(" RPM");    // Imprime a unidade: RPM
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");      // Imprime uma tabulação
      Serial.print("erro: ");  // Imprime mensagem ...
      Serial.print(erro, 1);   // Imprime o erro
      Serial.print(" RPM");    // Imprime a unidade: RPM
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");          // Imprime uma tabulação
      Serial.print("Variação: ");  // Imprime mensagem ...
      Serial.print(varErro, 1);    // Imprime o erro
      Serial.print(" RPM");        // Imprime a unidade: RPM
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");           // Imprime uma tabulação
      Serial.print("Out Fuzzy: ");  // Imprime mensagem ...
      Serial.print(outf, 2);        // Imprime o sinal de controle
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");          // Imprime uma tabulação
      Serial.print("Controle: ");  // Imprime mensagem ...
      Serial.print(controle);      // Imprime o sinal de controle
      //    Serial.print("\t");                                 // Imprime uma tabulação
      Serial.print("\t");     // Imprime uma tabulação
      Serial.print("PWM: ");  // Imprime mensagem ...
      Serial.println(PWM);    // Imprime o sinal de controle
      break;
    case 7:                     // Se foi escolhida a opção 7,
      Serial.print(sp);         // Imprime o SP
      Serial.print("\t");       // Imprime uma tabulação
      Serial.print(omega, 0);   // Imprime valor de Omega
      Serial.print("\t");       // Imprime uma tabulação
      Serial.println(erro, 1);  // Imprime o erro
      break;
    case 8:                       // Se foi escolhida a opção 8,
      Serial.print(outf, 2);      // Imprime a saída do fuzzy
      Serial.print("\t");         // Imprime uma tabulação
      Serial.print(controle, 2);  // Imprime o sinal de controle
      Serial.print("\t");         // Imprime uma tabulação
      Serial.println(PWM);        // Imprime o valor do PWM
      break;
  }
}
