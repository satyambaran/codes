#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<int> cnt(26, 0);
	for (auto ch : str) {
		cnt[ch - 'a']++;
	}
	int lastI = -1;
	bool flag = false;
	int l = 0, r = 25, lf = -1, rf = -1;
	while (l <= r) {
		if (cnt[l] % 2) {
			lf = l;
		}
		else {
			l++;
		}
		if (cnt[r]%2) {
			rf = r;
		}
		else {
			r--;
		}
		if (lf != -1 && rf != -1) {
			cnt[lf]++;
			cnt[rf]--;
			lf = -1;
			rf = -1;
			l++;
			r--;
		}
	}
	if (flag) {
		cnt[lastI]--;
	}
	int n = str.size();
	str = "";
	char odd = 'a';
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			str = str + string(cnt[i] / 2, 'a' + i);
		}
		if (cnt[i] % 2)
			odd = 'a' + i;
	}
	string s = str;
	reverse(str.begin(), str.end());
	if (n % 2) {
		s = s + odd;
	}
	s = s + str;
	cout << s << endl;

	return 0;
}