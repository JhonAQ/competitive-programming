#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  cin.ignore();

  vector<int> rows(n, 0);
  vector<int> columns(n, 0);
  vector<vector<int>> items;

  for (int i = 0; i < n; i++) {
    string row; 
    getline(cin, row);
    for (int j = 0; j < n; j++) {
      int value = row[j] == 'o' ? 1 : 0;
      rows[i] += value;
      columns[j] += value;
      if (value)
        items.push_back({i, j});
    }
  }
  for (int i = 0; i < n; i++) {
    cout << rows[i] << " ";
  }
  cout <<endl;
  for (int i = 0; i < n; i++) {
    cout << columns[i] << " ";
  }
  cout <<endl;
}
