#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dbg(x) cerr << (#x) << " = " << (x) << " "
#define fallaDebug cerr << "\n"
#define raya cerr << "--------------------------------\n"

struct Range {
  int low, high;
};

static Range getStartRange(const vector<int> &v) {
  int n = (int)v.size();
  if(n == 0) return Range{0, 0};
  vector<long long> pref(n+1, 0LL);
  for(int i = 0; i < n; i++){
    pref[i+1] = pref[i] + v[i];
  }
  long long mn = LLONG_MAX, mx = LLONG_MIN;
  for(int j = 0; j < n; j++){
    long long sumSeg = pref[j+1] - pref[0]; 
    mn = min(mn, sumSeg);
    mx = max(mx, sumSeg);
  }
  return Range{mn, mx};
}

static Range getEndRange(const vector<int> &v) {
  int n = (int)v.size();
  if(n == 0) return Range{0, 0};
  vector<long long> pref(n+1, 0LL);
  for(int i = 0; i < n; i++){
    pref[i+1] = pref[i] + v[i];
  }
  long long mn = LLONG_MAX, mx = LLONG_MIN;
  for(int i = 0; i < n; i++){
    long long sumSeg = pref[n] - pref[i];
    mn = min(mn, sumSeg);
    mx = max(mx, sumSeg);
  }
  return Range{mn, mx};
}

static Range getSubsRange(const vector<int> &v) {
  if (v.empty()) return Range{0, 0};
  int s = 0, lo = 0, hi = 0, loPref = 0, hiPref = 0;
  for (auto &x : v) {
    s += x;
    hi = max(hi, s - loPref);
    lo = min(lo, s - hiPref);
    loPref = min(loPref, s);
    hiPref = max(hiPref, s);
  }
  return Range{lo, hi};
}

void solve() {
  int n; 
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  int cnt = 0, pos = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1 && a[i] != -1) {
      cnt++;
      pos = i;
    }
  }

  if (!cnt) {
    Range r = getSubsRange(a);
    set<int> st;
    for (int x = r.low; x <= r.high; x++){
      st.insert(x);
    }
    st.insert(0);
    cout << st.size() << "\n";
    for (auto &val : st) cout << val << " ";
    cout << "\n";
    return;
  }

  int x = a[pos];
  vector<int> L(a.begin(), a.begin() + pos);
  vector<int> R(a.begin() + pos + 1, a.end());

  Range leftSubs = getSubsRange(L);
  Range rightSubs = getSubsRange(R);
  Range leftEnd  = getEndRange(L);
  Range rightStart = getStartRange(R);

  set<int> sums;
  for (int i = leftSubs.low; i <= leftSubs.high; i++){
    sums.insert(i);
  }
  for (int j = rightSubs.low; j <= rightSubs.high; j++){
    sums.insert(j);
  }
  for (int Lval = leftEnd.low; Lval <= leftEnd.high; Lval++){
    for (int Rval = rightStart.low; Rval <= rightStart.high; Rval++){
      sums.insert(Lval + x + Rval);
    }
  }
  sums.insert(0);

  vector<int> ans(sums.begin(), sums.end());
  cout << ans.size() << "\n";
  for (auto &val : ans){
    cout << val << " ";
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

