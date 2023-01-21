#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int main() {
    int n, target; cin>>n>>target;
    vector<int> coins(n);
    for (int i = 0;i<n;i++) {
        cin>>coins[i];
    }
    dp[0] = 0;
    for (int i = 1;i<=target;i++) {
        dp[i] = 100001;
        for (int j = 0;j<n;j++) {
            if (i-coins[j]>=0) dp[i] = min(dp[i], 1+dp[i-coins[j]]);
        }
    }
    if (dp[target]==INT_MAX)cout<<"-1";
    else cout<<dp[target];
    return 0;
    // If 1st egg broke on ith floor,  one egg will have to check i-1
    // If on ith floor egg didnt break then will have 2 eggs and have t check n-i;

    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=i;j++)
            dp[i] = min(j, dp[i-j]);
}