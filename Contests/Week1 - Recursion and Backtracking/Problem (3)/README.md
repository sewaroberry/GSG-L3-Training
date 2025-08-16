# Mountain Ski

## Problem Statement
A ski resort in Italy hosts a slalom competition. Every participant skis down a mountain, earning points at each section of the path. The mountain is represented as a triangle of integers.  

- At each step, the participant may move **down-left** or **down-right** to the next layer.  
- The total score is the sum of all points collected along the chosen path.  
- The participant starts at the top of the mountain and may finish at any cell in the last layer.  

Your task is to determine the **maximum score** a participant can achieve.  

---

## Input  
- The first line contains an integer `n` — the number of layers in the triangle.  
- The following `n` lines contain the values of the triangle.  
  - The `i`-th line contains exactly `i` integers, representing the points in that row of the triangle.  

---

## Output  
- Print a single integer — the maximum score that one can achieve.  

---

## Example  
### Input  
4
1
4 3
5 6 7
8 9 0 9


### Output  
20


**Explanation:**  
One optimal path is: `1 → 4 → 6 → 9 = 20`.

---

## Approach  
- Use **recursion with backtracking** or **dynamic programming**.  
- From each cell `(x, y)`, you can move to:  
  - `(x + 1, y)` → down-left  
  - `(x + 1, y + 1)` → down-right  
- Define a recursive relation:  


f(x, y) = A[x][y] + max(f(x+1, y), f(x+1, y+1))  

- Base case: if `x` exceeds the number of rows, return `0`.  
- Start from the top `(0, 0)` and compute the maximum path sum.  

---

## Complexity  
- **Time Complexity:**  
- Naive recursion: `O(2^n)` (exploring both left/right paths).  
- With memoization / DP: `O(n^2)`.  
- **Space Complexity:** `O(n^2)` for storing the triangle and memoization table.  

---

## Notes  
- Since `n ≤ 20` in the problem constraints, even the recursive solution without memoization will run within the time limit.  
- However, dynamic programming provides an efficient bottom-up approach and is preferred for larger constraints.  
