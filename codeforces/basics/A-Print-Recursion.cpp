#include<bits/stdc++.h>

using namespace std;
void solve(int n){
  if(n == 0) return;
  cout << "I love Recursion\n";
  solve(n--);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; 
  solve(n);
}
