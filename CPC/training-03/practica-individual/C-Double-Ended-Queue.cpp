#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  int t = tc;
  while(t--){
    deque<int> dq; 
    cout << "Case " << tc - t << ":\n";
    int n, m; cin >> n >> m;
    while(m--){
      string op; cin >> op;
      int num;
      if(op.find("push") == 0){
        cin >> num;
        if(!n){
          cout << "The queue is full\n";
          continue;
        }
      }else if(dq.empty()){
        cout << "The queue is empty\n";
        continue;
      }

      if(op == "pushLeft"){
        dq.push_front(num);
        cout << "Pushed in left: " << num << "\n";
        n--;
      }else if(op == "pushRight"){
        dq.push_back(num);
        cout << "Pushed in right: " << num << "\n";
        n--;
      }else if(op == "popRight"){
        cout << "Popped from right: " << dq.back() << "\n";
        dq.pop_back();
        n++;
      }else{
        cout << "Popped from left: " << dq.front() << "\n";
        dq.pop_front();
        n++;
      }
    }
  }
}
