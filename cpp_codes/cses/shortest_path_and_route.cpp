//Labyrinth
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define pii pair<int,int>

const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
string dirs[4] = { "R", "D", "L","U" };
string rdirs[4] = { "L", "U", "R","D" };
int did[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int djd[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l = INT_MAX, m = -1, n, o, p, q, r, s, t = 1, u, v,
w, x, y, z, tot = 0, si = -1, sj, ei = 0, ej = 0;
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
        flag = false;
        cin >> n >> m;
        vector<string> v(n);
        vector<vector<int>> dir(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = 0;j<m;j++) {
                if (v[i][j]=='A') si = i, sj = j;
                else if (v[i][j]=='B') ei = i, ej = j;
            }
        }
        v[ei][ej] = '.';
        queue<pii> q;
        q.push({ si,sj });
        while (q.size()&&!flag) {
            auto cur = q.front();
            q.pop();
            for (int i = 0;i<4;i++) {
                int newi = cur.first+di[i], newj = cur.second+dj[i];
                if (isValid(newi, newj, v)) {
                    dir[newi][newj] = i;
                    v[newi][newj] = '#';
                    q.push({ newi,newj });
                    if (newi==ei&& newj==ej) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag) {
            string ans;
            while (ei^si||ej^sj) {
                int dirn = dir[ei][ej];
                ei = ei-di[dirn];
                ej = ej-dj[dirn];
                ans += dirs[dirn];
            }
            reverse(ans.begin(), ans.end());
            cout<<"YES\n"<<ans.size()<<endl<<ans<<endl;
        }
        else {
            cout<<"NO\n";
        }
    }
}