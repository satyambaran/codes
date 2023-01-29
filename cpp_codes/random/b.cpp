#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l, m = -1, n, o, p, q, r, s, t = 1, u, v, w, x, y, z, tot = 0;
string str;
// x^p-2 % p = x^-1 %p
// x^p-1 % p =1%p
// x*2x*3x.....(p-1)x % mod = 1*2*3.....(p-1) % mod
// rand%p is between 1 to p-1
// rand*(any number between 1 to p-1)%p will lie between 1 to p-1
int fact[maxn];
int modInverse(int x) {
    int y = mod-2;
    int res = 1;
    x %= mod;
    while (y>0) {
        if (y&1) {
            res = (res*x)%mod;
        }
        x = (x*x)%mod;
        y = y>>1;
    }
    return res;
}
int nCi(int n, int i) {
    return (((fact[n]*modInverse(fact[i]))%mod)*(modInverse(fact[n-i])%mod))%mod;
}
int32_t main() {
    cin>>t;
    while (t--) {
        cin>>n>>m;
        fact[0] = 1;
        int minm = min(n, m);
        int maxm = max(n, m);
        n = minm; m = maxm;
        for (int i = 1; i <= minm; i++)
            fact[i] = (fact[i - 1] * i) % mod;
        int temp = fact[minm];
        int jk;
        for (int i = minm+1;i<=maxm;i++) {
            temp = (temp*i)%mod;
        }
        fact[n+1] = temp;
        int ans = 0;
        for (int i = 1;i<=minm;i++) {
            ans = ans + (nCi(n, i)* nCi(m, i))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// unsigned long long power(unsigned long long x, int y, int mod) {
//     unsigned long long res = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1)
//             res = (res * x) % mod;
//         y = y >> 1; // y = y/2
//         x = (x * x) % mod;
//     }
//     return res;
// }
// unsigned long long modInverse(unsigned long long n, int mod) {
//     return power(n, mod - 2, mod);
// }
// unsigned long long nCrModPFermat(unsigned long long n, int r, int mod) {
//     if (n < r)
//         return 0;
//     if (r == 0)
//         return 1;
//     unsigned long long fac[n + 1];
//     fac[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fac[i] = (fac[i - 1] * i) % mod;

//     return (fac[n] * modInverse(fac[r], mod) % mod * modInverse(fac[n - r], mod) % mod) % mod;
// }
// int djd() {
//     // mod must be a prime greater than n.
//     int n = 10, r = 2, mod = 13;
//     cout << "Value of nCr % mod is "
//         << nCrModPFermat(n, r, mod);
//     return 0;
// }