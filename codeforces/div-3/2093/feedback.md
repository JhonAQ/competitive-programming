# Retroalimentacion de problemas - div 3

## A - Ideal Generator
- Greedy

Basicamente, si el generador es un numero par, siempre se podra escribir de la forma {1, 1, 1, 1, ... , 1, 1}, pero si el generador es impar, los palimdromos tendran que ser: {1, 1, ... m/2, m/2, ... 1, 1}, haciendo que la suma sea: 2 \* (1, 1, 1, m/2), por lo cual no alcanzará para hacer los impares

## B - Epensive Number
- Greedy

1. Probar que el costo minimo posible es 1

- Representar el numero y descomponer polinomicamente para darnos cuenta que siempre se cumple

2. Siempre podemos dejar todos los digitos menos uno, (y tantos 0 a la izquierda posibles)
3. Code

- ¿Habra alguna forma de quitar pocos numeros y el costo sea menos que 1?
  - Nunca la suma de los digitos de un numero es mayor al numero en cuestion, como mucho sera igual (en caso de un digito)
  - No se puede tener un costo menor a 1, y la unica manera de tener un costo 1 es que sea de un digito

## C - Simple repetition
- Greedy

1. Demostrar que para cualquier k > 1, con un x > 1 no puede ser primo, ya que siempre multiplica por x y nunca x es y
2. Si k es uno, mostrar YES si x es primo
3. Si x es 1, entonces por fuerza bruta o comprar rapidamente localmente, el unico primo es 11

### Necesito

- Implementar efectivamente la criba de eratostenes
- Para numeros superiores, primero hacer una criba hasta 1e5, y despues hacer la prueba de primalidada

## D - Skibidi Table
- Greedy

La idea basica es partir desde la definicio de rangos en los cuales puede estar un numero, a partir de donde podemos deducir como se veran afectados (reducidos) los rangos en los que puede estar el numero en cuanto a sus indices

Para encontrar las coordenadas de un numero, hacer una busqueda tetraria por los 4 subespacios de numeros en los que se divide el rango mas grande, y dependiendo del cuadrante, reducir los posibles indices, hasta dar con uno

## E - Min max MEX
