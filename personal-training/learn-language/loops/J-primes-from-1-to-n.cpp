#include<iostream>

using namespace std;

bool isPrime(int x){
  for(int i = 2; i < x; i++){
    if(x % i == 0) return false;
  }
  return true;
}

int main(){
  int x;
  cin >> x;

  for(int i = 2; i <= x; i++){
    if(isPrime(i)) cout << i << " ";
  }
  
}
