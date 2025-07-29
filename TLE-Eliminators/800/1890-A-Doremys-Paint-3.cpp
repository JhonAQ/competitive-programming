#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> list(n, 0);
        while(n--){
            int a; cin >> a;
            list[a]++;
        }

        if(list.size() == 1){
            cout << "Yes" << endl;
            continue;
        }

        if(list.size() != 2){
            cout << "No" << endl;
            continue;
        }

        auto it = list.begin();
        int a = *it;
        int b = *next(it);

        if(abs(a - b) == 1){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
