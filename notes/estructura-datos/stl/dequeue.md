# Dequeue

Un dequeue o doble cola es una estructura de datos que permite agregar y eliminar elementos al principio y al final de la cola. Es una estructura de datos muy versátil, ya que combina las ventajas de una pila y una cola.

Se hace con listas enlazadas, lo que permite agregar y eliminar elementos en tiempo constante, a diferencia de los vectores que tienen un tiempo lineal.

## Funciones utiles

```cpp
deque<int> d; // Declarar un dequeue de enteros
d.push_front(1); // Agregar un elemento al principio
d.push_back(2); // Agregar un elemento al final
d.pop_front(); // Eliminar el primer elemento
d.pop_back(); // Eliminar el ultimo elemento
d.front(); // Primer elemento
d.back(); // Ultimo elemento

// Las siguientes funciones son generales para cualquier contenedor
d.size(); // Tamaño del dequeue
d.empty(); // Verificar si el dequeue esta vacio
d.clear(); // Limpiar el dequeue
```
