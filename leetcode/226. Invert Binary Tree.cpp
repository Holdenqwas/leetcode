#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>

// https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
	TreeNode* invertTree226(TreeNode* root) {
		if (root == nullptr) return root;

		queue<TreeNode*> order;
		order.push(root);

		while (!order.empty()) {
			int size = order.size();

			for (int i = 0; i < size; i++) {
				TreeNode* FirstNode = order.front();

				TreeNode* temp = FirstNode->left;
				FirstNode->left = FirstNode->right;
				FirstNode->right = temp;

				if (FirstNode->left != nullptr) order.push(FirstNode->left);
				if (FirstNode->right != nullptr) order.push(FirstNode->right);

				order.pop();
			}
		}

		return root;
	}
};

int main226(int argc, char* argv[]) {
	Solution sol = Solution();
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	a.left = &b;
	TreeNode c = TreeNode(3);
	b.left = &c;

	cout << sol.invertTree226(&a) << endl;

	return 0;
}