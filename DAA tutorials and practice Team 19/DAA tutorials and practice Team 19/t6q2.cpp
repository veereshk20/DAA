//Here we exploit the optiised solution with memoised DP
#include<bits/stdc++.h>
using namespace std;

int maxCoinsHelper(vector<int>& pots, int i, int j, vector<vector<int>>& memo)
{
    if (i > j) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    int pickLeft = pots[i] + min(maxCoinsHelper(pots, i+2, j, memo), maxCoinsHelper(pots, i+1, j-1, memo));
    int pickRight = pots[j] + min(maxCoinsHelper(pots, i+1, j-1, memo), maxCoinsHelper(pots, i, j-2, memo));

    memo[i][j] = max(pickLeft, pickRight);
    return memo[i][j];
}

int maxCoins(vector<int>& pots)
{
    int n = pots.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return maxCoinsHelper(pots, 0, n-1, memo);
}

int main()
{
    vector<int> pots = {5, 7, 3, 4};
    int max_coins = maxCoins(pots);

    cout << "Maximum number of coins: " << max_coins << endl;

    return 0;
}