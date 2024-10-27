#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  if (n==0) {
    cout << -100 -100 << '\n';
    return 0;
  }
  int r1 = 0, l1 = 0, r2 = 0, l2 = 0;
  bool flagR1 = true;
  for(int i = 0; i < n; i
    int a, b; cin >> a >> b;
    if(i == 0){
      l1 = a;
      r1 = b;
    }else{
      if(flagR1 || ((l1 <= a && a <= r1) || (l1 <= b && b<= r1))){
        bool rang1 = l1 <= a && a<= r1;
        bool rang2 = l1 <= b && b <= r1;
        if(rang1 ||  rang2){
          if(rang1){
            l1 = a;
          }
          if(rang2){
            r1 = b;
          }  
          continue;
        }
        flagR1 = false;
        l2 = a; r2 = b;
      }else{
        bool rang1 = l2 <= a && a <= r2;
        bool rang2 = l2 <= b && b <= r2;
        if(rang1 || rang2){
          if(rang1){
            l2 = a;
          }
          if(rang2){
            r2 = b;
          }  
          continue;
        }
        
        cout << -1 << endl; return 0;
      }

    }
  }
  if(r2 == 0 && l2 ==0){
    cout << l1 << " " << l1 << endl;
    return 0 ;
  }
  if(l2 < l1){
    int temp = l1;
    l1 = l2;
    l2 = temp;
  }
  cout << l1 << " " << l2 << endl;
}
