#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define endl '\n'
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
#define FOR(i, a, b) for (auto i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;

vector<int> votos, pPts, mPts;

bool cmpVotos(int a, int b){
  return votos[a] > votos[b];
}

bool cmpTotal(int a, int b){
  int ta = pPts[a] + mPts[a];
  int tb = pPts[b] + mPts[b];
  if (ta != tb) return ta > tb;
  return mPts[a] > mPts[b];
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n; cin >> n;
  vector<int> pOrder(n);

  votos.assign(n, 0);
  pPts.assign(n, 0);
  mPts.assign(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> pOrder[i];
    pOrder[i]--;
  }

  for (int i = 0; i < n; i++) cin >> votos[i];

  for (int i = 0; i < n; i++) pPts[pOrder[i]] = n - i;

  vector<int> idx(n);
  for (int i = 0; i < n; i++) idx[i] = i;
  sort(idx.begin(), idx.end(), cmpVotos);

  for (int i = 0; i < n; i++) mPts[idx[i]] = n - i;

  for (int i = 0; i < n; i++) idx[i] = i;
  sort(idx.begin(), idx.end(), cmpTotal);

  for (int i = 0; i < n; i++) {
    int id = idx[i] + 1;
    int total = pPts[idx[i]] + mPts[idx[i]];
    cout << (i + 1) << ". Kod" << (id < 10 ? "0" : "") << id << " (" << total << ")\n";
  }
}
