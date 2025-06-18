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

3. Ts = 100 ms | min (MELHOR DE TODOS)
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