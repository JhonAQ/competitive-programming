# Bitwise Tricks

## Determinar la paridadd de un numero

```cpp
int x = 12;
bool esPar(int n){
  return !(n & 1)
}
```

## Verificar si un numero es potencia de 2

```cpp
// x & (x - 1) es 0 si x es una potencia de 2

bool powerOf2(int x){
  return x && !(x & (x - 1));
}
```

## Jugando con el K-esimo bit

Comportamiento de los bitwise operators:

```cpp
& | ^ ~
```

### Verificar si el bit k esta encendido

```cpp
bool isKSet(n, k){
  return n & (1<<k);
}
```

### Cambiar el estado del bit k

```cpp
void toggleBit(n, k){
  n ^= (1<<k)
}
```

### Encender el bit k

```cpp
void setBit(n, k){
  n |= (1<<k)
}
```

### Apagar el bit k

```cpp
void offBit(n, k){
  n &= ~(1<<k)
}
```

## Multiplicar y dividir por 2^k

### Para multiplicar por 2^k

```cpp
int a = 34;
int porDos = a<<1;
int porCuatro = a<<2;
int porOcho = a<<3;
```

### Para dividir por 2^k

```cpp
int b = 5;
int entreDos = b>>2
```

## Como hallar el modulo con 2^k

```cpp
int a = 34;
int moduloOcho = a & ((1<<k) - 1)
```

## Cambiar dos bits sin variable auxiliar

```cpp
int a = 23;
int b = 43;

a ^= b;
b = a^b;
a = a^b;
```

## Regla que se cumple para XOR

> Si el numero de bits encendidos en A = X
> Y el numero de bits encendidos en B = Y
> y el numero de bits encendidos en (A^B) = z
>
> entonces:
>
> Z es par si x + Y es par
> Z es impar si x + y es impar

## Cambiar el valor de un numero dependiendo si es uno u otro

```cpp
// Codigo a reducir:
void cambiar(int a){
  if(a == 10){
    a = 5;
  }
  else if(a == 5){
    a = 10;
  }
}

// Otro ejemplo:
a = (a == 10) ? 5 : 10;

// Con bitwise:

a = 10 ^ 5 ^ a;
```

## Propiedades de suma

```cpp
int a = 10;
int b = 10;

int suma = (a ^ b) + 2(a & b)
int otraForma = (a | b) + (a & b)
```

## Averiguar la cantidad de bits prendidos en un setbit

```cpp
// Solo en c++, con esta función lo sacamos en complejidad O(1)
int x = 0b1001010;
long long x1 = 12312145345345
int bitsOn = __builtin_popcount(x);
int bitsOnLL = __builtin_popcount(x1);
// Te devuelve la cantidad de bits encendidos
```
