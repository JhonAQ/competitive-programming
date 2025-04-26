#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	set<int> st;
	for(int i = 1; i <= 2*n; i++){
		st.insert(i);
	}
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		int x;cin>>x;
		a[i] = x;
		st.erase(x);
	}
	int mi = 0;
	int ma = 0;

	set<int> st1 = st;
	for(int i = 0; i < n; i++){
		int num = a[i];
		auto it = st1.upper_bound(num);
		if(it == st1.begin()){
			//cout<<"No hay un numero menor!"<<endl;
		}else{
			--it;
			mi++;
			st1.erase(it);
		}
	}
	set<int> st2 = st;
	for(int i = 0; i < n; i++){
		int num = a[i];
		auto it = st2.upper_bound(num);
		if(it != st2.end()){
			st2.erase(it);
		}else{
			ma++;
			st2.erase(st2.begin());
		}
		
	}
	
	cout<<ma<<" "<<mi<<endl;


}
