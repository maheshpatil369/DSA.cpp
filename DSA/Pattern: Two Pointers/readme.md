# ✌️ Pattern: Two Pointers — Cheat Sheet & Revision Guide

The **Two Pointers** pattern is a highly efficient algorithmic technique used to process linear data structures like Arrays and Strings. By using two reference markers moving across the collection, it typically optimizes a brute-force $O(N^2)$ nested-loop approach down to a linear $O(N)$ time complexity.

---

## 🧠 Core Strategy & Key Signals

### When to use it?
* The data structure is **sorted** (or can be sorted easily).
* You need to find pairs, triplets, or subsegments satisfying a specific condition.
* You need to manipulate elements in-place without using extra space (e.g., swapping or removing).

### Pointer Behaviors
1. **Opposite Ends:** One pointer at the start (`left = 0`) and one at the end (`right = n - 1`). They converge toward the middle.
2. **Fast & Slow:** Both pointers start at the same end but move at different paces (`slow++` vs `fast += 2` or conditional increments).

---

## 🛠️ Topic-by-Topic Revision Summary

### 1. Pair with Target Sum
* **Core Idea:** Find a pair in a *sorted* array whose sum equals a given target.
* **Key Trick:** Initialize `left = 0` and `right = n - 1`. If the current sum is too small, shift `left++` to increase it. If the sum is too large, shift `right--` to decrease it.

### 2. Remove Duplicates
* **Core Idea:** Modify a sorted array in-place to shift unique elements to the front and return the unique count.
* **Key Trick:** Use a Fast and Slow pointer setup. `slow` tracks the placement index for the next unique element, while `fast` iterates through the array. Whenever `arr[fast] != arr[slow - 1]`, move the element to `slow` and increment `slow`.

### 3. Square of a Sorted Array
* **Core Idea:** Given an array sorted in ascending order (including negative numbers), return an array of the squares sorted in ascending order.
* **Key Trick:** The largest squares always exist at the extreme ends (due to negative values). Place pointers at `left = 0` and `right = n - 1`. Compare the squared values, place the larger one at the *end* of your results array, and step that pointer inward.

### 4. Three Sum (3Sum)
* **Core Idea:** Find all unique triplets in an array that sum up to zero (or a target).
* **Key Trick:** Sort the array first. Loop through the array, fixing one element `i`. Then, treat the remaining part of the array as a classic **Pair with Target Sum** problem using `left = i + 1` and `right = n - 1`. 
* *Crucial:* Skip duplicate values for `i`, `left`, and `right` to prevent tracking duplicate triplets.

### 5. Subarray Product Less Than Target
* **Core Idea:** Count the total number of contiguous subarrays where the product of elements is strictly less than a target value.
* **Key Trick:** This is a crossover between Two Pointers and a **Sliding Window**. Expand the window using a `right` pointer. If the product exceeds the target, shrink it from the `left` until it fits. The number of valid new subarrays introduced by `right` is exactly `(right - left + 1)`.

### 6. Merge Sorted Array
* **Core Idea:** Merge two pre-sorted arrays into a single sorted array.
* **Key Trick:** If merging in-place to the end of the first array, process items from **right to left** (largest to smallest). Compare the last elements of both arrays and place the larger element at the very back to avoid overwriting your initial array data.

### 7. Dutch National Flag Problem (Sort Colors)
* **Core Idea:** Sort an array containing only `0`s, `1`s, and `2`s in a single pass without using sorting libraries.
* **Key Trick:** Use **Three Pointers**: `low` (boundary for 0s), `mid` (current element runner), and `high` (boundary for 2s). 
  * If `arr[mid] == 0`: Swap `arr[low]` and `arr[mid]`, increment both `low++` and `mid++`.
  * If `arr[mid] == 1`: Leave it, just `mid++`.
  * If `arr[mid] == 2`: Swap `arr[mid]` and `arr[high]`, decrement `high--` (do *not* increment `mid` yet, as the swapped element needs to be checked).

---

## 🚀 Speed Run Code Boilerplate (Opposite Ends)

```cpp
void solveTwoPointer(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];
        
        if (current_sum == target) {
            // Found the match! Handle logic here
            return;
        } 
        else if (current_sum < target) {
            left++; // Need a larger sum
        } 
        else {
            right--; // Need a smaller sum
        }
    }
}