#include <bits/stdc++.h>
using namespace std;
#define int long long
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val, Node* left = nullptr, Node* right = nullptr) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
int32_t main() {
    int val = 5;
    Node* left = new Node(val++);
    Node* right = new Node(val++);
    Node* root = new Node(val++, left, right);
    cout<<root->val<<" "<<root->right->val<<" "<<root->left->val;
}