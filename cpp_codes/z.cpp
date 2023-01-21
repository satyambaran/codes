#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l, m = -1, n, o = 0, p, q, r, s, t = 1, u, v, w, x, y, z, tot = 0;
bool flag;
string str;
int gcd(int mx, int mn) {
    if (mx<mn) {
        w = mx;
        mx = mn;
        mn = w;
    }
    // cout<<mx<<mn;
    if (mx%mn) return gcd(mn, mx%mn);
    else return mn;
}
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return (double)p1.first/p1.second>(double)p2.first/p2.second;
}

int32_t main() {
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<pair<int, int>> st(n);
        for (int i = 0;i<n;i++) {
            cin>>st[i].first;
        }
        for (int i = 0;i<n;i++) {
            cin>>st[i].second;
        }
        sort(st.begin(), st.end(), compare);

        int sum = 0;
        int length = st[0].first;
        for (int i = 1;i<st.size();i++) {
            sum = sum+(length*st[i].second);
            length = (length+st[i].first);

        }
        cout<<sum<<endl;
    }
    return 0;
}

// int32_t main() {
//     cin>>t;
//     while (t--) {
//         cin>>a>>b>>c;
//         vector<int> aBit, bBit, cBit;
//         i = 0;
//         tot = 0;
//         if (a<b) {
//             e = b;
//             b = a;
//             a = e;
//         }
//         while (a||c) {
//             if (a&1) {
//                 aBit.push_back(1);
//             }
//             else {
//                 aBit.push_back(0);
//             }
//             if (b&1) {
//                 bBit.push_back(1);
//             }
//             else {
//                 bBit.push_back(0);
//             }
//             if (c&1) {
//                 cBit.push_back(1);
//             }
//             else {
//                 cBit.push_back(0);
//             }
//             i++;
//             a /= 2;b /= 2;c /= 2;
//         }
//         i = 0;
//         int msb = log2(c);
//         while (msb>-1) {
//             msb--;
//             if (c&(1<<msb)) {
//                 if (diffBit.back()==msb) {
//                     diffBit.pop_back();
//                 }
//             }
//         }
//     }
//     return 0;
// }
