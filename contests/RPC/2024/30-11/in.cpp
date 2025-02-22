#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> solve_laundry_problem(vector<pair<ll, vector<ll>>> &test_cases) {
    vector<ll> results;
    for (auto &test_case : test_cases) {
        ll k = test_case.first;
        vector<ll> &counts = test_case.second;
        ll c1 = counts[0], c2 = counts[1], c3 = counts[2];
        ll c4 = counts[3], c5 = counts[4], c6 = counts[5], c7 = counts[6];

        // Initialize
        ll total_items_A = c1;
        ll total_items_B = c2;
        ll total_items_C = c3;
        ll lA = (total_items_A + k - 1) / k;
        ll lB = (total_items_B + k - 1) / k;
        ll lC = (total_items_C + k - 1) / k;
        ll rA = lA * k - total_items_A;
        ll rB = lB * k - total_items_B;
        ll rC = lC * k - total_items_C;

        // Process c4 (A and B)
        ll c4_items = c4;
        while (c4_items > 0 && (rA > 0 || rB > 0)) {
            if (rA >= rB) {
                ll m = min(c4_items, rA);
                total_items_A += m;
                rA -= m;
                c4_items -= m;
            } else {
                ll m = min(c4_items, rB);
                total_items_B += m;
                rB -= m;
                c4_items -= m;
            }
        }

        if (c4_items > 0) {
            ll delta_lA = ((total_items_A + c4_items + k - 1) / k) - lA;
            ll delta_lB = ((total_items_B + c4_items + k - 1) / k) - lB;
            if (delta_lA <= delta_lB) {
                total_items_A += c4_items;
                lA += delta_lA;
            } else {
                total_items_B += c4_items;
                lB += delta_lB;
            }
            c4_items = 0;
        }

        // Update residuals
        rA = lA * k - total_items_A;
        rB = lB * k - total_items_B;

        // Process c5 (B and C)
        ll c5_items = c5;
        while (c5_items > 0 && (rB > 0 || rC > 0)) {
            if (rB >= rC) {
                ll m = min(c5_items, rB);
                total_items_B += m;
                rB -= m;
                c5_items -= m;
            } else {
                ll m = min(c5_items, rC);
                total_items_C += m;
                rC -= m;
                c5_items -= m;
            }
        }

        if (c5_items > 0) {
            ll delta_lB = ((total_items_B + c5_items + k - 1) / k) - lB;
            ll delta_lC = ((total_items_C + c5_items + k - 1) / k) - lC;
            if (delta_lB <= delta_lC) {
                total_items_B += c5_items;
                lB += delta_lB;
            } else {
                total_items_C += c5_items;
                lC += delta_lC;
            }
            c5_items = 0;
        }

        // Update residuals
        rB = lB * k - total_items_B;
        rC = lC * k - total_items_C;

        // Process c6 (A and C)
        ll c6_items = c6;
        while (c6_items > 0 && (rA > 0 || rC > 0)) {
            if (rA >= rC) {
                ll m = min(c6_items, rA);
                total_items_A += m;
                rA -= m;
                c6_items -= m;
            } else {
                ll m = min(c6_items, rC);
                total_items_C += m;
                rC -= m;
                c6_items -= m;
            }
        }

        if (c6_items > 0) {
            ll delta_lA = ((total_items_A + c6_items + k - 1) / k) - lA;
            ll delta_lC = ((total_items_C + c6_items + k - 1) / k) - lC;
            if (delta_lA <= delta_lC) {
                total_items_A += c6_items;
                lA += delta_lA;
            } else {
                total_items_C += c6_items;
                lC += delta_lC;
            }
            c6_items = 0;
        }

        // Update residuals
        rA = lA * k - total_items_A;
        rC = lC * k - total_items_C;

        // Process c7 (A, B, C)
        ll c7_items = c7;
        while (c7_items > 0 && (rA > 0 || rB > 0 || rC > 0)) {
            ll max_r = max({rA, rB, rC});
            if (max_r == rA) {
                ll m = min(c7_items, rA);
                total_items_A += m;
                rA -= m;
                c7_items -= m;
            } else if (max_r == rB) {
                ll m = min(c7_items, rB);
                total_items_B += m;
                rB -= m;
                c7_items -= m;
            } else {
                ll m = min(c7_items, rC);
                total_items_C += m;
                rC -= m;
                c7_items -= m;
            }
        }

        if (c7_items > 0) {
            ll delta_lA = ((total_items_A + c7_items + k - 1) / k) - lA;
            ll delta_lB = ((total_items_B + c7_items + k - 1) / k) - lB;
            ll delta_lC = ((total_items_C + c7_items + k - 1) / k) - lC;
            ll min_delta = min({delta_lA, delta_lB, delta_lC});
            if (min_delta == delta_lA) {
                total_items_A += c7_items;
                lA += delta_lA;
            } else if (min_delta == delta_lB) {
                total_items_B += c7_items;
                lB += delta_lB;
            } else {
                total_items_C += c7_items;
                lC += delta_lC;
            }
            c7_items = 0;
        }

        // Recalculate loads
        lA = (total_items_A + k - 1) / k;
        lB = (total_items_B + k - 1) / k;
        lC = (total_items_C + k - 1) / k;

        ll total_loads = lA + lB + lC;
        results.push_back(total_loads);
    }
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<pair<ll, vector<ll>>> test_cases;
    for (int i = 0; i < t; ++i) {
        ll k;
        cin >> k;
        vector<ll> counts(7);
        for (int j = 0; j < 7; ++j) {
            cin >> counts[j];
        }
        test_cases.emplace_back(k, counts);
    }

    vector<ll> results = solve_laundry_problem(test_cases);

    for (ll res : results) {
        cout << res << endl;
    }

    return 0;
}
