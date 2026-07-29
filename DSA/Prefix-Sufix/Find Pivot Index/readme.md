# LeetCode 724. Find Pivot Index

## Problem
Given an integer array `nums`, return the **pivot index**.

A pivot index is an index where:

- Sum of all elements to the **left** = Sum of all elements to the **right**
- Leftmost pivot index should be returned.
- If no pivot exists, return `-1`.

---

## Approach (Prefix Sum)

### Idea
Instead of calculating the left and right sums for every index (which would take O(n²)), we:

1. Calculate the **total sum** of the array.
2. Maintain a variable `leftSum`.
3. Traverse the array.
4. For every index:
   - Compute the right sum using:
     ```
     rightSum = totalSum - leftSum - nums[i]
     ```
   - If `leftSum == rightSum`, return the current index.
   - Otherwise, add the current element to `leftSum`.

---

## Why does the formula work?

For every index `i`,

```
Total Sum = Left Sum + nums[i] + Right Sum
```

Rearranging,

```
Right Sum = Total Sum - Left Sum - nums[i]
```

So, we don't need to calculate the right sum separately every time.

---

## Algorithm

1. Find the total sum of the array.
2. Initialize `leftSum = 0`.
3. Traverse the array.
4. Compute:
   ```
   rightSum = totalSum - leftSum - nums[i]
   ```
5. If
   ```
   leftSum == rightSum
   ```
   return `i`.
6. Otherwise,
   ```
   leftSum += nums[i]
   ```
7. If no pivot index is found, return `-1`.

---

## Dry Run

### Input

```
nums = [1,7,3,6,5,6]
```

### Step 1

```
totalSum = 28
leftSum = 0
```

| i | nums[i] | leftSum | rightSum | Pivot? |
|---|---------|---------|----------|--------|
|0|1|0|28-0-1 = 27|No|
| |Update leftSum|1|||
|1|7|1|28-1-7 = 20|No|
| |Update leftSum|8|||
|2|3|8|28-8-3 = 17|No|
| |Update leftSum|11|||
|3|6|11|28-11-6 = 11|✅ Yes|

Since

```
Left Sum = 11
Right Sum = 11
```

Return

```
3
```

---

## Example 2

```
nums = [1,2,3]
```

```
totalSum = 6
```

| i | leftSum | rightSum | Result |
|---|---------|----------|--------|
|0|0|5|No|
|1|1|3|No|
|2|3|0|No|

No pivot exists.

Return

```
-1
```

---

## C++ Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - One pass to calculate total sum.
  - One pass to find the pivot.

- **Space Complexity:** `O(1)`
  - Only two extra variables (`totalSum` and `leftSum`) are used.

---

## Key Revision Points

- Compute **total sum** first.
- Maintain a running **leftSum**.
- Calculate:
  ```
  rightSum = totalSum - leftSum - nums[i]
  ```
- If
  ```
  leftSum == rightSum
  ```
  return the current index.
- Update `leftSum` **after** checking the condition.
- **Time:** `O(n)`
- **Space:** `O(1)`