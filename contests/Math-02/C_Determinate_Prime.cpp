#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

bitset<32000> isP;

void generatePrimes(){
  isP.set();
  isP[0] = isP[1] = 0;
  for(int i = 2; i < 32000; i++)
    if(isP[i])
      for(int j = i * i; j < 32000; j += i)
        isP[j] = 0;
}

int main(){
  generatePrimes();
  for(int i = 1; i < 10666; i++){
    int count = 0;
    for(int j = 0; j < 31999; j+=i){
      if(isP[j]){
        if(count)
          cout << j << " ";
        else
          count++;
      }
      else
      count = 0;
    }
  }
}