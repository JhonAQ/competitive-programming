# Bitmask
Muy usadas para representar conjuntos, union, interseccion, cardinalidad, recorres elementos, etc.

## Consideraciones
- El operador `^` es como hacer una suma y modulo bit a bit

## Trucos

> Saber si un numero es par o no
```cpp
if(x&1) cout << "impar";
else cout << "par";
```

> Elevar 2 a la n
```cpp
int dosCubo = 1 << 3;
int dosPotencia = 1 << n;
```

> Multiplicar por 2 un numero
```cpp
int multi = x << k; //es igual a hacer x * (2 ^ k)
```

> Extraer el kesimo bit
```cpp
int x = 0b10010010;
int kesimo = x & (1 << k);

```
> Establecer el kesimo bit de x en 1
```cpp
x |= (1 << k)
```

> Establecer el kesimo bit de x en cero
```cpp
x &= ~(1 << k)
```

> Invertir el kesimo bit de x
```cpp
x ^= (1 << k)
```

> Prueba de divisibilidad por 2^k
```cpp
x & ((1 << k) - 1) == 0
```

> Cambiar el ultimo bit encendido a 0
```cpp
x &= (x - 1)
```

> Invierte todos los bits despues del ultimo bit 1
```cpp
x |= (x - 1)
```

> Se obtiene el bit activo menos significatibo
```cpp
int menSig = x & -x // 1010 & 0101
```

## Funciones utiles de g++
Se compilan en codigo maquina altamente optimizado y se implementan utilizando instrucciones de procesaro especificas de la arquitectura, lo que permite que sean extremadamente rapidas.

- `__builtin_clz(x)` -> La cantidad de '0's al principio del numero
- `__builtin_ctz(x)` -> La cantidad de '0's al final de un numero
- `__builtin_popcount(x)` -> La cantidad de '1's en el numero
- `__builtin_parity(x)` -> La paridad de la cantidad de '1's
