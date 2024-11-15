# Busqueda de componentes conexos

Este algoritmo usa dfs para buscar todos los componentes conexos de un grafo
(tambien se puede implementar con BFS)

La idea basica es iterar sobre todos nuestros vertices en orden siempre q no
fueron visitdos previamente, luego aplicar dfs en cada uno de ellos que NO hayan
sido sido visitados aun.

Como dfs solo encuentra los nodos de 1 componente conexo, los que no han sido
visitados despues de un dfs forman aprte de un nuevo componente conexo, que
gracias a la primera iteración son visitados ahora

## Pseudocodigo

```txt
def numCC 
para cada vertice u en V:
  si dfs_[u] == UNVISITED:
    ++numCC
    dfs(u)
```
