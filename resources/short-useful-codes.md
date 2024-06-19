## How to iterate a string: 
```cpp
int j = 0;
string str = "Palabra";
while(str[j]){
  char ch = str[j];
  cout << ch; 
  j++;
}
```

## How to swap two variables without temp: 
```cpp
auto a = "2"
auto b = "3"

a ^= b;
b = a ^ b
a = a ^ b;
```
