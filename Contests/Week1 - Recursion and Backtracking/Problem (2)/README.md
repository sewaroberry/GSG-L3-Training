# K. Word Search

## Problem Statement  
You are given an `n × m` grid of lowercase English letters and a target word `w`.  
Your task is to determine whether `w` can be found in the grid by starting from any cell and moving to neighboring cells one letter at a time.

- You may move **up, down, left, or right** at each step.  
- You cannot leave the grid.  
- You cannot visit the same cell more than once while forming the word.  

---

## Input  
- The first line contains two integers `n` and `m` (`1 ≤ n, m ≤ 20`).  
- The next `n` lines each contain exactly `m` lowercase English letters, representing the grid.  
- The last line contains the target word `w` (`1 ≤ |w| ≤ n × m`).  

---

## Output  
- Print `YES` if the word can be found in the grid.  
- Print `NO` otherwise.  

---

## Examples  

### Example 1  
**Input**  
3 4
abce
sfcg
adgs
gsg  
  
**Output**  
YES  
  
---

## Approach  
- Use **Depth-First Search (DFS)** with backtracking.  
- Start from every cell in the grid and try to build the word letter by letter.  
- At each step:
  - Check boundaries of the grid.  
  - Ensure the current cell matches the required character in the word.  
  - Mark the cell as visited to prevent revisiting.  
  - Recursively move **up, down, left, or right** to match the next character.  
  - Backtrack by unmarking the cell after exploring all paths.  
- If the full word is matched, return `YES`; otherwise, if no path works, return `NO`.  

---

## Complexity  
- **Time Complexity:** `O(n × m × 4^L)` where `L = |w|` (since each step has up to 4 moves).  
- **Space Complexity:** `O(n × m)` for the visited matrix + recursion stack.  

---

## Notes  
- Since `n, m ≤ 20`, the grid is at most `400` cells, so the recursive solution runs within the time limits.  
- The word length is bounded by `n × m`, so recursion depth is safe.  
