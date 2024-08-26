#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>
#include <stack>

// https://leetcode.com/problems/count-complete-tree-nodes/?envType=study-plan-v2&envId=top-interview-150

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
	int countNodes222(TreeNode* root) {
		if (root == nullptr) return 0;

		stack<TreeNode*> order;
		order.push(root);

		int level = 0;
		int minus_count = 0;
		int count = 0;

		bool isNeedbreak = false;

		while (!order.empty()) {
			TreeNode* node = order.top();
			order.pop();


			if (node->left != nullptr) { order.push(node->left); }
			else {
				minus_count++;
			}


			if (node->right != nullptr) { order.push(node->right); }
			else {
			    minus_count++;
			}
			if (!isNeedbreak) {
				count += pow(2, level);
				level++;

			}
			if (node->left == nullptr || node->right == nullptr)
			{
				isNeedbreak = true;
			}
			if (isNeedbreak && node->right != nullptr && node->left != nullptr) break;
		}
		count += pow(2, level);
		return count - minus_count;
	}
};

int main222(int argc, char* argv[]) {
	Solution sol = Solution();
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	a.left = &b;
	TreeNode c = TreeNode(3);
	a.right = &c;
	TreeNode d = TreeNode(4);
	b.left = &d;


	cout << sol.countNodes222(&a) << endl;

	return 0;
}