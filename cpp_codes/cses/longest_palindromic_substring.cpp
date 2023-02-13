// Longest Palindrome
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define pii pair<int, int>
#define REP(i, m, n) for(int i=m;i<n;i++)
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
void solve() {
    string a;
    cin >> a;
    string s = "";
    s += '@';
    s += '#';
    for (auto i : a)
        s += i, s += '#';
    s += '$';
    a = s;
    n = a.size();
    int mini[n] = { 0 };
    int c = 0, r = 0, maxi = 0;
    for (int i = 1; i < n; i++) {
        int mir = 2 * c - i;
        if (r > i) {
            mini[i] = min(r - i, mini[mir]);
        }
        while (s[i - mini[i] - 1] == s[i + mini[i] + 1]) {
            mini[i]++;
        }
        if (mini[i] + i > r) {
            r = mini[i] + i;
            c = i;
        }
        maxi = max(maxi, mini[i]);
    }
    REP(i, 0, n) {
        if (mini[i] == maxi) {
            string ans = "";
            for (int j = i - mini[i]; j <= i + mini[i]; j++) {
                if (s[j] != '#' && s[j] != '$' && s[j] != '@')
                    ans += s[j];
            }
            cout << ans;
            return;
        }
    }
}
int32_t main() {
    solve();
    // cin>>t;
    // while (t--) {
    //     tot = 1;
    //     cin >> str;
    //     // n = str.size();
    //     // int maxj, maxk = 0;
    //     // vector<vector<bool>> dp(n, vector<bool>(n, 0));

    //     // for (int i = n-1;i>-1;i--) {
    //     //     dp[i][i] = 1;
    //     //     if (i&&str[i]==str[i-1]) {
    //     //         dp[i-1][i] = 1;
    //     //         maxk = i-1;
    //     //         tot = 2;
    //     //     }
    //     // }
    //     // // for (int i = n-1;i>-1;i--) {
    //     // //     for (int j = i;j<n;j++) {
    //     // //         if (j&&i<n-1&&str[i]==str[j]&&dp[i+1][j-1]) {
    //     // //             dp[i][j] = 1;
    //     // //             if (tot< j-i+1) {
    //     // //                 tot = j-i+1;
    //     // //                 maxk = i;
    //     // //             }
    //     // //         }
    //     // //     }
    //     // // }
    //     // for (int k = 3;k<=n;k++) {
    //     //     for (int i = 0;i<n-k+1;i++) {
    //     //         j = i+k-1;
    //     //         if (dp[i+1][j-1]&&str[i]==str[j]) {
    //     //             dp[i][j] = 1;
    //     //             maxk = i;
    //     //             tot = k;
    //     //         }
    //     //     }
    //     // }
    //     // // cout<<maxk<<tot;
    //     // cout<<str.substr(maxk, tot)<<endl;
    // }
    
    return 0;
}
// int32_t main() {
//     // cin>>t;
//     while (t--) {
//         tot = -1;
//         cin >>str;
//         n = str.size();
//         int maxj, maxk;
//         for (int i = 0;i<str.size();i++) {
//             j = i, k = i-1;
//             while (k>-1&&j<n&&str[j]==str[k]) {
//                 j++;k--;
//             }
//             j--;k++;
//             if (tot<j-k+1) {
//                 tot = j-k+1;
//                 maxj = j, maxk = k;
//             }
//             j = i, k = i;
//             while (k>-1&&j<n&&str[j]==str[k]) {
//                 j++;k--;
//             }
//             j--;k++;
//             if (tot<j-k+1) {
//                 tot = j-k+1;
//                 maxj = j, maxk = k;
//             }
//         }
//         // cout<<maxj<<maxk<<tot;
//         cout<<str.substr(maxk, tot)<<endl;
//     }
//     return 0;
// }