#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <queue>

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int maxDepth104(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> order;
        set<TreeNode*> visited;

        order.push(root);
        visited.insert(root);

        int depth = 0;

        while (!order.empty()) {
            depth++;

            int size = order.size();
            for (int i = 0; i < size; i++) {
                TreeNode* TopNode = order.front();

                if (TopNode->left != nullptr) order.push(TopNode->left);
                if (TopNode->right != nullptr) order.push(TopNode->right);

                order.pop();
            }
            
        }

        return depth;
    }
};

int main104(int argc, char* argv[]) {
    Solution sol = Solution();
    TreeNode a = TreeNode(1);
    TreeNode b = TreeNode(2);
    a.left = &b;
    TreeNode c = TreeNode(3);
    b.left = &c;
    //c.next = &b;
    cout << sol.maxDepth104(&a) << endl;

    return 0;
}