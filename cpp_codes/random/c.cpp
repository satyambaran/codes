#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2000001, maxt = 100001, mod = 998244353;
int dp[maxn], ans[maxn];
int a, b, c, d, e, i, j, k, l, m = -1, n, o, p, q, r, s, t = 1, u, v, w, x, y,
                               z, tot = 0;
bool flag;
string str;
int fact[maxn];
int modInverse(int x) {
  int y = mod - 2;
  int res = 1;
  x %= mod;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    y = y >> 1;
  }
  return res;
}
int nCi(int n, int i) {
  return (((fact[n] * modInverse(fact[i])) % mod) *
          (modInverse(fact[n - i]) % mod)) %
         mod;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int di[4] = {0, 1, 0, -1};
int dj[4] = {-1, 0, 1, 0};
int dis[4] = {1, 1, -1, -1};
int djs[4] = {-1, 1, 1, -1};
int32_t main() {
  cin >> t;
  // label:
  while (t--) {
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    vector<vector<bool>> special(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; i++) {
      cin >> a >> b;
      special[a][b] = true;
    }
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (special[i - 1][j - 1]) {
          dp[i][j] = 1 + min({dp[i][j] - 1, dp[i][j - 1], dp[i - 1][j],
                              dp[i - 1][j - 1]});
        } else {
          dp[i][j] = 1 + min({dp[i][j] - 1, dp[i][j - 1], dp[i - 1][j]});
        }
      }
    }
    cout << dp[n][m] << endl;
  }
  return 0;
}
