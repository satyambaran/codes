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

int getOnes(string str, int id) {
	int maxm = 0, cur = 0;
	for (int i = id; i < str.size(); i++) {
		if (str[i] == '1') {
			cur++;
		}
		else {
			maxm = max(cur, maxm);
			cur = 0;
		}
	}
	return maxm;
}

int32_t main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n);
		if (n==2) {
			cout<<"343 -343\n";
		}
		else {
			v[0] = 1;
			v[n-1] = -1;
			int ls = 1, rs = -1;
			for (int i = 1;i<(n/2);i++) {
				if (i%2) {
					v[i] = -1;
					v[n-i-1] = ls-rs;
					ls++;
					rs += v[n-i-1];
				}
				else {
					v[i] = 1;
					v[n-i-1] = ls-rs;
					ls++;
					rs += v[n-i-1];
				}
			}
			for (int i = 0;i<n;i++) {
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}
