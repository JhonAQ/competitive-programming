#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long n;
        int d;
        cin >> n >> d;

        vector<int> ans;
        ans.push_back(1);

        if(n >= 3) {
            ans.push_back(3);
        } else { // n == 2
            if(d == 3 || d == 6 || d == 9) {
                ans.push_back(3);
            }
        }

        if(d == 5) ans.push_back(5);

        if(n >= 3) {
            ans.push_back(7);
        } else {
            if(d == 7) {
                ans.push_back(7);
            }
        }

        if(n >= 6){
            ans.push_back(9);
        } else {
            if(n == 2) {
                if(d == 9) ans.push_back(9);
            } else if(n == 3) {
                if(d == 3 || d == 6 || d == 9) ans.push_back(9);
            } else if(n == 4) {
                if(d == 3 || d == 6 || d == 9) ans.push_back(9);
            } else if(n == 5) {
                if(d == 3 || d == 6 || d == 9) ans.push_back(9);
            }
        }

        for(int x: ans){
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
