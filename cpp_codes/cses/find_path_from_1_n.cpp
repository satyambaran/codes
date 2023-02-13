#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define pii pair<int, int>
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int did[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int djd[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l = INT_MAX, m = -1, n, o, p, q, r, s, t = 1, u, v,
w, x, y, z, tot = 0, si = -1, sj, ei = 0, ej = 0;
bool flag, flag2;
string str, str2;
bool isValid(int i, int j, vector<string>& v) {
    return i > -1 && i < n&& j > -1 && j < m&& v[i][j] == '.';
}
int32_t main() {
    // cin>>t;
    while (t--) {
        tot = 0;
        flag = false;
        cin >> n >> m;
        vector<vector<int>> v(n);
        vector<int> reachedFrom(n, -1);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            --a, --b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        reachedFrom[0] = 0;
        while (q.size() && !flag) {
            auto cur = q.front();
            q.pop();
            for (auto child : v[cur]) {
                if (reachedFrom[child] == -1) {
                    q.push(child);
                    reachedFrom[child] = cur;
                    if (child == n - 1) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag) {
            vector<int> ans;
            n = n-1;
            while (n != 0) {
                ans.push_back(n);
                n = reachedFrom[n];
            }
            cout << ans.size()+1 << endl<<"1 ";
            for (int i = ans.size() - 1; i > -1; i--) {
                cout << ans[i]+1 << " ";
            }
        }
        else {
            cout << "IMPOSSIBLE\n";
        }

    }
    return 0;
}