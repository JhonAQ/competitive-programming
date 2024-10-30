#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main(){
  int count = 0;
  vector<int> coins;
	int n, x; cin >> n >> x;
	vector<int> memo(x + 1, INF);
	memo[0] = 0;
	for(int i = 0; i <n; i++){
	  int c; cin >> c;
		coins.push_back(c);
		//cout << c << endl;
	}
	for(int i = 0; i <= x; i++){
	  for(int moneda : coins){
      /*if(count >= 1000000) cout << "que paso aqui";*/
		  //cout << "i: " <<  i <<  " modeda:" << moneda << " "<< endl;
		  if(i + moneda <= x){
			  memo[i + moneda] = min(memo[i + moneda], memo[i] + 1);
			}
		}
	}
	if(memo[x] != INF){
	  cout << memo[x]<<endl;
	}else{
	  cout << -1 << endl;
	}

}
