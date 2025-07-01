# Experimentos com _Setpoints_ Aleatórios

14. Ts = 100 | min
```
int16_t RPMteste[5] = {-114, 29, -28, 137, -92};

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

15. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-114, 29, -28, 137, -92};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.6, 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .6, 0.1, 0.0 } };  // Parâmetros [p q r]
```
---

16. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-114, 29, -28, 137, -92};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.2, 0.5, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .2, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

17. Ts = 100 ms | min
```
int16_t RPMteste[5] = {133, -122, -140, 135, -133};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.8, 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .2, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

18. Ts = 100 ms | min
```
int16_t RPMteste[5] = {133, -122, -63, 78, -106};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.8, 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .2, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

19. Ts = 100 ms | min
```
int16_t RPMteste[5] = {133, -122, -63, 78, -106};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.8, 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .5, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---
20. Ts = 100 ms | min
```
int16_t RPMteste[5] = {133, -122, -63, 78, -106};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 0.8, 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .6, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

21. Ts = 100 ms | min
```
int16_t RPMteste[5] = {133, -122, -63, 78, -106};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -30.0, 0.0, 30.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1., 0.1, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .6, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

22. Ts = 100 ms | min
```
int16_t RPMteste[5] = {133, -122, -63, 78, -106};

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
                             { .6, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

23. TS = 100 ms | min
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
                             { .6, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

24. Ts = 100 ms | min (**MELHO DE TODOS**)
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