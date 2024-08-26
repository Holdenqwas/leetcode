#include <vector>
#include <iostream>

// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int removeDublicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i, k;
        for (i = 1, k = 1; i < nums.size(); i++) {
            if (nums[i-1] != nums[i]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main26(int argc, char* argv[]) {
    vector<int> nums{ 1, 1, 2, 2, 3, 4 };

    Solution sol = Solution();
    cout << sol.removeDublicates(nums) << endl;

    for (auto val : nums) {
        cout << val << endl;
    }
    return 0;
}