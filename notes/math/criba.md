# Criba de eratostenes

## Implementacion

```cpp
int n;
vector<bool> isPrime(n+1, true);
isPrime[0] = isPrime[1] = false;
for(int i = 2; i * i <= n; i++){
  if(isPrime[i]){
    for(int j = i * i; j <= n; j+=i){
      isPrime[j] = false;
    }
  }
}
```

## Consideraciones

- Otras implementaciones en la forma de almacenar los primos como `vector<char>` y `bitset<int>` pueden ahorrar mas memoria (ya que trabajan con bits y no bytes), pero son un poco mas lentas para acceder a los elementos
