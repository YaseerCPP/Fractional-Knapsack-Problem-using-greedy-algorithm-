#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Comparator function to sort items by value/weight ratio
bool compare(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int currentWeight = 0;

    // Iterate through the sorted items
    for (const auto &item : items) {
        // If the entire item can be added, do so
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            maxValue += item.value;
        }
        // Otherwise, add the fraction of the item that fits
        else {
            int remain = W - currentWeight;
            maxValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int W;  // Maximum weight capacity of the knapsack
    int n;  // Number of items

    // Input number of items and maximum weight
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity: ";
    cin >> W;

    vector<Item> items(n);

    // Input weights and values of the items
    cout << "Enter weights and values of the items (weight value):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    // Solve the fractional knapsack problem
    double maxValue = fractionalKnapsack(W, items);

    // Output the maximum value that can be achieved
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
