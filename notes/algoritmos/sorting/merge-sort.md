# Merge sort

- **Complejidad algoritmica:** O(n log n)
- **Estable:** Si
- **In-place:** No, pero se puede mejorar

Se usa el paradigma de divide y venceras, en cada paso recursivo, se divide el arreglo en dos mtades, se ordena y se hace 'merge' en el array original.

## Pseudocodigo

- Merge sort recursivo
- si la longitud del array es 1, entonces se retorna el array
- si no, se llama a merge por la izquierda y merge por la derecha
- se hacer 'merge' en el arreglo original
