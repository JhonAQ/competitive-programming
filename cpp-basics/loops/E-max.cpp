#include<iostream>

using namespace std;

int main(){
  int tc;
  cin >> tc;
  int max;
  cin >> max;
  tc--;
  while(tc--){
    int number;
    cin >> number;
    if(number > max) max = number;
  }
  cout << max;
}