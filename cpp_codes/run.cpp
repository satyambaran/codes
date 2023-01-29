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
		cin >> str;
		flag = false;
		bool flag2 = false, flag3 = false;
		tot = 0;
		a = 0, b = 0, c = 0;
		i = 0;
		if (str[0] == '1') {
			while (str[i] == '1')
			{
				a++;
				i++;
				c = getOnes(str, i);
			}
			cout << a + c << endl;
		}
		else {
			c = getOnes(str, 0);
			cout << c << endl;
		}
	}

	return 0;
}
