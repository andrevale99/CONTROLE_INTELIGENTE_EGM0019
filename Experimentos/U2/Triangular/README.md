# Valores dos Testes

1. **Ts = 100ms** | max
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)

float paramtersout[6][3] = { { 1., 0.1, 0.0 },
                             { 1.0, 0.1, 0.0 },
                             { 0.004, 0.01, 0.0 },
                             { 0.004, 0.01, 0.0 },
                             { 1.0, 0.1, 0.0 },
                             { 1., 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

2. Ts = 100ms | max

 ```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.4, 0.0, 0.0 },
                             { 0.05, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.06, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 } };  // Parâmetros [p q r]
 ```
 ---

 3. Ts = 50 ms | max
 ``` 
 float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.4, 0.0, 0.0 },
                             { 0.05, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.06, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 } };  // Parâmetros [p q r]
 ```
 ---

 4. Ts = 100 ms | max
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1., 0.0, 0.0 },
                             { 0.5, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.5, 0.0, 0.0 },
                             { 1., 0.0, 0.0 } };  // Parâmetros [p q r]
```
---

5. Ts = 100 ms | min

```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1., 0.0, 0.0 },
                             { 0.5, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.4, 0.0, 0.0 },
                             { 0.5, 0.0, 0.0 },
                             { 1., 0.0, 0.0 } };  // Parâmetros [p q r]
```
---

6. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.5, 0.0, 0.0 },
                             { 1., 0.0, 0.0 },
                             { 0.5, 0.0, 0.0 },
                             { 0.5, 0.0, 0.0 },
                             { 1., 0.0, 0.0 },
                             { 1.5, 0.0, 0.0 } };  // Parâmetros [p q r]
```

---

7. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 5, 0., 0.0 },
                             { 3., 0.0, 0.0 },
                             { 1.5, 0.0, 0.0 },
                             { 1.5, 0.0, 0.0 },
                             { 3., 0.0, 0.0 },
                             { 5, 0., 0.0 } };  // Parâmetros [p q r]
float erro = 0.0, erroAnt = 0.0, varErro = 0.0;   // Cria variáveis p
```

---

8. Ts = 100 ms | max
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 5, 0., 0.0 },
                             { 3., 0.0, 0.0 },
                             { 1.5, 0.0, 0.0 },
                             { 1.5, 0.0, 0.0 },
                             { 3., 0.0, 0.0 },
                             { 5, 0., 0.0 } };  // Parâmetros [p q r]
float erro = 0.0, erroAnt = 0.0, varErro = 0.0;   // Cria variáveis p
```
---

9. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 2, 0., 0.0 },
                             { 1., 0.0, 0.0 },
                             { .5, 0.0, 0.0 },
                             { .5, 0.0, 0.0 },
                             { 1., 0.0, 0.0 },
                             { 2, 0., 0.0 } };  // Parâmetros [p q r]
```
---

10. Ts = 100 ms | min
```
float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1, 0., 0.0 },
                             { .5, 0.0, 0.0 },
                             { .05, 0.0, 0.0 },
                             { .05, 0.0, 0.0 },
                             { .5, 0.0, 0.0 },
                             { 1, 0., 0.0 } };  // Parâmetros [p q r]
```