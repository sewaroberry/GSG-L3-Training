# Rabbit

## Problem Statement  
A rabbit jumps along a line of `n` cells numbered from **1 to n**. Each cell can be one of the following:
- **Swamp (`w`)**: The rabbit cannot land on this cell.  
- **Grass (`"`)**: The rabbit can land here and eat the grass, increasing its grass counter by **1**.  
- **Empty (`.`)**: The rabbit can land here, but nothing happens.  

The rabbit:  
- Always starts at cell `1` and wants to reach cell `n`.  
- Can only jump **1, 3, or 5 cells to the right** in a single move.  
- Cells `1` and `n` are guaranteed to be **empty (`.`)**, meaning they contain neither swamps nor grass.  

Your task is to determine the **maximum number of grass cells** the rabbit can eat on a valid path from cell `1` to cell `n`.  
If the rabbit cannot reach cell `n`, output **-1**.

---

## Input  
- The first line contains an integer `n` (`2 ≤ n ≤ 15`).  
- The second line contains a string `w` of length `n`, describing the cells:  
  - `'w'` → swamp  
  - `'"'` → grass  
  - `'.'` → empty  

You may assume:
- `w[0] = '.'` (first cell is empty)  
- `w[n-1] = '.'` (last cell is empty)  

---

## Output  
- Print **one integer** — the maximum number of grass cells the rabbit can eat on a valid path from `1` to `n`, or `-1` if it is impossible.  

---

## Examples  
### Example 1  
**Input**  
7
."w.".".

**Output**  
3

**Explanation:**  
Path: `1 → 2 (grass) → 4 (grass) → 6 (grass) → 7`.  
The rabbit eats 3 grass cells.

---

### Example 2  
**Input**  
6
.w"w".

**Output**  
0

yaml
Copy
Edit

**Explanation:**  
Path: `1 → 4 → 6`.  
The rabbit avoids swamps but lands only on empty cells.  

---

### Example 3  
**Input**  
7
.wwwww.

**Output**  
-1

**Explanation:**  
There is no possible way to reach cell `7` without landing on swamps.  

---

## Approach  
This problem can be solved using **recursion with backtracking** or **dynamic programming**:

1. Define a recursive function `f(pos)` that represents the maximum grass collected starting from position `pos`.  
2. From each cell, the rabbit can attempt jumps of length **1, 3, or 5**.  
3. If the next cell is a swamp (`w`), skip it.  
4. If it’s grass (`"`), add +1 to the result and continue recursion.  
5. Use memoization to avoid recomputation.  
6. If no valid path leads to the last cell, return `-1`.  

---

## Complexity  
- **Time Complexity:** `O(n * 3)` → since for each position the rabbit considers 3 jumps.  
- **Space Complexity:** `O(n)` for recursion and memoization.  

Since `n ≤ 15`, recursion without memoization is also feasible within the time limit.  