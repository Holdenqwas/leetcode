#include <vector>
#include <iostream>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int removeDublicates80(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i, k;
        int count = 0;
        for (i = 1, k = 1; i < nums.size(); i++) {
            if (nums[k-1] == nums[i]) {
                count++;
                if (count < 2) {
                    nums[k] = nums[i];
                    k++;
                }
            }
            else {
                count = 0;
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main80(int argc, char* argv[]) {
    vector<int> nums{ 0,0,1,1,1,1,2,3,3 };

    Solution sol = Solution();
    cout << sol.removeDublicates80(nums) << endl;

    for (auto val : nums) {
        cout << val << endl;
    }
    return 0;
}