#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define endl '\n'

int N;
vector <vector <int>> A;

int recur(int x, int y) {
    if(x >= N) return 0;
    if(y >= x + 1) return 0;

    // Left
    int choice1 = recur(x + 1, y);

    // Right
    int choice2 = recur(x + 1, y + 1);

    return A[x][y] + max(choice1, choice2);
}

void solve() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        vector <int> temp;
        for(int j = 0; j < i + 1; j++) {
            int a;
            cin >> a;

            temp.push_back(a);
        }
        A.push_back(temp);
    }

    cout << recur(0, 0);
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