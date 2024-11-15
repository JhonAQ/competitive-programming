#include<bits/stdc++.h>

using namespace std;

#define ll long long

/* Fibonacci, implementaciones: 
* - Fibonacci Recursivo (No es necesariamente la implementación mas eficiente
* - Fibonacci Iterativo (Sin memoizacion)
* - Fibonacci Iterativo (Con memoizacion)
*/

ll fibRecursivo(int n){
  if(n <= 1) return n;
  return fibRecursivo(n - 1) + fibRecursivo(n - 2);
}

ll fibIterativo(int n){
  ll a = 0, b = 1, ans = 1;
  for(int i = 0; i < n - 1; i++){
    ans = a + b;
    a = b;
    b = ans;
  }
  return ans;
}

ll fibMemo(int n, ll memo[]){
  if (n >= 0) memo[0] = 0; 
  if (n >= 1) memo[1] = 1;

  for (int i = 2; i <= n; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
  }
  return memo[n];
}

int main(){
  int n; cin >> n;
  ll memo[n + 1];
  memo[0] = 0;
  memo[1] = 1;
  memset(memo, -1, sizeof(memo));
  ll fibo;
  //fibo = fibRecursivo(n);
  //fibo = fibIterativo(n);
  fibo = fibMemo(n, memo);
  cout << "Fibo de " << n << ": " << fibo << "\n";
}
