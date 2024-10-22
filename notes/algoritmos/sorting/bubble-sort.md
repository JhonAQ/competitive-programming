# Bubble sort

- **Complejidad algoritmica:** O(n^2)
- Estable: Si
- In-place: Si

Se hace el 'burbujeo' de los elementos mas grande hacia el final.

## Pseudocodigo

```python
para cada i en 0 hasta n-1:
    para cada j en 0 hasta n-i-1:
        si a[j] > a[j+1]:
          swap(a[j], a[j+1])
```
