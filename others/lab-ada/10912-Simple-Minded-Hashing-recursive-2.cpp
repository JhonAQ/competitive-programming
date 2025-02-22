#include <bits/stdc++.h>
using namespace std;

long long memo[27][351][27];
bool computedFlag[27][351][27];

long long dp(int L, int S, int start) {
    if(L == 0 && S == 0)
        return 1;
    if(L == 0 || S <= 0 || start > 26)
        return 0;
    if(computedFlag[L][S][start])
        return memo[L][S][start];
    
    long long count = 0;
    for(int i = start; i <= 26; ++i){
        if(S - i >= 0){
            count += dp(L - 1, S - i, i + 1);
        }
    }
    memo[L][S][start] = count;
    computedFlag[L][S][start] = true;
    return count;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(computedFlag, false, sizeof(computedFlag));
    
    int L, S;
    int caseNum = 1;
    while(cin >> L >> S){
        if(L == 0 && S == 0)
            break;
        if(L <= 0 || L > 26){
            cout << "Case " << caseNum++ << ": " << 0 << "\n";
            continue;
        }
        int minSum = L*(L+1)/2;
        int maxSum = L*(53 - L)/2;
        if(S < minSum || S > maxSum){
            cout << "Case " << caseNum++ << ": " << 0 << "\n";
            continue;
        }
        long long result = dp(L, S, 1);
        cout << "Case " << caseNum++ << ": " << result << "\n";
    }
    return 0;
}
