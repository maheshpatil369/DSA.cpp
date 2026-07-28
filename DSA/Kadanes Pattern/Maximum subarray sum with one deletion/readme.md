# 1186. Maximum Subarray Sum with One Deletion

## Problem Statement

Given an integer array, find the **maximum subarray sum**.

You are allowed to **delete at most one element** from the chosen subarray.

> **Important:** After deletion, the subarray must still contain at least one element.

---

# Example

```text
arr = [1, -2, 0, 3]
```

Without deletion:

```text
1 + (-2) + 0 + 3 = 2
```

If we delete `-2`:

```text
1 + 0 + 3 = 4
```

Answer:

```text
4
```

---

# Normal Kadane's Algorithm

Normally, Kadane's algorithm asks:

> What is the maximum subarray sum ending at the current index?

For every index we store only **one value**.

Example:

```text
arr = [1, -2, 3]
```

At `3`:

Either

* Start a new subarray from `3`
* Continue the previous subarray

That's why Kadane uses:

```cpp
keep = max(arr[i], keep + arr[i]);
```

---

# Why Doesn't Kadane Work Here?

Now we are allowed **one deletion**.

Consider:

```text
arr = [1, -2, 3]
```

At index `3`, there are **two different situations**.

### Situation 1

You have **not deleted anything yet**.

Current sum:

```text
1 + (-2) = -1
```

Add `3`:

```text
-1 + 3 = 2
```

---

### Situation 2

You already deleted `-2`.

Current sum becomes:

```text
1
```

Now add `3`:

```text
1 + 3 = 4
```

Notice:

At the same index we have

```text
Without deletion = 2

With deletion = 4
```

One variable cannot store both answers.

That's why we need **two states**.

---

# Two DP States

## 1. keep

Meaning:

> Maximum subarray sum ending at current index **without using deletion**.

You can still delete an element later.

---

## 2. del

Meaning:

> Maximum subarray sum ending at current index **after using one deletion**.

Deletion has already been used.

---

# Think Like Two Players

Imagine two players walking through the array.

## Player 1 (keep)

"I haven't used my delete coupon yet."

---

## Player 2 (del)

"I already used my delete coupon."

At every element, both players update their scores.

---

# Transition for keep

Exactly Kadane.

Two choices:

### Choice 1

Start a new subarray.

```text
arr[i]
```

### Choice 2

Continue previous subarray.

```text
keep + arr[i]
```

Formula:

```cpp
newKeep = max(arr[i], keep + arr[i]);
```

---

# Transition for del

This is the important part.

There are only **two possibilities**.

---

## Option 1 : Delete Current Element

Suppose

```text
5   -100
     ↑
```

If we delete `-100`

Remaining subarray:

```text
5
```

Which is exactly the previous **keep**.

So

```cpp
newDel = keep;
```

Meaning:

> Use the deletion on the current element.

---

## Option 2 : Deletion Was Already Used

Example:

```text
5   X   7
```

`X` means one element was deleted earlier.

Current element `7` cannot be deleted again.

Simply add it.

```cpp
newDel = del + arr[i];
```

---

Take the better option.

```cpp
newDel = max(
    keep,
    del + arr[i]
);
```

---

# Dry Run

Array:

```text
arr = [1, -2, 0, 3]
```

Initially

```text
keep = 1
del = 0
ans = 1
```

---

## Index = 1

Current element

```text
-2
```

### keep

```text
max(-2, 1 + (-2))

= -1
```

### del

Delete current element

```text
keep = 1
```

Already deleted earlier

```text
0 + (-2) = -2
```

Take maximum

```text
del = 1
```

State:

| keep | del |
| ---- | --- |
| -1   | 1   |

---

## Index = 2

Current element

```text
0
```

### keep

```text
max(0, -1 + 0)

= 0
```

### del

Delete current

```text
keep(previous)

= -1
```

Already deleted

```text
1 + 0

= 1
```

Take maximum

```text
del = 1
```

State:

| keep | del |
| ---- | --- |
| 0    | 1   |

---

## Index = 3

Current element

```text
3
```

### keep

```text
max(3, 0 + 3)

= 3
```

### del

Delete current

```text
0
```

Already deleted

```text
1 + 3

= 4
```

Take maximum

```text
del = 4
```

State:

| keep | del |
| ---- | --- |
| 3    | 4   |

Final answer:

```text
4
```

---

# Workflow

```text
                 arr[i]
                    |
        -----------------------
        |                     |
    No deletion         One deletion
      (keep)               (del)

keep:
Start new
OR
Continue previous

del:
Delete current
OR
Deletion already used
```

---

# Code

```cpp
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int keep = arr[0];
        int del = 0;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int newDel = max(keep, del + arr[i]);

            int newKeep = max(arr[i], keep + arr[i]);

            keep = newKeep;
            del = newDel;

            ans = max(ans, max(keep, del));
        }

        return ans;
    }
};
```

---

# Time Complexity

```text
O(n)
```

We visit every element exactly once.

---

# Space Complexity

```text
O(1)
```

Only three variables are used.

---

# Easy Way to Remember

At every index, ask only **two questions**:

### Question 1

**If I haven't used my deletion yet, what is the best sum?**

→ `keep`

---

### Question 2

**If I have already used my deletion, what is the best sum?**

→ `del`

For `del`, there are only **two choices**:

1. Delete the current element → `keep`
2. Deletion already happened earlier → `del + arr[i]`

That's the complete logic of the solution.
