#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l, m = -1, n, o, p, q, r, s, t = 1, u, v, w, x, y, z, tot = 0;
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
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class BaseClass {
public:
	int j;
	void disp() {
		cout<<"Function of Parent Class";
	}
};
class DerivedClass : public BaseClass {
public:
	int k;
	void disp() {
		cout<<"Function of Child Class";
	}
};
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

int32_t main() {
	BaseClass obj = DerivedClass();
	obj.j;
	cin>>t;
	while (t--) {
		// TreeNode k = TreeNode();
		// Node ll = Node();
		// Node* lll = new Node();
		// cout<<k.left<<" "<<k.right<<" "<<k.val<<" ";
		// TreeNode* l = new TreeNode(10);
		// cout<<l->left<<" "<<l->right<<" "<<l->val;
		string s = "bgf";
		if (s.find("hj")==string::npos) {
			cout<<-1;
		}
		if (s.find("gf")!=string::npos) {
			cout<<s.find("gf");
		}
	}
	return 0;
}

