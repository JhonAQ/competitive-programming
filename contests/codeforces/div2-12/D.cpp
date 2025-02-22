#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define falla cout << -1 << " " << -1 << "\n";
#define debug(x) cerr << "[debug] " << #x << " = " << (x) << "\n";

bool test(ll a, ll b, ll s, ll e, ll Gmeta) {
  // debug(a)
  // debug(b)
  if (a >= s && a <= e && b >= s && b <= e && __gcd(a, b) == 1) {
    cout << a * Gmeta << " " << b * Gmeta << "\n";
    return true;
  }
  return false;
}

void solve() {
  ll l, r, Gmeta; cin >> l >> r >> Gmeta;
  ll s = (l + Gmeta - 1) / Gmeta; 
  ll e = r / Gmeta;

  // debug(s)
  // debug(e)

  if (s > e) {
    falla;
    return;
  }

  if (s == e) {
    if (s == 1)
      cout << Gmeta << " " << Gmeta << "\n";
    else falla;
    return;
  }

  if (test(s, e, s, e, Gmeta)) return;

  const int lim = 60; 
  ll maxX = -1, maxY = -1, maxDist = -1;

  for(int i = 0; i <= lim; i++){
    for(int j = 0; j <= lim; j++){
      ll x = s + i; 
      ll y = e - j;
      if(x > y) continue;
      if(x < s || x > e) continue;
      if(y < s || y > e) continue;
      if(gcd(x, y) == 1) {
        ll dist = y - x;
        if(dist > maxDist) {
          maxDist = dist; 
          maxX = x; 
          maxY = y;
        } else if(dist == maxDist && x < maxX) {
          maxX = x;
          maxY = y;
        }
      }
    }
  }

  if(maxDist >= 0)
    cout << maxX * Gmeta << " " << maxY * Gmeta << "\n";
  else falla;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--)
    solve();
}
