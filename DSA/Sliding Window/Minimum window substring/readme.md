# LeetCode 76 - Minimum Window Substring

## Problem Statement

Given two strings:

- `s` = Main string
- `t` = Required string

Find the **smallest substring of `s`** that contains **all the characters of `t` (including duplicates)**.

Example:

```text
s = "ADOBECODEBANC"
t = "ABC"

Answer = "BANC"
```

---

# Intuition (Very Simple)

Think of it like shopping.

Suppose your shopping list is:

```text
A
B
C
```

Now you walk through a long market.

```text
A D O B E C O D E B A N C
```

Your goal is to find the **smallest continuous part** where you can collect:

- A
- B
- C

Whenever you collect all of them,

**don't stop.**

Try to make your basket (window) **smaller**.

This is exactly what Sliding Window does.

---

# Sliding Window

We use two pointers.

```text
low  -> Left side of window
high -> Right side of window
```

Initially

```text
A D O B E C O D E B A N C
^
low
^
high
```

The window is

```text
A
```

Move `high` to make the window bigger.

Move `low` to make the window smaller.

---

# Variables Used

```cpp
vector<int> need(128,0);
```

Stores how many characters are still needed.

Example

```text
t = "ABC"
```

Then

```text
need['A']=1
need['B']=1
need['C']=1
```

---

```cpp
count = t.size();
```

This tells us

> **How many required characters are still missing?**

Initially

```text
Need

A
B
C

count = 3
```

---

# Dry Run

```
s = ADOBECODEBANC
t = ABC
```

Initially

```text
need

A=1
B=1
C=1

count=3
```

---

## high = 0

Character = A

```cpp
if(need['A']>0)
    count--;
```

Need

```text
A=1
```

A was required.

Now

```text
count=2
```

Then

```cpp
need['A']--;
```

Need becomes

```text
A=0
```

Meaning

> We don't need A anymore.

---

## high = 1

Character = D

Need

```text
D=0
```

D is not required.

So

```text
count remains 2
```

Then

```cpp
need['D']--;
```

Need

```text
D=-1
```

Negative means

> Extra character.

---

## high = 2

Character = O

Again

```text
Need becomes

O=-1
```

Extra character.

---

## high = 3

Character = B

Need

```text
B=1
```

Required.

```text
count=1
```

Need

```text
B=0
```

---

## high = 5

Character = C

Need

```text
C=1
```

Required.

Now

```text
count=0
```

Window

```text
ADOBEC
```

Contains

```text
A ✔
B ✔
C ✔
```

Window is now VALID.

---

# Why while(count==0)?

```cpp
while(count==0)
```

Means

> Window already contains everything.

Now try to make it smaller.

Current window

```text
ADOBEC
```

Length = 6

Save answer.

---

Remove left character.

```cpp
need[s[low]]++;
```

low points to

```text
A
```

So

```text
need['A']++

A becomes 1
```

Meaning

> We now need A again.

Check

```cpp
if(need[s[low]]>0)
    count++;
```

Since

```text
need['A']=1
```

Window becomes invalid.

Now

```text
count=1
```

Stop shrinking.

Increase `high` again.

---

Eventually

Window becomes

```text
BANC
```

Contains

```text
A ✔
B ✔
C ✔
```

Length = 4

Smaller than previous answer.

Final Answer

```text
BANC
```

---

# Understanding need[]

This is the most important part.

Suppose

```text
need['A']=1
```

Means

```text
One A is still needed.
```

---

When A enters the window

```cpp
need['A']--;
```

Need becomes

```text
0
```

Meaning

```text
Requirement completed.
```

---

Another A enters.

```cpp
need['A']--;
```

Need becomes

```text
-1
```

Meaning

```text
Extra A
```

No problem.

---

When removing A

```cpp
need['A']++;
```

Need becomes

```text
0
```

Still enough A inside window.

---

Remove another A

```cpp
need['A']++;
```

Need becomes

```text
1
```

Meaning

```text
One A is missing now.
```

Window becomes invalid.

---

# Meaning of need[]

| Value | Meaning |
|--------|---------|
| > 0 | Character is still needed |
| = 0 | Requirement exactly completed |
| < 0 | Extra character is present |

---

# Understanding count

Initially

```text
Need

A
B
C

count=3
```

A found

```text
count=2
```

B found

```text
count=1
```

C found

```text
count=0
```

Whenever

```text
count==0
```

Window is VALID.

Whenever

```text
count>0
```

Window is INVALID.

---

# Complete Algorithm

```
Start

↓

Create frequency array of t

↓

count = number of required characters

↓

Move high

↓

Character needed?

↓

Yes

count--

↓

Decrease need[]

↓

count==0 ?

↓

No

Move high

↓

Yes

Save answer

↓

Increase need[low]

↓

If character becomes needed again

count++

↓

Move low

↓

Repeat
```

---

# Time Complexity

```
O(n)
```

Each character is visited at most twice.

- Once by `high`
- Once by `low`

---

# Space Complexity

```
O(1)
```

We only use a fixed-size frequency array.

---

# Code

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        int low = 0;
        int count = t.size();
        int start = 0;
        int res = INT_MAX;

        for (int high = 0; high < s.size(); high++) {

            if (need[s[high]] > 0)
                count--;

            need[s[high]]--;

            while (count == 0) {

                if (high - low + 1 < res) {
                    res = high - low + 1;
                    start = low;
                }

                need[s[low]]++;

                if (need[s[low]] > 0)
                    count++;

                low++;
            }
        }

        if (res == INT_MAX)
            return "";

        return s.substr(start, res);
    }
};
```