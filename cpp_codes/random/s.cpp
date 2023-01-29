#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 10000002, maxt = 100002, mod = 1000000007;
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l, m = -1, n, o, p, q, r, s, t = 1, u, v, w, x, y,
                               z, tot = 0, sum;
bool flag;
string str;

int fun(int k, int sum) {
  int i = 0;
  for (int i = 0; i < 1000; i++) {
    int totsum = (pow(k, i + 1) - 1) / (k - 1);
    if (totsum >= sum)
      return i + 1;
  }
  return 1000;
}
struct obj {
  int val;
  int par;
  vector<int> scores;
  int mult = 1;
};
int32_t main() {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> graph = vector<vector<int>>(n + 1);
    vector<int> values, num, deno;

    values.push_back(-1);
    for (int i = 0; i < n; i++) {
      cin >> a;
      values.push_back(a);
    }
    for (int i = 0; i < n - 1; i++) {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    queue<obj> q;
    obj first;
    first.val = 1;
    first.par = -1;
    first.scores.push_back(values[1]);
    first.mult = graph[1].size();
    q.push(first);
    while (q.size()) {
      int len = q.size();
      while (len--) {
        auto cur = q.front();
        q.pop();
        flag = false;
        for (auto child : graph[cur.val]) {
          if (child == cur.par)
            continue;
          obj qObj;
          qObj.par = cur.val;
          qObj.scores = cur.scores;
          qObj.scores.push_back(values[child]);
          qObj.val = child;
          qObj.mult = cur.mult * (graph[child].size() - 1);
          flag = true;
          q.push(qObj);
        }
        if (!flag) {
          deno.push_back(cur.mult);
          int total = 0;
          for (auto k : cur.scores) {
            total ^= k;
          }
          int maxm = 0;
          for (auto k : cur.scores) {
            maxm = max(maxm, total ^ k);
          }
          num.push_back(maxm);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < deno.size(); i++) {
      ans += (1.0 * num[i] / deno[i]);
    }
    cout << ans << endl;
  }
  return 0;
}

// x^p-2 % p = x^-1 %p
// x^p-1 % p =1%p
// x*2x*3x.....(p-1)x % mod = 1*2*3.....(p-1) % mod
// rand%p is between 1 to p-1
// rand*(any number between 1 to p-1)%p will lie between 1 to p-1
// int fact[maxn];
// int modInverse(int x) {
//     int y = mod-2;
//     int res = 1;
//     while (y>0) {
//         if (y%2) {
//             res = (res*x)%mod;
//             y--;
//         }
//         x = (x*x)%mod;
//         y /= 2;
//     }
//     return res;
// }
// int nCi(int n, int i) {
//     return
//     (fact[n]*(modInverse(fact[i])%mod)*(modInverse(fact[n-i])%mod))%mod;
// }
// int32_t main() {
//     cin>>t;
//     while (t--) {
//         cin>>n>>m;
//         if (n>=maxn||m>=maxn) {
//             cout<<"maxn\n";
//             continue;
//         }
//         fact[0] = 1;
//         for (int i = 1; i <= n; i++)
//             fact[i] = (fact[i - 1] * i) % mod;
//         int minm = min(n, m);
//         int ans = 0;
//         j = -m; // j= x-y
//         while (j%3) j++;
//         for (int i = j;i<=n;i += 3) {
//             a = m-i;
//             b = n+i;
//             cout<<a<<b<<endl;
//             minm = min(a, b);
//             // int st;
//             // if (j<0) st = -j;
//             // else st = 0;
//             // for (int y = st;y<=m;y++) {
//             //     x = y+i;
//             //     if (x==0&&y==0) continue;
//             //     else if (x<=n) {
//             ans = (ans+nCi(n+m, minm)%mod)%mod;
//             //     }
//             // }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }