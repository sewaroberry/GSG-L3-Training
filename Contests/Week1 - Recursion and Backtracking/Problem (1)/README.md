# N-Queens Problem (Counting Solutions)

## Problem Statement
Place `N` queens on an `N × N` chessboard such that no two queens attack each other.  
Queens attack in the same **row**, **column**, or **diagonal**.  

Your task is to **count the total number of valid arrangements** using recursion.

---

## Input  
- A single integer `N` (size of the chessboard).  

---

## Output  
- A single integer: the **number of valid arrangements** of queens.  

---

## Example  
### Input  
4  

### Output  
2  


Explanation:  
There are **2 valid ways** to place 4 queens on a 4×4 board without attacking each other.

---

## Approach
The solution uses **backtracking** with recursion:
1. Place queens row by row.
2. For each row, try placing a queen in every column.
3. Check if the current placement is valid:
   - No two queens share the same column.
   - No two queens share the same diagonal.
   - Note: It's sure that no two queens share the same row.
4. If valid, continue to the next row.
5. If all rows are filled, increment the solution counter.
6. Use backtracking to explore all possible placements.