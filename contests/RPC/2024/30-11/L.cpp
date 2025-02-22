
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        ll c1, c2, c3, c4, c5, c6, c7;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7;
        ll total_items = c1 + c2 + c3 + c4 + c5 + c6 + c7;
        
        ll total_A = c1;
        ll total_B = c2;
        ll total_C = c3;
        
        // Assign pile c4 (AB)
        if (total_A <= total_B) {
            total_A += c4;
        } else {
            total_B += c4;
        }
        // Assign pile c5 (AC)
        if (total_A <= total_C) {
            total_A += c5;
        } else {
            total_C += c5;
        }
        // Assign pile c6 (BC)
        if (total_B <= total_C) {
            total_B += c6;
        } else {
            total_C += c6;
        }
        // Assign pile c7 (ABC)
        if (total_A <= total_B && total_A <= total_C) {
            total_A += c7;
        } else if (total_B <= total_A && total_B <= total_C) {
            total_B += c7;
        } else {
            total_C += c7;
        }
        
        ll loads_A = (total_A + k - 1) / k;
        ll loads_B = (total_B + k - 1) / k;
        ll loads_C = (total_C + k - 1) / k;
        
        ll total_loads = loads_A + loads_B + loads_C;
        cout << total_loads << endl;
    }
    return 0;
}
