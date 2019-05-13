# Numerical Methods
*1.* [Bisection Method](#Bisection-Method)

*2.* [False Position / Regula Falsi Method](#False-Position-Method)

*3.* [Secant Method](#Secant-Method)

*4.* [Newton Raphson Method](#Newton-Raphson-Method)
___
### Algorithms
#### Bisection Method
```
1. Start
2. Read two initial guesses (a, b) and tolerance
3. Compute: f(a), f(b)
4. IF f(a)*f(b) > 0 GOTO 2
5. Determine: c=(a+b)/2
6. IF |(b-a)/c| < tolerance THEN
        display c and GOTO 9
    ELSE
        compute f(c)
7. IF f(c)*f(a) > 0 THEN
        a = c
        f(a) = f(c)
    ELSE
        b = c
        f(b) = f(c)
8. GOTO 5
9. Stop
```

#### False Position Method
```
1. Start
2. Read two initial guesses (a, b) and tolerance
3. Compute: f(a), f(b)
4. IF f(a)*f(b) > 0 GOTO 2
5. Determine: c = a-f(a)*(b-a)/(f(b)-f(a))
6. IF f(b)*f(c) < 0 THEN
        a = c
    ELSE
        b = c
7. IF f(c) > tolerance THEN
    GOTO 5
8. Display c
9. Stop
```

#### Secant Method
```
1. Start
2. Read two initial guesses (a, b) and tolerance
3. Compute: c = b-f(b)*(b-a)/(f(b)-f(a))
4. IF f(b)*f(c) < 0 THEN
        a = c
    ELSE
        b = c
5. IF |(c-b)/c| > tolerance THEN
    GOTO 3
6. Display c
7. Stop
```

#### Newton Raphson Method
```
1. Start
2. Read two initial guess (a) and tolerance
3. Compute: b = a - f(a)/df(a)
4. Compute: error=|(b-a)/b|
5. IF error > tolerance THEN
    a = b
    GOTO 3
6. Display b
7. Stop
```