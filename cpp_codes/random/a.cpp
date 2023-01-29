// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int maxn = 2000001, maxt = 200001, mod = 1e9+7;
// // vector<int> dp[maxt][maxt], ans[maxn];
// int dp[maxt], ans[maxn];
// int a, b, c, d, e, i, j, k, l, m = -1, n, o, p, q, r, s, t = 1, u, v, w, x, y, z, tot = 0;
// struct obj {
// 	int st;
// 	int end;
// 	int money;
// };
// bool comp(obj a, obj b) {
// 	return a.end<b.end;
// }
// string str, str1;
// int find(vector<obj>& v, int n) {
// 	int l = 0, r = n-1, mid = l+(r-l)/2, m = -1;
// 	while (l<=r) {
// 		mid = l+(r-l)/2;
// 		if (v[mid].end>=v[n].st) {
// 			r = mid-1;
// 		}
// 		else {
// 			m = mid;
// 			l = mid+1;
// 		}
// 	}
// 	if (m!=-1) return m;
// 	return -1;
// }
// int32_t main() {
// 	int n;
// 	cin >> n;
// 	vector<obj>v;
// 	for (int i = 0;i<n;i++) {
// 		obj temp;
// 		cin>>a>>b>>c;
// 		temp.st = a;
// 		temp.end = b;
// 		temp.money = c;
// 		v.push_back(temp);
// 	}
// 	sort(v.begin(), v.end(), comp);
// 	dp[0] = v[0].money;
// 	for (int i = 1;i<n;i++) {
// 		m = v[i].money;
// 		int idx = find(v, i);
// 		if (idx==-1) {
// 			dp[i] = m;
// 		}
// 		else {
// 			dp[i] = m+dp[idx];
// 		}
// 		dp[i] = max(dp[i], dp[i-1]);
// 	}
// 	cout<<dp[n-1];
// 	return 0;
// }
// C++ program to convert binary to decimal
#include <bits/stdc++.h>
#define int long long
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(string s) {
	int base = 1;
	int num = 0;
	for (int i = 0;i<s.size();i++) {
		if (s[i]!=' ')num *= 2;
		if (s[i]=='1')num += 1;
	}

	return num;
}
string decimalToBinary(int k) {
	string s = "";
	while (k) {
		if (k%2) {
			s = s+'1';
		}
		else {
			s = s+'0';
		}
		k = k>>1;
	}
	reverse(s.begin(), s.end());
	return s;
}

int32_t main() {
	string s = "000000 001000 011110 111111 111111 011011 001100";
	int k = binaryToDecimal(s);
	s = decimalToBinary(k);
	cout <<k<<endl<< s << endl<<binaryToDecimal(s) << endl;
}
