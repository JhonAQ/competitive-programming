#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &arr, vector<string> &bui){
	int fila = arr.size() - bui.size();
	int col = arr[0].size() - bui[0].size();
	int ans = 0;
	for(int i = 0; i <= fila; i++){
		for(int j = 0; j <= col; j++){
			int temp = 0;
			int stfila = i;
			int stcol = j;
			for(int x = 0; x < arr.size(); x++){
				for(int y = 0; y < arr[0].size(); y++){
					int v1 = x-stfila;
					int v2 = y-stcol;
					//cout<<"v1: "<<v1<<endl;
					//cout<<"v2: "<<v2<<endl;
					if((v1 < 0 || v1 >= bui.size() ) || (v2 < 0 || v2>= bui[0].size())){
						temp += arr[x][y];
					}else{
						if(bui[v1][v2] == '.') temp+= arr[x][y];
					}
				}
			}
			ans = max(ans, temp);
		}
	}
	return ans;
}


int main(){
	int r,c; cin>>r>>c;
	vector<vector<int>> arr(r, vector<int>(c));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>>arr[i][j];
		}
	}
	int s,t; cin>>s>>t;
	vector<string> b(s);
	for(auto &x: b) cin>>x;
	
	
	vector<vector<int>> arr1(c, vector<int>(r));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			arr1[j][r-i-1] = arr[i][j];
		}
	}
	vector<vector<int>> arr2(r, vector<int>(c));
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			arr2[j][c-i-1] = arr1[i][j];
		}
	}
	vector<vector<int>> arr3(c, vector<int>(r));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			arr3[j][r-i-1] = arr2[i][j];
		}
	}
	/*
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			cout<<arr1[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			cout<<arr3[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int res1 = solve(arr, b);
	int res2 = solve(arr1, b);
	int res3 = solve(arr2, b);
	int res4 = solve(arr3, b);
	
	cout<<max(res1, max(res2, max(res3, res4)))<<endl;
}
