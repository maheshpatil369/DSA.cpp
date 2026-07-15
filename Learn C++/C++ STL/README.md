# C++ STL (Standard Template Library) - Beginner Notes

# What is STL?

STL (Standard Template Library) is a collection of ready-made classes and functions that help you write efficient C++ programs.

It has **4 main parts**:

```
                C++ STL
                   |
     --------------------------------
     |            |         |        |
 Containers   Algorithms  Iterators Functions(Functors)
```

---

# 1. Containers 📦

## What is a Container?

A **Container** stores data.

Think of it like a box.

Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10,20,30};

    for(int x : v)
        cout << x << " ";
}
```

Output

```
10 20 30
```

## Common Containers

| Container | Purpose |
|-----------|---------|
| vector | Dynamic Array |
| pair | Store two values |
| deque | Double-ended queue |
| list | Doubly Linked List |
| stack | LIFO |
| queue | FIFO |
| priority_queue | Heap |
| set | Sorted Unique Elements |
| multiset | Sorted Duplicate Elements |
| map | Sorted Key-Value Pair |
| unordered_set | Hash Set |
| unordered_map | Hash Map |

---

# 2. Algorithms ⚡

Algorithms are ready-made functions.

Instead of writing your own sorting code, STL already provides it.

## sort()

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v = {4,2,5,1};

    sort(v.begin(), v.end());

    for(int x : v)
        cout << x << " ";
}
```

Output

```
1 2 4 5
```

---

## reverse()

```cpp
reverse(v.begin(), v.end());
```

---

## find()

```cpp
auto it = find(v.begin(), v.end(), 5);

if(it != v.end())
    cout<<"Found";
else
    cout<<"Not Found";
```

---

## count()

```cpp
vector<int> v = {1,2,2,3,2};

cout << count(v.begin(), v.end(), 2);
```

Output

```
3
```

---

## max_element()

```cpp
cout << *max_element(v.begin(), v.end());
```

---

## min_element()

```cpp
cout << *min_element(v.begin(), v.end());
```

---

## binary_search()

Vector must be sorted.

```cpp
sort(v.begin(),v.end());

if(binary_search(v.begin(),v.end(),5))
    cout<<"Present";
```

---

## lower_bound()

First position where value can appear.

```cpp
auto it = lower_bound(v.begin(),v.end(),5);

cout << it-v.begin();
```

---

## upper_bound()

First element greater than value.

```cpp
auto it = upper_bound(v.begin(),v.end(),5);

cout << it-v.begin();
```

---

## next_permutation()

```cpp
vector<int> v={1,2,3};

next_permutation(v.begin(),v.end());

for(int x:v)
    cout<<x<<" ";
```

Output

```
1 3 2
```

---

# 3. Iterators 👉

## What is an Iterator?

Iterator is like a pointer.

It helps move through a container.

```
10 20 30 40
 ^
begin()
```

Move iterator

```cpp
it++;
```

Now

```
10 20 30 40
    ^
```

---

## Example

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v={10,20,30};

    vector<int>::iterator it=v.begin();

    cout<<*it<<endl;

    it++;

    cout<<*it<<endl;
}
```

Output

```
10
20
```

---

## Important Iterator Functions

```cpp
begin()

end()

rbegin()

rend()
```

---

# 4. Function Objects (Functors) 🎯

A Functor is an object that behaves like a function.

Mostly used with algorithms.

---

## greater<int>()

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    vector<int> v={4,2,5,1};

    sort(v.begin(),v.end(),greater<int>());

    for(int x:v)
        cout<<x<<" ";
}
```

Output

```
5 4 2 1
```

---

## less<int>()

Ascending order

```cpp
sort(v.begin(),v.end(),less<int>());
```

---

## Custom Functor

```cpp
class Compare{

public:

    bool operator()(int a,int b){

        return a>b;
    }

};
```

Usage

```cpp
sort(v.begin(),v.end(),Compare());
```

---

# How All Four Work Together

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    vector<int> v={5,2,9,1};

    sort(v.begin(),v.end(),greater<int>());

    for(int x:v)
        cout<<x<<" ";
}
```

Output

```
9 5 2 1
```

Explanation

- Container → vector stores data
- Iterator → begin() and end() tell where data starts and ends
- Algorithm → sort() sorts the data
- Functor → greater<int>() changes sorting to descending order

---

# Quick Revision Table

| STL Part | Meaning | Examples |
|----------|---------|----------|
| Containers | Store data | vector, map, set |
| Algorithms | Perform operations | sort, reverse, find |
| Iterators | Traverse containers | begin, end |
| Functors | Change algorithm behavior | greater<int>(), less<int>() |

---

# Best Learning Order

1. vector
2. pair
3. stack
4. queue
5. deque
6. priority_queue
7. set
8. multiset
9. unordered_set
10. map
11. unordered_map
12. Iterators
13. Algorithms
14. Functors
15. Lambda Functions

---

# Interview Tip

Remember this sentence:

> **Container stores data, Iterator accesses data, Algorithm processes data, and Functor customizes the processing.**
