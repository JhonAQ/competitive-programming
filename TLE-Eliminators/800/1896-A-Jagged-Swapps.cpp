#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;

  while(tc--){
    int n; cin >> n;
    int arr[n];
    int minN = 1;
    for(int i = 0 ; i< n; i++){cin >> arr[i]; minN = min(minN, arr[i]);}
    if(is_sorted(arr, arr+n)){
      cout << "YES" << endl;
      continue;
    }
    if(arr[0] == minN){
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" <<endl;
  }
}
