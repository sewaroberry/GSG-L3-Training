#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n'

int N;
string S;
vector<int> ans;

int recur(int index) {
    if(index >= N) return LLONG_MIN;
    if(S[index] == 'w') return LLONG_MIN;
    if(index == N - 1) return 0;

    if(ans[index] != -1) return ans[index]; 

    int temp = LLONG_MIN;

    // Step 1
    if(index + 1 < N) {
        int choice1 = recur(index + 1);
        if(choice1 != LLONG_MIN) temp = max(temp, choice1 + (S[index + 1] == '"' ? 1 : 0));
    }

    // Step 2
    if(index + 3 < N) {
        int choice2 = recur(index + 3);
        if(choice2 != LLONG_MIN) temp = max(temp, choice2 + (S[index + 3] == '"' ? 1 : 0));
    }

    // Step 3
    if(index + 5 < N) {
        int choice3 = recur(index + 5);
        if(choice3 != LLONG_MIN) temp = max(temp, choice3 + (S[index + 5] == '"' ? 1 : 0));
    }

    ans[index] = temp;
    return temp;
}

void solve() {
    cin >> N >> S;
    ans = vector<int>(N, -1);

    int flag = recur(0);
    if(flag < 0) cout << -1 << endl;
    else cout << flag << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}