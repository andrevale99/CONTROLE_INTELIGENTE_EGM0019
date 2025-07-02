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
---

6. Ts = 100 ms | max
```
int16_t RPMteste[5] = {82, 91, 3, 83, 126};

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
---

7. Ts = 100 ms | max
```
int16_t RPMteste[5] = {78, 19, 87, 101, -94};

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
---

8. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-114, -57, 86, 60, -31};

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
---

9. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-114, -57, 86, 60, -31};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .5, 0.1, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .5, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

10. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-114, -57, 86, 60, -31};

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

11. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-26, -53, -110, 23, -112};

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

12. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-95, 124, -48, -106, 55};

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

13. Ts = 100 ms | max
```
int16_t RPMteste[5] = {91, -109, -47, 124, -105};

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

14. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-30, -40, -50, -60, -70};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

15. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-30, -40, -50, -60, -70};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

16. Ts = 100 ms | max (**MELHORZÃO**)
```
int16_t RPMteste[5] = {91, -109, -47, 124, -105};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.2, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---
17. Ts = 100 ms | max
```
int16_t RPMteste[5] = {-30, -40, -50, -60, -70};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.75, 0.2, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

18. Ts = 100 ms | max
```
int16_t RPMteste[5] = {91, -109, -47, 124, -105};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.5, 0.2, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .25, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```