# Numerical Methods
*1.* [Bisection Method](#Bisection-Method)

*2.* [False Position / Regula Falsi Method](#False-Position-Method)
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
6. IF f(b)*f(c) <> 0 THEN
        a = c
    ELSE
        b = c
7. IF f(c) > tolerance THEN
    GOTO 5
8. Display c
9. Stop
```
