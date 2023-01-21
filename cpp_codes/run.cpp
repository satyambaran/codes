#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l = INT_MAX, m = -1, n, o, p, q, r, s, t = 1, u, v,
                            w, x, y, z, tot = 0;
bool flag;
string str;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int32_t main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n), inv(n), invu(n);
    tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int inv_count = 0, cover = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (v[i] > v[j]) {
          inv_count++;
          if (v[i] - v[j] == 1) {
            cover++;
          }
        }
      }
      // inv[i] = inv_count;
      // invu[i] = inv_count - cover;
    }
    // for (int i = 0; i < n; i++) {
    //   cout << inv[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //   cout << invu[i] << " ";
    // }
    // cout << endl;
    // cout << endl;
    cout << cover << endl;
  }
  return 0;
}

// int32_t main() {
//   cin >> t;
//   while (t--) {
//     cin >> a >> b;
//     cout << a - gcd(a, b) << endl;
//   }
//   return 0;
// }
