#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n'

int N = 8;
vector<int> row(8, -1);
int countSolutions = 0; // Counter for valid arrangements

bool ok() {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(row[i] != -1 && row[j] != -1) {
                if(row[i] == row[j]) return false; // Same column
                if(abs(i - j) == abs(row[i] - row[j])) return false; // Same diagonal
            }
        }
    }
    return true;
}

void recur(int r) {
    if(r == N) {
        countSolutions++; // Found a valid arrangement
        return;
    }
    for(int i = 0; i < N; i++) { // Place queen in row r
        row[r] = i;
        if(ok()) recur(r + 1);
        row[r] = -1; // Backtrack
    }
}

void solve() {
    cin >> N; // Read board size
    row.assign(N, -1); // Resize row vector
    countSolutions = 0;
    recur(0);
    cout << countSolutions << endl; // Only output total number of solutions
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}