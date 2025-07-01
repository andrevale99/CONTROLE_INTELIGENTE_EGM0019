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
---

25. Ts = 100 ms | min
```
int16_t RPMteste[5] = {80, 88, -111, 106, 72};

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

26. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
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

27. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.1, 0.12, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

28. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.25, 0.12, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

29. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.05, 0.12, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

30. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.05, 0.12, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { 1., 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

31. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
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

32. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[9] = { -400.0, -50.0, 10.0,
                          -60.0, 0.0, 60.0,
                          -10.0, 50.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)
float paramtersIn2[6] = { -500.0, -30.0, 10.0,
                          -10.0, 30.0, 500.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
float paramtersout[6][3] = { { 1.2, 0.1, 0.0 },
                             { .45, 0.1, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .01, 0.01, 0.0 },
                             { .45, 0.05, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

33. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-97, 76, -32, -71, -29};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .75, 0.5, 0.0 },
                             { .75, 0.5, 0.0 },
                             { .75, 0.5, 0.0 },
                             { .75, 0.5, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
```
---

 34. Ts = 100 ms | min
 ```
int16_t RPMteste[5] = {-18, -137, 136, -110, -49};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .75, 0.1, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
 ```
 ---
 35. Ts = 100 ms | min
 ```
int16_t RPMteste[5] = {-18, -137, 136, -110, -49};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .75, 0.05, 0.0 },
                             { .75, 0.5, 0.0 } };  // Parâmetros [p q r]
 ```
 ---
 
 36. Ts = 100 ms | min
 ```
int16_t RPMteste[5] = {-18, -137, 136, -110, -49};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .15, 0.15, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .05, 0.1, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .75, 0.1, 0.0 },
                             { 1.2, 0.2, 0.0 } };  // Parâmetros [p q r]
 ```
 ---

 37. Ts = 100 ms | min
 ```
 int16_t RPMteste[5] = {-58, -137, 136, -110, -49};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .15, 0.15, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .55, 0.1, 0.0 },
                             { 1.2, 0.2, 0.0 } };  // Parâmetros [p q r]
```
---

38. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-58, -137, 136, -110, -49};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .55, 0.01, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .55, 0.1, 0.0 },
                             { 1.2, 0.2, 0.0 } };  // Parâmetros [p q r]
```
---
39. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-58, -137, 136, -110, -49};

float paramtersIn1[15] = {-400.0, -350.0, -100.0, 
-150.0, -50.0, 0.0,
  -50.0, 0.0, 50.0,
  0.0, 50.0, 150.0,
  100.0, 350.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 1 (erro)

float paramtersIn2[6] = { -400.04 -30.0, 10.0,
                          -10.0, 30.0, 400.0 };  // Parâmetros [a b c] das MFs da entrada 2 (variação do erro)
                        
float paramtersout[10][3] = { { 1.2, 0.2, 0.0 },
                             { .25, 0.01, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .05, 0.05, 0.0 },
                             { .01, 0.1, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .01, 0.05, 0.0 },
                             { .55, 0.1, 0.0 },
                             { 1.2, 0.2, 0.0 } };  // Parâmetros [p q r]
```
---

40. Ts = 100 ms | min
```
int16_t RPMteste[5] = {-58, -137, 136, -110, -49};

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