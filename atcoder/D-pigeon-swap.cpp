#include<bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl
#define RAYA cerr << "=======================" << endl
#define MSG(x) cerr << #x << endl;

using namespace std;

vector<int> pigeons;

int getNest(int n){
  return pigeons[n];
}

void op1(int a, int b){
  pigeons[a] = b;
}

void op2(int a, int b){
  /* MSG("operacion 2"); */
  /* RAYA; */
  for(int i = 0; i < pigeons.size(); i++){
    if(pigeons[i] == a) {
      /* MSG("Pigeon cambiado"); */
      /* DBG(pigeons[i]); */
      pigeons[i] = b;
      /* DBG(pigeons[i]); */
    }
    else if(pigeons[i] == b){
      /* MSG("Pigeon cambiado"); */
      /* DBG(pigeons[i]); */
      pigeons[i] = a;
      /* DBG(pigeons[i]); */
    }
  }
  
}

void op3(int a){
  cout << getNest(a) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q; cin >> n >> q;
  pigeons.assign(n, -1);
  for(int i = 0; i < pigeons.size(); i++){
    pigeons[i] = i;
  }
  while(q--){
    int op; cin >> op;
    int a, b;
    if(op == 1){
      cin >> a >> b;
      op1(a, b);
    }else if(op == 2){
      cin >> a >> b;
      op2(a, b);
    }else{
      cin >> a;
      op3(a);
    }
  }
}
