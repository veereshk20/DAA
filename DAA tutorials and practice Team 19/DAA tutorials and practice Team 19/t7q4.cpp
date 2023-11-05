#include <bits/stdc++.h>
using namespace std;

int minCoins(int x, vector<int> denominations, vector<int> limits) {
    int n = denominations.size();
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, INT_MAX));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 0; k <= min(limits[i - 1], j / denominations[i - 1]); k++) {
                if (dp[i - 1][j - k * denominations[i - 1]] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k * denominations[i - 1]] + k);
                }
            }
        }
    }

    if (dp[n][x] == INT_MAX) {
        return -1;
    } else {
        return dp[n][x];
    }
}

int main() {
    int n, x;
    vector<int> denominations;
    vector<int> limits;

    cout << "Enter the number of denominations: ";
    cin >> n;

    cout << "Enter the denomination and limit pairs (e.g., denomination limit): ";
    for (int i = 0; i < n; i++) {
        int d, l;
        cin >> d >> l;
        denominations.push_back(d);
        limits.push_back(l);
    }

    cout << "Enter the change amount: ";
    cin >> x;

    int minCoinsRequired = minCoins(x, denominations, limits);

    if (minCoinsRequired == -1) {
        cout << "It's not possible to make change for the given amount." << endl;
    } else {
        cout << "Minimum number of coins required: " << minCoinsRequired << endl;
    }

    return 0;
}