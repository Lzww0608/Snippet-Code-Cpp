#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode():val(0), lchild(nullptr),rchild(nullptr){}
	TreeNode(int v) :val(v), lchild(nullptr), rchild(nullptr) {}
};
int K;
vector<string>input;
vector<string>output;
unordered_map<int, vector<int>>m;
TreeNode* root = new TreeNode();

void buildTree(const vector<string>& nodes) {
	if (nodes.empty() || nodes[0] == "null") return;
	root->val = stoi(nodes[0]);
	queue<TreeNode*>q;
	q.emplace(root);
	int i = 1, n = nodes.size();
	while (i < n && !q.empty()) {
		TreeNode* t = q.front();
		q.pop();
		if (i < n && nodes[i] != "null") {
			t->lchild = new TreeNode(stoi(nodes[i]));
			q.emplace(t->lchild);
		}
		i++;
		if (i < n && nodes[i] != "null") {
			t->rchild = new TreeNode(stoi(nodes[i]));
			q.emplace(t->rchild);
		}
		i++;
	}
}

void findPath_Prefix(TreeNode* root, int d, int sum, vector<int>path) {
	if (!root) return;
	sum += root->val + d;
	path.push_back(root->val);
	if (m.count(sum-K) == 1) {
		for (auto x : m[sum-K]) {
			string s;
			for (int i = x+1; i < path.size(); i++) {
				s += to_string(path[i]) + " ";
			}
			output.push_back(s);
		}
	}
	m[sum].push_back(path.size()-1);
	findPath_Prefix(root->lchild, d + 1, sum, path);
	findPath_Prefix(root->rchild, d + 1, sum, path);
	m[sum].pop_back();
}


void findPath(TreeNode* root, int d, int sum, vector<int>path) {
	sum += root->val + d;
	path.push_back(root->val);
	if (sum == K) {
		string s;
		for (auto x : path) {
			s += to_string(x) + " ";
		}
		output.push_back(s);
	}
	if (root->lchild) {
		findPath(root->lchild, d + 1, sum, path);
	}
	if (root->rchild) {
		findPath(root->rchild, d + 1, sum, path);
	}
}


void findPathNode(TreeNode* root,int d) {
	if (!root) return;
	findPath(root, d, 0, vector<int>{});
	findPathNode(root->lchild, d + 1);
	findPathNode(root->rchild, d + 1);
}

int main() {
	m[0].push_back(0);
	cin >> K;
	cin.ignore();
	string line;
	getline(cin, line);
	stringstream ss(line);
	string node;
	while (ss >> node) {
		input.push_back(node);
	}
	buildTree(input);
	vector<int>path;
	path.push_back(0);
	//findPathNode(root, 0); // 暴力搜索 O(n^2)
	//findPath_Prefix(root, 0, 0, path); // 前缀和 一次遍历 O(n)
	for (auto& x : output) {
		cout << x << endl;
	}
	return 0;
}
