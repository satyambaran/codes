#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int did[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int djd[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l = INT_MAX, m = -1, n, o, p, q, r, s, t = 1, u, v,
w, x, y, z, tot = 0;
bool flag, flag2;
string str, str2;
bool isValid(int i, int j, vector<string>& v) { return i > -1 && i < n&& j > -1 && j < m&& v[i][j]=='.'; }
void dfs(int oldi, int oldj, vector<string>& v) {
    for (int i = 0; i < 4; i++) {
        int newi = oldi + di[i], newj = oldj + dj[i];
        if (isValid(newi, newj, v)) {
            v[newi][newj] = '#';
            dfs(newi, newj, v);
        }
    }
}
int32_t main() {
    // cin>>t;
    while (t--) {
        cin >> n >> m;
        vector<string> v(n);
        // vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isValid(i, j, v)) {
                    v[i][j] = '#';
                    dfs(i, j, v);
                    tot++;
                }
            }
        }
        cout << tot << endl;
    }
    return 0;
}