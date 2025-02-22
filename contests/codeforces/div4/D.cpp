#include<bits/stdc++.h>
#define RAYA cerr << "-----------------------------------" << endl
#define DBG(x) cerr << #x << " = " << (x) << endl


using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int bajo = 0, alto = 0;
    vector<int> rangx;
    int puntos[n + 1][2];
    puntos[n + 1][0] = -1;
    puntos[n + 1][1] = -1;
    int rectos = 0;
    for(int i = 0; i < n; i++){

      puntos[i][0] = -1;
      puntos[i][1] = -1;
      int x, y; cin >> x >> y;
      puntos[x][y] = 1;
      if(find(rangx.begin(), rangx.end(), x) != rangx.end())
        rectos++;
      rangx.push_back(x);
      if(y) alto++; 
      else bajo++;
    }
    int ans = rectos * (alto - 1) + rectos * (bajo - 1);
    //RAYA;
    //DBG(ans);
    //RAYA;
    for(int i = 0; i <= n; i++){
      if(puntos[i][0] != -1){
        bool pUno = puntos[i + 1][1] != -1;
        bool pDos = puntos[i + 2][0] != -1;
        if(pUno && pDos){
          ans++;
        }
      }
      if(puntos[i][1] != -1){
        bool pUno = puntos[i + 1][0] != -1;
        bool pDos = puntos[i + 2][1] != -1;
        if(pUno && pDos){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }

}
