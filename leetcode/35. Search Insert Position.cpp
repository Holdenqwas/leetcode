#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int searchBin(vector<int>& nums, int low, int hight, int target) {
        int middle = -1;
        while (low <= hight) {
            middle = (hight - low) / 2 + low;

            if (nums[middle] == target) return middle;

            if (nums[middle] < target) {
                low = middle + 1;
            }
            else
            {
                hight = middle - 1;
            }
        }
        return low;
    }
    int searchInsert35(vector<int>& nums, int target) {
        if (!nums.size()) return 0;

        return searchBin(nums, 0, nums.size() - 1, target);
    }
};

int main35(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> arr{ 1,3,5,6 };
    cout << sol.searchInsert35(arr, 5) << 2<< endl;

    vector<int> arr2{ 1,3,5,6 };
    cout << sol.searchInsert35(arr2, 2) << 1<< endl;

    vector<int> arr3{ 1,3,5,6 };
    cout << sol.searchInsert35(arr3, 7) << 4<< endl;
    
    vector<int> arr4{ 1,3 };
    cout << sol.searchInsert35(arr4, 2) << 1<< endl;

    return 0;
}