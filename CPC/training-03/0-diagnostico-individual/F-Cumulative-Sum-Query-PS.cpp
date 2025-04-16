#include<bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }
  // Hacemos el prefix sum
  for(int i = 1; i < n; i++){
    //cout << nums[i] << endl;
    nums[i] += nums[i - 1];
  }

  int q; cin >> q;
  while(q--){
    int i, j; cin >> i >> j;
    if(i == 0){
      cout << nums[j] << "\n";
      continue;
    }
    cout << nums[j] - nums[i - 1] << endl;
  }
}
