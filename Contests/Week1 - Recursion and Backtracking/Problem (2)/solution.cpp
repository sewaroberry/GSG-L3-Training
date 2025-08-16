#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define endl '\n'

int N, M;
string Target;
vector <vector <char>> Grid;
vector <vector <bool>> visited;

bool recur(int x, int y, int index) {
    if(index == Target.size()) return true; 
    
    if(x < 0 || x >= N) return false;
    if(y < 0 || y >= M) return false;
    if(visited[x][y]) return false; // We visited this node before
    if(Grid[x][y] != Target[index]) return false; // This letter is not right for our target word

    visited[x][y] = true;

    // Up
    if(recur(x - 1, y, index + 1)) {
        visited[x][y] = false;
        return true;
    }
    // Down
    if(recur(x + 1, y, index + 1)) {
        visited[x][y] = false;
        return true;
    }
    // Left
    if(recur(x, y - 1, index + 1)) {
        visited[x][y] = false;
        return true;
    }
    // Right
    if(recur(x, y + 1, index + 1)) {
        visited[x][y] = false;
        return true;
    }

    visited[x][y] = false; // Backtracking
    return false;
}

void solve() {
    cin >> N >> M;
    
    Grid = vector <vector <char>>(N, vector <char> (M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Grid[i][j];
        }
    }
    
    cin >> Target;

    visited = vector <vector <bool>> (N, vector <bool> (M, false));
    bool found = false;

    for(int i = 0; i < N && !found; i++) {
        for(int j = 0; j < M && !found; j++) {
            if(recur(i, j, 0)) {
                found = true;
            }
        }
    }

    if(found) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}