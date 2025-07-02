1. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-44, -127, 115, -131, -74};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

2. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-48, -72, 65, -119, 118};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

3. Ts = 100 ms | min
```
int16_t RPMteste[5] = {117, 60, 94, 135, -53};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

4. Ts = 100 ms | min (**MELHOZINHO**)
```
int16_t RPMteste[5] = {117, 60, 94, 135, -53};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .5, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .5, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

5. Ts = 100 ms | max (**MELHOR DE TODOS**)
```
int16_t RPMteste[5] = {117, 60, 94, 135, -53};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .5, 0.1, 0.0 },
                             { .1, 0.05, 0.0 },
                             { .1, 0.05, 0.0 },
                             { .5, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```