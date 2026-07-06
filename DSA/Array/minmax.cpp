#include <iostream>
#include <climits>
using namespace std;

// Function to find minimum element
int getMin(int num[], int n) {
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        mini = min(mini, num[i]);
    }

    return mini;
}

// Function to find maximum element
int getMax(int num[], int n) {
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, num[i]);
    }

    return maxi;
}

int main() {
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    int num[100];

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }

    cout << "Maximum value is: " << getMax(num, size) << endl;
    cout << "Minimum value is: " << getMin(num, size) << endl;

    return 0;
}