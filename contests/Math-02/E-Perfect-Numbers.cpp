#include<bits/stdc++.h>

using namespace std;

unordered_set<long long> p;

unsigned long long n(int x){
  unsigned long long a = 1ULL << (x -1);
  unsigned long long b = (1ULL << x) - 1;
  if(x == 34){
    // cout << "\t" << a << " " << b << endl;
  }
  return a * b;
}

int main(){
  p.insert(28);
  p.insert(6);
  p.insert(496);
  p.insert(8128);
  p.insert(33550336);
  p.insert(8589869056);
  int tc; cin >> tc;
  while(tc--){
    int a;
    scanf("%d,", &a);
    if(a < 0 || a > 65){
      cout << "No\n";
      continue;
    }
    unsigned long long b = n(a);
    cout << (p.find(b) != p.end() ? "Yes\n" : "No\n");
  }
}