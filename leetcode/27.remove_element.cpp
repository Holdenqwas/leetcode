#include <vector>
#include <iostream>

// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, k;
        for (i = 0, k = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                if (i != k) {
                    nums[k] = nums[i];
                }
                k++;
            }
        }
        return k;
    }
};

int main27(int argc, char* argv[]) {
    vector<int> nums{ 2, 1 };
    int m = 1;

    Solution sol = Solution();
    cout<<sol.removeElement(nums, m) << endl;

    for (auto val : nums) {
        cout << val << endl;
    }
    return 0;
}