#include <bits/stdc++.h>

using namespace std;

int toggleBinNum(unsigned int num) {
    int totalBits = 32;
    for (int i = totalBits - 1; i >= 0; --i) {
        num ^= (1<<i);
    }
    return num;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        unsigned int num;
        cin >> num;
        unsigned int res = toggleBinNum(num);
        cout << res << endl;
    }
    return 0;
}