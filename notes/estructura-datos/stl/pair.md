# Pair

Se usa para combinar dos unidades de datos en una sola entidad. Es útil cuando
se necesita almacenar dos valores juntos.

Se accede al primer elemento con `.first` y al segundo con `.second`

```cpp
pair<int, int> par;
par.first = 1;
par.second = 2;

// Tambien:
par = make_pair(3, 7);

// Tambien:
par = {3, 7};

cout << par.first << " " << par.second << "\n";
```

## Template

```cpp
#define pii pair<int, int>
#define p3i pair<pii, int>
#define mkp make_pair
```

**Uso:**

```cpp
p31 a;
a = mkp(mkp(3, 7), 11);
cout << a.first.first << endl;
cout << a.first.second << endl;
cout << a.second << endl;
```
