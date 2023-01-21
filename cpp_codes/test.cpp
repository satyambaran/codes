#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e15+2
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define mod1 998244353
const int maxn = 504;
#define vpll  vector<pair<ll,ll>>
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define pob pop_back
#define lb lower_bound
#define ld long double
#define ub upper_bound
#define LB 60
#define setp(x) cout<<fixed<<setprecision(x)
#define PQ_MIN  priority_queue <ll, vector<ll>, greater<ll> >
#define setbit(x)   __builtin_popcount(x)
#define all(x) (x).begin(),(x).end()
#define pie 3.14159265358
#define enter(a)   for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a)     for(ll e: a) cout<<e<<" "; cout<<"\n";
#define pii pair<ll,ll>
using vi = vector<int>;
ll power(ll n, ll p) {
    ll r = 1;
    while (p) {
        if (p%2) {
            r = (r*n)%mod;
            p--;
        }
        p = p/2;
        n = (n*n)%mod;
    }
    return r;
}
ll quer(int a, int b, int c) {

    cout<<"? "<<a<<" "<<b<<" "<<c<<"\n";
    fflush(stdout);
    int k;
    cin >> k;
    return k;

}

const int N = 1e5+5;
int n, m;
char v[104][104];
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int dp[104][104][3];
bool valid(int x, int y) {
    return (x>=0&&x<n&& y>=0&&y<m);
}
int get_ans(int x, int y) {

    if (valid(x, y))
        return v[x][y] == '1';
    return 0;
}
int sol(int x, int y, int f) {
    if (x==n)
        return 1e6;
    if (y == m)
        return 1e6;
    if (x == n-1 && y==m-1) {
        int ans = 0;
        if (v[x][y]=='1')
            ans++;
        for (int i = 0;i<4;i++) {
            ans += get_ans(x+dx[i], y+dy[i]);
        }
        if (f == 1) {
            ans -= get_ans(x-1, y+1);
        }
        if (f==2) {
            ans -= get_ans(x+1, y-1);
        }
        return ans;
    }
    if (dp[x][y][f]!=-1)
        return dp[x][y][f];
    int ans = 0;

    for (int i = 0;i<4;i++) {
        ans += get_ans(x+dx[i], y+dy[i]);
    }
    int c = 0, d = 0;
    if (f == 1) {
        c -= get_ans(x-1, y+1);
    }
    if (f==2) {
        d -= get_ans(x+1, y-1);
    }
    int ans1 = ans+d;
    int ans2 = ans+c;
    ans1 += sol(x+1, y, 1)-get_ans(x+1, y);
    ans2 += sol(x, y+1, 2)-get_ans(x, y+1);
    // ans+=min(sol(x+1,y,1)+d,sol(x,y+1,2)+c-get_ans(x,y+1));
   //  cout<<ans1<<" "<<ans2<<"\n";
    dp[x][y][f] = min(ans1, ans2);
    return dp[x][y][f];
}
int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {

        ll i, j, k, l;
        cin >> n >> m;
        for (i = 0;i<n;i++) {
            for (j = 0;j<m;j++)
                cin>>v[i][j];
        }
        memset(dp, -1, sizeof(dp));
        //cout<<valid(1,0)<<" ";
        cout<<sol(0, 0, 0)<<"\n";



    }





}


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int maxn = 2000001, maxt = 100001, mod = 1000000007;
// int dp[maxn], ans[maxn];
// int a, b, c, d, e, i, j, k, l, m = -1, n, o, p, q, r, s, t = 1, u, v, w, x, y, z, tot = 0;
// string str;
// vector<string> maze;
// int di[4] = { 0,-1,0,1 };
// int dj[4] = { -1,0,1,0 };
// bool isValid(int i, int j) {
// 	return i>-1&&j>-1&&i<n&& j<m;
// }
// bool isScared(int i, int j) {
// 	int ni, nj;
// 	for (int k = 0;k<4;k++) {
// 		ni = i+di[k];
// 		nj = j+dj[k];
// 		if (isValid(ni, nj)) {
// 			if (maze[ni][nj]==1) return true;
// 		}
// 	}
// 	return false;
// }
// int32_t main() {
// 	cin>>t;
// 	while (t--) {
// 		cin>>n>>m;
// 		maze.clear();
// 		maze.resize(n);
// 		for (int i = 0;i<n;i++) {
// 			cin>>maze[i];
// 		}
		
// 	}
// 	return 0;
// }
