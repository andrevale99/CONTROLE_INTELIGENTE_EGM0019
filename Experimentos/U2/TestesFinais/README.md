1. Ts = 100 ms | max | Gaussiana 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

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
---

2. Ts = 100 ms | min | Triangular 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { 1.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
--- 

3. Ts = 100 ms | min | Triangular 5 MF's e 2 MF's de variação de erro
```
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
```
---

4. Ts = 100 ms | min | Trapezoidal 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[12] = { -400.0, -100, -50.0, 30.0,
                           -75.0, -10, 10.0, 75.0,
                           -30.0, 50, 100.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[8] = { -500.0, -250, -100.0, 100.0,
                          -100.0, 100.0, 250, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1, 0.01, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.5, 0.0 },
                             { .05, 0.5, 0.0 },
                             { .05, 0.05, 0.0 },
                             { 1.2, 0.4, 0.0 } };  // Parâmetros [p q r]
```
---
5. Ts = 100 ms | min | Trapezoidal 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[12] = { -400.0, -100, -50.0, 30.0,
                           -75.0, -10, 10.0, 75.0,
                           -30.0, 50, 100.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[8] = { -500.0, -250, -100.0, 100.0,
                          -100.0, 100.0, 250, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1, 0.01, 0.0 },
                             { .1, 0.05, 0.0 },
                             { .05, 0.5, 0.0 },
                             { .05, 0.5, 0.0 },
                             { .1, 0.05, 0.0 },
                             { 1.2, 0.4, 0.0 } };  // Parâmetros [p q r]
```
---

6. Ts = 100 ms | min | Trapezoidal 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[12] = { -400.0, -100, -50.0, 30.0,
                           -75.0, -10, 10.0, 75.0,
                           -30.0, 50, 100.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[8] = { -500.0, -250, -100.0, 100.0,
                          -100.0, 100.0, 250, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1, 0.01, 0.0 },
                             { .8, 0.05, 0.0 },
                             { .05, 0.5, 0.0 },
                             { .05, 0.5, 0.0 },
                             { .8, 0.05, 0.0 },
                             { 1.2, 0.4, 0.0 } };  // Parâmetros [p q r]
```
---

7. Ts = 100 ms | min | Trapezoidal 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[12] = { -400.0, -100, -50.0, 30.0,
                           -75.0, -10, 10.0, 75.0,
                           -30.0, 50, 100.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[8] = { -500.0, -250, -100.0, 100.0,
                          -100.0, 100.0, 250, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .8, 0.05, 0.0 },
                             { .5, 0.5, 0.0 },
                             { .5, 0.5, 0.0 },
                             { .8, 0.05, 0.0 },
                             { 1.2, 0.4, 0.0 } };  // Parâmetros [p q r]
```
---

8. Ts = 100 ms | min | Trapezoidal 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[12] = { -400.0, -100, -50.0, 30.0,
                           -75.0, -10, 10.0, 75.0,
                           -30.0, 50, 100.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[8] = { -500.0, -250, -100.0, 100.0,
                          -100.0, 100.0, 250, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .8, 0.5, 0.0 },
                             { .5, 0.5, 0.0 },
                             { .5, 0.5, 00 },
                             { .8, 0.5, 0.0 },
                             { 1.2, 0.4, 0.0 } };  // Parâmetros [p q r]
```
---

9. Ts = 100 ms | max | Trapezoidal 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[12] = { -400.0, -100, -50.0, 30.0,
                           -75.0, -10, 10.0, 75.0,
                           -30.0, 50, 100.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[8] = { -500.0, -250, -100.0, 100.0,
                          -100.0, 100.0, 250, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .8, 0.5, 0.0 },
                             { .5, 0.5, 0.0 },
                             { .5, 0.5, 00 },
                             { .8, 0.5, 0.0 },
                             { 1.2, 0.4, 0.0 } };  // Parâmetros [p q r]
```
--- 

10. Ts = 100 ms | max | Triangular 5 MF's e 2 MF's de variação de erro
```
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
```
---

11. Ts = 100 ms | max | Triangular 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { 1.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

12. Ts = 100 ms | max | Triangular 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.5, 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .05, 0.1, 0.0 },
                             { 0.5, 0.1, 0.0 } };  // Parâmetros [p q r]
```

---

13. Ts = 100 ms | min | Triangular 3 Mf's erro e 2 MF's de variação de erro
```
int16_t RPMteste[5] = {-111, -66, 85, -39, 137};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { 1.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```