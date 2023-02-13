#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();

		// Case 1 :
		if (k == 0 || prices.size() < 2) {
			return 0;
		}

		// Case 2 :
		int maxProfit = 0;
		if (n < k * 2) {
			for (int i = 1; i < prices.size(); i++) {
				if (prices[i - 1] < prices[i]) {
					maxProfit += prices[i] - prices[i - 1];
				}
			}
			return maxProfit;
		}

		vector<int> dp((2 * k));
		dp[0] = -prices[0];

		for (int i = 1; i < 2 * k; i++) {
			if (i % 2 == 0) {
				dp[i] = INT_MIN;
			}
			else {
				dp[i] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * k; j++) {
				if (j == 0) {
					dp[j] = max(dp[j], -prices[i]);
				}
				else if (j % 2 == 0) {
					dp[j] = max(dp[j], dp[j - 1] - prices[i]);
				}
				else {
					dp[j] = max(dp[j], dp[j - 1] + prices[i]);
				}
			}
		}
		return dp[2 * k - 1];
	}
};
int main() {
	string name = "satyam";
	string name2 = "satyaprakash";
	string s = "flam";
	int k = 5;
	while (s.size() > 1) {

		string news;
		int to_remove = s.size() % k;
		if (s.size() == 1) {
			cout << s << endl;
			break;
		}
	}
	int i = 0, n = name.size(), m = name2.size();
	while (i < n && i < m && name[i] == name2[i]) {
	}
	return 0;
}