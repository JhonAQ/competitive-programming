#include<bits/stdc++.h>

using namespace std;

bool comp(string a, string b){
  int lina = a.length();
  int linb = b.length();
//  cout << "a: " << a << ", " << lina << "\t b: "<< b << ", " << linb << endl;
  if(lina != linb) return lina < linb;
//  cout << "SE DECIDE POR LEXICOGRAFICO " << a << " <> " << b << endl;
  for(int i = 0; i < lina; i++){
    if(a[i] == b[i]) continue;
    return a[i] < b[i];
  }
  return false;
}

int main(){
  vector<string> nums;
  int tc; cin >> tc;
  while(tc--){
    string n; cin >> n;
    nums.push_back(n);
  }
  sort(nums.begin(), nums.end(), comp);
  for(string n: nums){
    cout << n << endl;
  }

}
