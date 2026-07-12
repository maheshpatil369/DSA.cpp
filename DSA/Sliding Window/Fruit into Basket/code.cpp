#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;

    int low = 0;
    int result = 0;

    for (int high = 0; high < fruits.size(); high++) {
        basket[fruits[high]]++;
        while (basket.size() > 2) {
            basket[fruits[low]]--;
            if (basket[fruits[low]] == 0)
                basket.erase(fruits[low]);
            low++;
        }
        // Update maximum fruits collected
        result = max(result, high - low + 1);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of trees: ";
    cin >> n;
    vector<int> fruits(n);
    cout << "Enter fruit types:\n";
    for (int i = 0; i < n; i++)
        cin >> fruits[i];
    cout << "Maximum fruits collected = " << totalFruit(fruits);
    return 0;
}



/*
https://leetcode.com/problems/fruit-into-baskets/description/
*/