# El sort de la STL

Es un sort ya implementado en la libreria estandar de C++, que ordena un rango de elementos en un contenedor. La complejidad de este algoritmo es O(n log n), y es estable.

**Es el introsort** -> combinación entre **Heapsort**, **Quicksort** y **Merge sort**

## Forma de uso

Para arrays:

```cpp
int arr[] = {5, 2, 4, 1, 3};

// Donde n es el numero hasta donde queremos ordenar

sort(arr, arr + n);
```

Para vectores:

```cpp
vector<int> v = {5, 2, 4, 1, 3};

sort(v.begin(), v.end());
```

- Para crear ordenamientos personalizados debemos usar un comparador
