# Experimentos com PI

1. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .1, 0.01, 0.0 },
                             { 1.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

2. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .1, 0.1, 0.0 },
                             { 1.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

3. Ts = 100 ms | min (**MELHOR DE TODOS**)
```
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

4. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 1., 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .1, 0.1, 0.} };

```
---

5. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .2, 0.1, 0.0 },
                             { 1.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---
6. Ts = 100 ms | min
```
float paramtersIn1[9] = {
  -400.0, -215.0, -30.0,  // Triângulo 1 (Negativo Grande)
  -100.0, 0.0, 100.0,    // Triângulo 2 (Zero)
  30.0, 215.0, 400.0     // Triângulo 3 (Positivo Grande)
};

float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .1, 0.01, 0.0 },
                             { 0.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

7. Ts =  100 ms | max
```
float paramtersIn1[9] = {
  -400.0, -215.0, -30.0,  // Triângulo 1 (Negativo Grande)
  -100.0, 0.0, 100.0,    // Triângulo 2 (Zero)
  30.0, 215.0, 400.0     // Triângulo 3 (Positivo Grande)
};

float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .1, 0.01, 0.0 },
                             { 0.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

8. Ts = 100 ms | min
```
float paramtersIn1[9] = {
  -400.0, -215.0, -30.0,  // Triângulo 1 (Negativo Grande)
  -100.0, 0.0, 100.0,    // Triângulo 2 (Zero)
  30.0, 215.0, 400.0     // Triângulo 3 (Positivo Grande)
};

float paramtersIn2[6] = { -500.0, -245.0, 10.0,
                          -10.0, 245.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .1, 0.01, 0.0 },
                             { 0.0, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---
 9.  Ts = 100 | min
 ```
 float paramtersIn1[9] = {
  -400.0, -215.0, -30.0,  // Triângulo 1 (Negativo Grande)
  -100.0, 0.0, 100.0,    // Triângulo 2 (Zero)
  30.0, 215.0, 400.0     // Triângulo 3 (Positivo Grande)
};

float paramtersIn2[6] = { -500.0, -245.0, 10.0,
                          -10.0, 245.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .5, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { 1, 0.1, 0.0 } };  // Parâmetros [p q r]
 ```
---

10. Ts = 100 ms | min
```
float paramtersIn1[9] = {
  -400.0, -215.0, -30.0,  // Triângulo 1 (Negativo Grande)
  -100.0, 0.0, 100.0,    // Triângulo 2 (Zero)
  30.0, 215.0, 400.0     // Triângulo 3 (Positivo Grande)
};

float paramtersIn2[6] = { -500.0, -245.0, 10.0,
                          -10.0, 245.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0.1, 0.0 },
                             { .5, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.00, 0.0 },
                             { .01, 0.00, 0.0 },
                             { 1, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

12. Ts = 100 ms | min
```
float paramtersIn1[15] = { 
  -400.0, -350.0, -100.0,
  -150.0, -50.0, 0.0, 
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0
};

float paramtersIn2[6] = { -500.0, -245.0, 10.0,
                          -10.0, 245.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[10][3] = { { 1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .1, 0.1, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0},
                             {.1, 0.1, 0.0},
                             {.1, 0.1, 0.0},
                             {1, 0.1, 0.0} };  // Parâmetros [p q r]
```
---

13. Ts = 100 ms | min (**MELHORZINHO**)
```
float paramtersIn1[15] = { 
  -400.0, -350.0, -100.0,
  -150.0, -50.0, 0.0, 
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0
};

float paramtersIn2[6] = { -500.0, -245.0, 10.0,
                          -10.0, 245.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[10][3] = { { 1, 0.1, 0.0 },
                             { .8, 0.1, 0.0 },
                             { .8, 0.1, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .1, 0.01, 0.0 },
                             { .1, 0.01, 0.0},
                             {.8, 0.1, 0.0},
                             {.8, 0.1, 0.0},
                             {1, 0.1, 0.0} };  // Parâmetros [p q r]
```