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
	// cin >> t;
	while (t--) {
		cin >> n; tot = 0;
		vector<int> v(n);
		for (int i = 0;i<n;i++) {
			cin>>v[i];
			q = sqrt(v[i]);
			if (q*q==v[i]) {
				tot += q;
			}
		}
	}
	cout<<tot<<endl;

	return 0;
}
