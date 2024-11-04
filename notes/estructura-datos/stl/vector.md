# Vector

Arreglo dinamico, con muchas implementaciones eficientes para guardar/consultar datos.

### Funciones utiles

```cpp
vector<int> v; // Declarar un vector de enteros
v.push_back(1); // Agregar un elemento al final
v.pop_back(); // Eliminar el ultimo elemento
v.pop(); // Eliminar el ultimo elemento
v.size(); // Tamaño del vector
v.clear(); // Limpiar el vector
v.empty(); // Verificar si el vector esta vacio
v.front(); // Primer elemento
v.back(); // Ultimo elemento
v.at(0); // Elemento en la posicion 0
v.insert(v.begin() + 1, 2); // Insertar un 2 en la posicion 1
v.erase(v.begin() + 1); // Eliminar el elemento en la posicion 1
v.erase(v.begin(), v.begin() + 2); // Eliminar los elementos en el rango [0, 2)
v.resize(3); // Cambiar el tamaño del vector a 3
v.resize(3, 2); // Cambiar el tamaño del vector a 3 y llenar con 2
v.reserve(10); // Reservar espacio para 10 elementos
v.shrink_to_fit(); // Liberar espacio no utilizado
v.swap(v2); // Intercambiar los elementos de dos vectores
v.assign(5, 2); // Asignar 5 elementos con valor 2
v.assign(v2.begin(), v2.end()); // Asignar los elementos de v2
v.assign({1, 2, 3}); // Asignar los elementos {1, 2, 3}
v.emplace(v.begin(), 2); // Insertar un 2 en la posicion 0
v.emplace_back(3); // Insertar un 3 al final
```
