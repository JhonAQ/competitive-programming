
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

    /*ll lA = (A + k - 1) / k;
    ll lB = (B + k - 1) / k;
    ll lC = (C + k - 1) / k;
    ll rA = lA * k - A;
    ll rB = lB * k - B;
    ll rC = lC * k - C;

    // Procesar ab
    ll abRopas = ab;
    while (abRopas > 0 && (rA > 0 || rB > 0)) {
      if (rA >= rB) {
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

    rA = lA * k - A;
    rB = lB * k - B;
    */

    ll ans = LLONG_MAX;
    for (int mask = 0; mask < 8; ++mask) {
      ll cntA = A;
      ll cntB = B;
      ll cntC = C;
      if ((mask & 1) == 0) {
        cntA += ab;
      } else {
        cntB += ab;
      }
      if ((mask & 2) == 0) {
        cntA += ac;
      } else {
        cntC += ac;
      }
      if ((mask & 4) == 0) {
        cntB += bc;
      } else {
        cntC += bc;
      }

      ll LA = (cntA + k - 1) / k;
      ll LB = (cntB + k - 1) / k;
      ll LC = (cntC + k - 1) / k;

      ll resA = LA * k - cntA;
      ll resB = LB * k - cntB;
      ll resC = LC * k - cntC;

      ll abcRes = abc;
      ll tempA = cntA, tempB = cntB, tempC = cntC;
      ll tempRestA = resA, tempRestB = resB, tempRestC = resC;
      ll tempLA = LA, tempLB = LB, tempLC = LC;
      ll temp_abc = abcRes;
      while (temp_abc > 0 && (tempRestA > 0 || tempRestB > 0 || tempRestC > 0)) {
        if (tempRestA >= tempRestB && tempRestA >= tempRestC && tempRestA > 0) {
          ll m = min(temp_abc, tempRestA);
          tempA += m;
          tempRestA -= m;
          temp_abc -= m;
        } else if (tempRestB >= tempRestA && tempRestB >= tempRestC && tempRestB > 0) {
          ll m = min(temp_abc, tempRestB);
          tempB += m;
          tempRestB -= m;
          temp_abc -= m;
        } else if (tempRestC > 0) {
          ll m = min(temp_abc, tempRestC);
          tempC += m;
          tempRestC -= m;
          temp_abc -= m;
        } else {
          break;
        }
      }

    /*

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

      acRopas = 0;
    }
    */

      tempLA = (tempA + k - 1) / k;
      tempLB = (tempB + k - 1) / k;
      tempLC = (tempC + k - 1) / k;

      if (temp_abc > 0) {
        ll extraLA = ((temp_abc + k - 1) / k);
        ll extraLB = ((temp_abc + k - 1) / k);
        ll extraLC = ((temp_abc + k - 1) / k);
        ll totalLA = tempLA + extraLA + tempLB + tempLC;
        ll totalLB = tempLB + extraLB + tempLA + tempLC;
        ll totalLC = tempLC + extraLC + tempLA + tempLB;

        ll minTL = min({totalLA, totalLB, totalLC});
        ans = min(ans, minTL);
      } else {
        ll totalL = tempLA + tempLB + tempLC;
        ans = min(ans, totalL);
      }
    }
    cout << ans << endl;
  }
}
