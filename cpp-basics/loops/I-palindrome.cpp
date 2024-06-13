#include<iostream> 

using namespace std;

int main(){
  string s; 
  string reverse;
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    reverse = s[i] + reverse;
  }
  int a, b;
  a = stoi(s);
  b = stoi(reverse);
  cout << b << endl;
  cout << ((a == b) ? "YES" : "NO");
}
