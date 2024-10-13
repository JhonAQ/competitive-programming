# Busqueda en profundidad

- **Complejidad:** `O(V + E)` para grafos representados por listas de adyacencia.
- **Complejidad:** `O(V²)` para grafos representados por matriz de adyacencia.
- **Complejidad:** `O(V*E)` para grafos representados por listas de vertices.

La busqueda en profundidad de manera recursiva, se hace partiendo desde un nodo
original y se recorriendo todos sus vecinos que no hayan sido visitados.

Sin embargo no sirve cuando es un grafo no conexo.

## DFS vs backtracking recursivo

Un backtracking resursivo recorre todas las posibles combinaciones en el grafo por lo que es exponencial, en cambio un DFS es eficiente y rapido.

## Pseudocodigo

```txt
vector visited
fn dfs(v){
  visited[u] = true
  for(vertice in u.LA){
    dfs(vertice) if visited[vertice] == false
  }
}
```
