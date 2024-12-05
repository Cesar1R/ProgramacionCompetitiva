//https://codeforces.com/problemset/problem/1934/B

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e9; // Practical limit for DP

vector<int> coins = {1, 3, 6, 10, 15};

// DP array to store the minimum coins needed for values up to MAXN
vector<int> dp(MAXN + 1, INF);

void initializeDP() {
    dp[0] = 0; // Base case

    for (int i = 1; i <= MAXN; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initializeDP(); // Precompute DP table

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}
