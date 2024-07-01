#include<iostream> 

using namespace std; 

int count = 0;

bool isLucky(int a){
  string str = to_string(a);
  for(int i = 0; i < str.size(); i++){
    if(str[i] != '7' and str[i] != '4') return false;
  }
  return true;
}

int main(){
  int a, b;

  cin >> a >> b;

  for(int i = a; i <= b; i++){
    if(isLucky(i)){
      cout << i << " ";
      count++;
    }
  }
  if(count == 0) cout << -1;
}