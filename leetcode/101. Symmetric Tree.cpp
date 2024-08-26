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
	bool isVectorSymmetric(vector<int>& arr, vector<bool>&arrPos) {
		int size = arr.size();
		if (size % 2 != 0) return false;
		for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
			if ((arr[i] != arr[j]) || (arrPos[i] == arrPos[j])) return false;
		}
		return true;
	};

	bool isSymmetric101(TreeNode* root) {
		if (root == nullptr) return true;

		queue<TreeNode*> order;
		order.push(root);
		vector<int> line;
		vector<bool> linePos;


		while (!order.empty()) {
			int size = order.size();

			for (int i = 0; i < size; i++) {
				TreeNode* TopNode = order.front();
				if (TopNode->left != nullptr) {
					order.push(TopNode->left);
					line.push_back(TopNode->left->val);
					linePos.push_back(true);
				}
				else {
					line.push_back(-101);
					linePos.push_back(true);
				}
				if (TopNode->right != nullptr) {
					order.push(TopNode->right);
					line.push_back(TopNode->right->val);
					linePos.push_back(false);
				}
				else {
					line.push_back(-101);
					linePos.push_back(false);
				}
				order.pop();
			}
			if (!isVectorSymmetric(line, linePos)) return false;
			line.clear();
			linePos.clear();
		}
		return true;
	}


};

int main101(int argc, char* argv[]) {
	Solution sol = Solution();
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	a.left = &b;
	TreeNode c = TreeNode(3);
	b.left = &c;
	TreeNode d = TreeNode(4);
	b.right = &d;
	
	TreeNode b2 = TreeNode(2);
	a.right = &b2;
	TreeNode c2 = TreeNode(4);
	b2.left = &c2;
	TreeNode d2 = TreeNode(3);
	b2.right = &d2;

	cout << sol.isSymmetric101(&a) << endl;

	return 0;
}