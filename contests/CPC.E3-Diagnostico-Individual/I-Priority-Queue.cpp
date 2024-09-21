#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

void insert(int j) {
  pq.push(j);
}

void extract() {
  if (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  } else {
    cout << "" << endl;
  }
}

int main() {
  string op;
  while (cin >> op && op != "end") {
    if (op == "insert") {
      int aux;
      cin >> aux;
      insert(aux);
    }
    if (op == "extract") {
      extract();
    }
  }
}
