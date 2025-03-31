#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    long long k;
    cin >> k;

    if(k == 0){
      cout << 1 << "\n" << 0 << " " << 0 << "\n";
      continue;
    }

    vector<int> groups;
    long long remaining = k;
    while(remaining > 0){
      double d = sqrt(1.0 + 8.0 * remaining);
      int r = (int) floor((1.0 + d) / 2.0);
      if(r < 2) r = 2;
      groups.push_back(r);
      remaining -= (long long) r*(r-1)/2;
    }

    int totalPoints = 0;
    for(auto r : groups)
      totalPoints += r;

    cout << totalPoints << "\n";

    const int OFFSET = 1000;

    int groupIndex = 0;
    for(auto r : groups){
      int y = groupIndex;
      int baseX = groupIndex * OFFSET;
      for(int j = 0; j < r; j++){
        cout << baseX + j << " " << y << "\n";
      }
      groupIndex++;
    }
  }
}
