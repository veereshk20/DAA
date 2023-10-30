#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the value and weight for item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int max_value = knapsack(values, weights, capacity);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
