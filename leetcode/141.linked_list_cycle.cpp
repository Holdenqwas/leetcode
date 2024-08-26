#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>
#include <stack>


// https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle141(ListNode* head) {
        if (head == nullptr) return false;
        unordered_set<ListNode*> Set;
        unordered_set<ListNode*>::iterator it;

        while (head->next != nullptr) {
            if (Set.find(head->next) != Set.end()) {
                return true;
            }
            Set.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main141(int argc, char* argv[]) {
    Solution sol = Solution();
    ListNode a = ListNode(1);
    ListNode b = ListNode(2);
    a.next = &b;
    ListNode c = ListNode(3);
    b.next = &c;
    //c.next = &b;
    cout << sol.hasCycle141(&a) << endl;


    return 0;
}