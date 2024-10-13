# Busqueda en profundidad

- **Complejidad:** `O(V + E)` para grafos representados por listas de adyacencia.
- **Complejidad:** `O(V²)` para grafos representados por matriz de adyacencia.
- **Complejidad:** `O(V*E)` para grafos representados por listas de vertices.

La busqueda en profundidad de manera recursiva, se hace partiendo desde un nodo
original y se recorriendo todos sus vecinos que no hayan sido visitados.

Sin embargo no sirve cuando es un grafo no conexo.
