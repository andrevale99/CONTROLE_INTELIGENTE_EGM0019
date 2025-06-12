# Valores dos Testes

1. **Ts = 100ms**
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