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
    // cin >> t;
    while (t--) {
        tot = 0;
        cin >> n >> m;
        vector<vector<int>> v(n);
        vector<int> par(n, -1), parList;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            --a, --b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i = 0; i < n; i++) {
            if (par[i] == -1) {
                par[i] = i;
                parList.push_back(i+1);
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int len=q.size();
                    while(len--){
                        int cur = q.front();
                        q.pop();
                        for (auto child: v[cur]) {
                            if (par[child]==-1) {
                                par[child] = i;
                                q.push(child);
                            }
                        }
                    }
                }
            }
        }
        cout<<parList.size()-1<<endl;
        for (int i = 1;i<parList.size();i++) {
            cout<<parList[0]<<" "<<parList[i]<<endl;
        }
    }
    return 0;
}