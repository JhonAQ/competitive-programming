# Struct

Equivalentes a las clases de otros lenguajes, pero con menos funcionalidades.Publicas por defecto a menos que se indique lo contrario, tiene atributos y funciones, asi como un constructor.

```cpp
struct Club {
    int a;
    int b;
    void imprimir() {
        cout << a << " " << b << "\n";
    }
};
```

**Constructor**

Los structs pueden tener un constructor, que se llama al declarar una variable de ese tipo.

### Operator +

Es un operador que define la suma de dos objetos de la clase. Se puede definir como una función miembro o externa.

```cpp
Club operator + (Club &c) {
    Club temp;
    temp.a = a + c.a;
    temp.b = b + c.b;
    return temp;
}
```
