#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>
#include <stack>


// https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists21(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (list1 && !list2) return list1;
        if (list2 && !list1) return list2;

        ListNode* temp;
        if (list1->val > list2->val) {
            temp = list2;
            list2 = list2->next;
        }
        else {
            temp = list1;
            list1 = list1->next;
        }
        ListNode* head = temp;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr) temp->next = list1;
        else temp->next = list2;
        return head;
    }
};

int main21(int argc, char* argv[]) {
    Solution sol = Solution();
    ListNode c = ListNode(4);
    ListNode b = ListNode(2, &c);
    ListNode a = ListNode(1, &b);

    ListNode c2 = ListNode(4);
    ListNode b2 = ListNode(3, &c2);
    ListNode a2 = ListNode(1, &b2);

    int i = 0;
    ListNode* ans = sol.mergeTwoLists21(&a, &a2);
    
    while (i++ < 6) {
        cout << ans->val << endl;
        ans = ans->next;
    }
    

    return 0;
}