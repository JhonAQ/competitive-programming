#include<iostream>

using namespace std;

int main(){
  char s; int n;
  cin >> s >> n;
  while(n--){
    int x; cin >> x;
    for(int i = 0; i < x; i++) cout << s;
    cout << endl;
  }
}
