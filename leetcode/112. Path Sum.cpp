#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>
#include <stack>

// https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150

using namespace std;



struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool DFS(TreeNode* root, int sum, int targetSum) {
		if (root == nullptr) return false;
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr && sum == targetSum) return true;
		bool res;
		if (root->left != nullptr) {
			res = DFS(root->left, sum, targetSum);
			if (res) return res;
		}

		if (root->right != nullptr) {
			res = DFS(root->right, sum, targetSum);
			if (res) return res;
		}

		return false;
	}
	bool hasPathSum112(TreeNode* root, int targetSum) {
		return DFS(root, 0, targetSum);
	}
};

int main112(int argc, char* argv[]) {
	Solution sol = Solution();
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	a.left = &b;
	TreeNode c = TreeNode(3);
	b.left = &c;
	TreeNode d = TreeNode(4);
	b.right = &d;


	cout << sol.hasPathSum112(&a, 6) << endl;

	return 0;
}