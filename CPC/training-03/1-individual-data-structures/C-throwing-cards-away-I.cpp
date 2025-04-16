#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << ": " << (x) << endl;
#define RAYA cerr << "===========" << endl;

int main() {
  int n;
  while(cin >> n && n){
    queue<int> q;
    for (int num = 1; num <= n; num++) {
      q.push(num);
    }
    cout << "Discarded cards:";
    bool first = true;
    while (q.size() > 1) {
      if (!first) cout << ",";
      cout <<" " <<  q.front();
      q.pop();
      first = false;
      q.push(q.front());
      q.pop();
    }
    cout << "\nRemaining card: " << q.front() << endl;
  }
}
