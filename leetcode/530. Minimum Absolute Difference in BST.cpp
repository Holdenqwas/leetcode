#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>
#include <stack>

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150

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
	void inOrder(TreeNode* node, vector<int>& arr) {
		if (node != nullptr) {
			inOrder(node->left, arr);
			arr.push_back(node->val);
			inOrder(node->right, arr);
		}
	}
	int getMinimumDifference530(TreeNode* root) {
		vector<int> arr;
		inOrder(root, arr);
		int minimum = INT_MAX;
		for (int i = 0; i < arr.size() - 1; i++) {
			minimum = min(minimum, arr[i + 1] - arr[i]);
		}
		return minimum;
	}
};

int main530(int argc, char* argv[]) {
	{
		Solution sol = Solution();
		TreeNode a = TreeNode(2);
		TreeNode b = TreeNode(1);
		a.left = &b;
		TreeNode c = TreeNode(3);
		a.right = &c;
		TreeNode d = TreeNode(0);
		b.left = &d;


		cout << sol.getMinimumDifference530(&a) << endl;
	}
	{
		Solution sol = Solution();
		TreeNode a = TreeNode(236);
		TreeNode b = TreeNode(104);
		a.left = &b;
		TreeNode c = TreeNode(227);
		b.right = &c;
		TreeNode d = TreeNode(701);
		a.right = &d;
		TreeNode e = TreeNode(911);
		d.right = &e;

		cout << sol.getMinimumDifference530(&a) << endl;
	}

	return 0;
}