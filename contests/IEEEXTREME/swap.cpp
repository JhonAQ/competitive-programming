#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  ios_base::sync_with_stdio(false);
  string n;
  cin >> n;
  int k; cin >> k;
  for (int i = 0; i < k; ++i) {
    if (i == (int)( n.size()-1 )) {
      cout << n << '\n'; return 0;
    }
    int max_idx = i+1;
    for (int j = i+1; j < (int)( n.size() ); ++j) {
      if (n[j] >= n[max_idx]) max_idx = j;
    }
    //cout << max_idx << " - "<<i << '\n';
    if (n[max_idx] > n[i]){
      char tmp = n[i];
      n[i] = n[max_idx];
      n[max_idx] = tmp;
    } else k++;
  }
  cout << n << '\n';
  return 0;
}


