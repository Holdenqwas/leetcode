#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>
#include <stack>

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150

using namespace std;



struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void levelOrder(TreeNode* node) {
	queue<TreeNode*> order;
	order.push(node);

	while (!order.empty()) {
		TreeNode* temp = order.front();
		cout << temp->val << " -> ";
		order.pop();
		if (temp->left) order.push(temp->left);
		if (temp->right) order.push(temp->right);
	}
}
void inorder(TreeNode* node) {
	if (node) {
		inorder(node->left);
		cout << node->val << " -> ";
		inorder(node->right);
	}
};

TreeNode* newNode(int val) {
	//TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	//temp->val = val;
	//temp->left = temp->right = NULL;
	TreeNode* temp = new TreeNode(val);

	return temp;
};

int getMiddle(vector<int>& arr) {
	int middle;
	if (arr.size() <= 2) middle = 0;
	else middle = arr.size() / 2;
	return middle;
}

TreeNode* insert(TreeNode* node, int val) {
	if (node == NULL) return newNode(val);

	if (node->val > val)
		node->left = insert(node->left, val);
	else
		node->right = insert(node->right, val);

	return node;
};

TreeNode* mergeInsert(TreeNode* root, vector<int>& arr) {
	if (arr.size()) {
		int middle = getMiddle(arr);
		if (!root) {
			root = newNode(arr[middle]);
		}
		else insert(root, arr[middle]);
		vector<int> slice;
		if (middle) {
			slice = vector<int>(arr.begin(), arr.begin() + middle);
			mergeInsert(root, slice);
		}
		else if (arr.size() > 1) {
			insert(root, arr[1]);
		}
		
		if (arr.size() > 4) {
			slice = vector<int>(arr.begin() + middle + 1, arr.end());
			mergeInsert(root, slice);
		}
		else if (arr.size() > 2) {
			insert(root, arr[middle + 1]);
		}

	}
	return root;
}


class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (!nums.size()) return nullptr;

		TreeNode* root = nullptr;

		root = mergeInsert(root, nums);

		return root;
	}
};

int main208(int argc, char* argv[]) {
	Solution sol = Solution();

	vector<int> a{ -10, -3, 0, 5, 9 };
	TreeNode* aT = sol.sortedArrayToBST(a);
	//inorder(aT);
	cout << endl;
	levelOrder(aT);
	cout << endl;
	cout << endl;


	vector<int> b{ 1,3 };
	TreeNode* bT = sol.sortedArrayToBST(b);
	//inorder(bT);
	cout << endl;
	levelOrder(bT);
	cout << endl;
	cout << endl;	
	
	
	vector<int> c{ 0,1,2,3,4,5 };
	TreeNode* cT = sol.sortedArrayToBST(c);
	//inorder(cT);
	cout << endl;
	levelOrder(cT);
	cout << endl;
	cout << endl;

	return 0;
}