#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
bool compareItems(Item item1, Item item2) {
    double ratio1 = (double)item1.value / item1.weight;
    double ratio2 = (double)item2.value / item2.weight;
    return ratio1 > ratio2;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(vector<Item>& items, int capacity) {
    // Sort the items based on their value-to-weight ratio in non-increasing order
    sort(items.begin(), items.end(), compareItems);

    double max_value = 0.0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            max_value += item.value;
            capacity -= item.weight;
        } else {
            // Take a fraction of the item to fill the knapsack to its capacity
            max_value += ((double)capacity / item.weight) * item.value;
            break;
        }
    }

    return max_value;
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double max_value = fractionalKnapsack(items, capacity);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}