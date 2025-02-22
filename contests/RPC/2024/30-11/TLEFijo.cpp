#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    ll k; cin >> k;
    ll A, B, C, ab, bc, ac, abc;
    cin >> A >> B >> C >> ab >> bc >> ac >> abc;
    /*cout << a;*/
    /*cout << b;*/
    /*cout << c;*/
    /*cout << ab;*/
    /*cout << bc;*/
    /*cout << ac;*/

    ll lA = (A + k - 1) / k;
    ll lB = (B + k - 1) / k;
    ll lC = (C + k - 1) / k;
    ll rA = lA * k - A;
    ll rB = lB * k - B;
    ll rC = lC * k - C;

    // pars ab
    ll abRopas = ab;
    while (abRopas > 0 && (rA > 0 || rB > 0)) {

      // cout << "k: " << k << ", A: " << A << ", B: " << B << ", C: " << C << endl;
      // cout << "ab: " << ab << ", bc: " << bc << ", ac: " << ac << ", abc: " << abc << endl;
      if (rA >= rB) {
      /*cout << ab;*/
        ll m = min(abRopas, rA);
        A += m;
        rA -= m;
        abRopas -= m;
      } else {
        ll m = min(abRopas, rB);
        B += m;
        rB -= m;
        abRopas -= m;
      }
    }

    if (abRopas > 0) {
      ll diffLA = ((A + abRopas + k - 1) / k) - lA;
      ll diffLB = ((B + abRopas + k - 1) / k) - lB;
      if (diffLA <= diffLB) {
        A += abRopas;
        lA += diffLA;
      } else {
        B += abRopas;
        lB += diffLB;
      }
      abRopas = 0;
    }

    // Update residuals
    rA = lA * k - A;
    rB = lB * k - B;

    // Process bc (B and C)
    ll bcRopas = bc;
    while (bcRopas > 0 && (rB > 0 || rC > 0)) {
      if (rB >= rC) {
        ll m = min(bcRopas, rB);
        B += m;
        rB -= m;
        bcRopas -= m;
      } else {
        ll m = min(bcRopas, rC);
        C += m;
        rC -= m;
        bcRopas -= m;
        // cout << "Usando bc para B, B: " << B << ", rB: " << rB << ", bcRopas: " << bcRopas << endl;
      }
    }

    if (bcRopas > 0) {
      ll diffLB = ((B + bcRopas + k - 1) / k) - lB;
      ll diffLC = ((C + bcRopas + k - 1) / k) - lC;
      if (diffLB <= diffLC) {
        B += bcRopas;
        lB += diffLB;
      } else {
        C += bcRopas;
        lC += diffLC;
      }
      bcRopas = 0;
    }

    rB = lB * k - B;
    rC = lC * k - C;

    ll acRopas = ac;
    while (acRopas > 0 && (rA > 0 || rC > 0)) {
      if (rA >= rC) {
        ll m = min(acRopas, rA);
        A += m;
        rA -= m;
        acRopas -= m;
      } else {
        ll m = min(acRopas, rC);
        C += m;
        rC -= m;
        acRopas -= m;
      }
    }

    if (acRopas > 0) {
      ll diffLA = ((A + acRopas + k - 1) / k) - lA;
      ll diffLC = ((C + acRopas + k - 1) / k) - lC;
      if (diffLA <= diffLC) {
        A += acRopas;
        lA += diffLA;
      } else {
        C += acRopas;
        lC += diffLC;
      }
      acRopas = 0;
    }

    rA = lA * k - A;
    rC = lC * k - C;

    ll abcRopas = abc;
    while (abcRopas > 0 && (rA > 0 || rB > 0 || rC > 0)) {
      ll max_r = max({rA, rB, rC});
      if (max_r == rA) {
        ll m = min(abcRopas, rA);
        A += m;
        rA -= m;
        abcRopas -= m;
      } else if (max_r == rB) {
        ll m = min(abcRopas, rB);
        B += m;
        rB -= m;
        abcRopas -= m;
      } else {
        ll m = min(abcRopas, rC);
        C += m;
        rC -= m;
        abcRopas -= m;
      }
    }

    if (abcRopas > 0) {
      ll diffLA = ((A + abcRopas + k - 1) / k) - lA;
      ll diffLB = ((B + abcRopas + k - 1) / k) - lB;
      ll diffLC = ((C + abcRopas + k - 1) / k) - lC;
      ll min_delta = min({diffLA, diffLB, diffLC});
      if (min_delta == diffLA) {
        A += abcRopas;
        lA += diffLA;
      } else if (min_delta == diffLB) {
        B += abcRopas;
        lB += diffLB;
          /*cout << B << endl;*/
      } else {
        C += abcRopas;
        lC += diffLC;
        /*cout << lC << "\n";*/
      }
      abcRopas = 0;
    }

    lA = (A + k - 1) / k;
    lB = (B + k - 1) / k;
    lC = (C + k - 1) / k;


    // cout << "lA: " << lA << ", lB: " << lB << ", lC: " << lC << endl
    ll ans = lA + lB + lC;
    // cout << ans;
    cout << ans << endl;
  }
}
