# La criba Lineal

Tiene un tiempo de complejidad lineal, pero usa mucha memoria (limite recomendado: n = 1e7), como efecto secundario genera la factorizacion de cada numero

## Implementacion

```cpp
const int N = 10000000;
vector<int> lp(N + 1);
vector<int> pr;

for(int i = 2; i <= N; ++i){
  if(lp[i] == 0){
    lp[i] = i;
    pr.push_back(i);
  }
  for(int j = 0; i * pr[j] <= N; ++j){
    lp[i * pr[j]] = pr[j];
    if(pr[j] == lp[i]) break;
  }
}
```

## Consideraciones

En la practica es igual de rapido que la criba normal

```

```
