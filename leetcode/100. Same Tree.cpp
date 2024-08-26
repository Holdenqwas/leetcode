#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>


#include <queue>

// https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
	bool isSameTree100(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr || q == nullptr) return false;

		queue<TreeNode*> p_q;
		queue<TreeNode*> q_q;

		p_q.push(p);
		q_q.push(q);

		while (!p_q.empty()) {
			int size_p = p_q.size();
			int size_q = q_q.size();
			if (size_p != size_q) return false;

			for (int i = 0; i < size_p; i++) {
				TreeNode* front_p = p_q.front();
				TreeNode* front_q = q_q.front();

				if (front_p->val != front_q->val) return false;

				if (front_p->left != nullptr) { p_q.push(front_p->left); }
				else if (front_p->left != front_q->left) return false;

				if (front_p->left != nullptr) {
					q_q.push(front_q->left);
				}
				else if (front_p->left != front_q->left) return false;

				if (front_p->right != nullptr) { p_q.push(front_p->right); }
				else if (front_p->right != front_q->right) return false;

				if (front_q->right != nullptr) {
					q_q.push(front_q->right);
				}


				p_q.pop();
				q_q.pop();
			}

		}


		return true;
	}
};

int main100(int argc, char* argv[]) {
	Solution sol = Solution();
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	a.left = &b;
	TreeNode c = TreeNode(3);
	b.left = &c;

	TreeNode a2 = TreeNode(1);
	TreeNode b2 = TreeNode(2);
	a2.left = &b2;
	TreeNode c2 = TreeNode(3);
	b2.left = &c2;
	//c.next = &b;
	cout << sol.isSameTree100(&a, &a2) << endl;

	return 0;
}