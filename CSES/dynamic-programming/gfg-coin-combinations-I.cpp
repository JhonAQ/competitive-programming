#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// function to find the number of distinct ways to make sum
// = X
ll solve(ll N, ll X, vector<ll>& coins)
{
    // dp[] array such that dp[i] stores the number of
    // distinct ways to make sum = i
    ll dp[X + 1] = {};

    // There is only 1 way to make sum = 0, that is to not
    // select any coin
    dp[0] = 1;

    // Iterate over all possible sums from 1 to X
    for (int i = 1; i <= X; i++) {
        // Iterate over all the N coins
        for (int j = 0; j < N; j++) {
            // Check if it is possible to have jth coin as
            // the last coin to construct sum = i
            if (coins[j] > i)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
    // Return the number of ways to make sum = X
    return dp[X];
}

int main()
{
    // Sample Input
    ll N , X; cin >> N >> X;
    vector<ll> coins;
    for(int i = 0; i < N; i++){
      int c; cin >> c;
      coins.push_back(c);
    }

    cout << solve(N, X, coins) << "\n";
}
