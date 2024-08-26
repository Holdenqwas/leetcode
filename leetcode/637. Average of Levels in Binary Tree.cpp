#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>
#include <stack>

// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
	vector<double> averageOfLevels637(TreeNode* root) {
		vector <double> arr;
		if (root == nullptr) return arr;

		queue<TreeNode*> order;
		double sum = 0;

		order.push(root);

		while (!order.empty()) {
			int size = order.size();

			for (int i = 0; i < size; i++) {
				TreeNode* node = order.front();
				sum += node->val;

				if (node->left != nullptr) order.push(node->left);
				if (node->right != nullptr) order.push(node->right);

				order.pop();
			}
			arr.push_back(sum / size);
			sum = 0.0;
		}
		return arr;
	}
};

int main637(int argc, char* argv[]) {
	Solution sol = Solution();
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	a.left = &b;
	TreeNode c = TreeNode(3);
	a.right = &c;
	TreeNode d = TreeNode(4);
	b.left = &d;


	for (auto a : sol.averageOfLevels637(&a)) {
		cout << a << endl;
	}

	return 0;
}