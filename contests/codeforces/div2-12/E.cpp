#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Range {
  int low, high;
};

// Subarreglos completos (solo ±1) -> rango [low..high].
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

// Subarreglos que TERMINAN exactamente en el final (solo ±1).
static Range getEndRange(const vector<int> &v) {
  if (v.empty()) return Range{0, 0};
  int s = accumulate(v.begin(), v.end(), 0LL);
  int lo = s, hi = s;
  int sumP = 0, loPref = 0, hiPref = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    sumP += v[i];
    hi = max(hi, s - (sumP - loPref));
    lo = min(lo, s - (sumP - hiPref));
    loPref = min(loPref, sumP);
    hiPref = max(hiPref, sumP);
  }
  return Range{lo, hi};
}

// Subarreglos que EMPIEZAN exactamente al inicio (solo ±1).
static Range getStartRange(const vector<int> &v) {
  if (v.empty()) return Range{0, 0};
  int sumP = 0, lo = 0, hi = 0, loPref = 0, hiPref = 0;
  for (int i = (int)v.size() - 1; i >= 0; i--) {
    sumP += v[i];
    hi = max(hi, sumP - loPref);
    lo = min(lo, sumP - hiPref);
    loPref = min(loPref, sumP);
    hiPref = max(hiPref, sumP);
  }
  return Range{lo, hi};
}

void solve() {
  int n; 
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  // Localizamos el (posible) elemento distinto de ±1
  int cnt = 0, pos = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1 && a[i] != -1) {
      cnt++;
      pos = i;
    }
  }

  // Caso sin elemento raro: puras ±1
  if (cnt == 0) {
    Range r = getSubsRange(a);
    set<int> st;
    for (int x = r.low; x <= r.high; x++) {
      st.insert(x);
    }
    // Subarreglo vacío
    st.insert(0);

    cout << st.size() << "\n";
    for (auto &val : st) cout << val << " ";
    cout << "\n";
    return;
  }

  // Caso con elemento raro (x)
  int x = a[pos];

  // Partición en L y R
  vector<int> L(a.begin(), a.begin() + pos);
  vector<int> R(a.begin() + pos + 1, a.end());

  // Rangos de subarreglos en L y R (solo ±1)
  Range leftSubs  = getSubsRange(L);
  Range rightSubs = getSubsRange(R);

  // Subarreglos que terminan en L y empiezan en R (solo ±1)
  Range leftEnd   = getEndRange(L);
  Range rightStart= getStartRange(R);

  // Preparación para enumerar subarreglos que contengan x
  // => i <= pos <= j
  // Hacemos prefix sums
  vector<int> pref(n+1, 0);
  for (int i = 0; i < n; i++){
    pref[i+1] = pref[i] + a[i];
  }
  
  // Insertaremos todas las sumas en este set
  set<int> sums;

  // 1) Sumas de subarreglos en L
  for (int val = leftSubs.low; val <= leftSubs.high; val++) {
    sums.insert(val);
  }
  // 2) Sumas de subarreglos en R
  for (int val = rightSubs.low; val <= rightSubs.high; val++) {
    sums.insert(val);
  }
  
  // 3) Sumas que incluyen x, PERO en lugar de usar rangos,
  //    hacemos FUERZA BRUTA en [i..j] con i <= pos <= j.
  //    Así nos aseguramos de no perdernos ningún caso.
  for (int i = 0; i <= pos; i++) {
    for (int j = pos; j < n; j++) {
      // suma de subarreglo [i..j]
      int subSum = pref[j+1] - pref[i];
      sums.insert(subSum);
    }
  }

  // Subarreglo vacío = 0
  sums.insert(0);

  // Pasamos a vector, ordenamos e imprimimos
  vector<int> ans(sums.begin(), sums.end());
  // Ya que usamos set, ya está ordenado, pero si quisieras:
  // sort(ans.begin(), ans.end()); 
  cout << ans.size() << "\n";
  for (auto &val : ans) {
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
 // Part
