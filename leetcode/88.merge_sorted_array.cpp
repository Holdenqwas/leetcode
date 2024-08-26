#include <vector>
#include <iostream>

// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = n + m - 1;

        n--;
        m--;
        while (m >= 0 && n >= 0) {

            if (nums1[m] >= nums2[n]) {
                nums1[i] = nums1[m--];
            }
            else {
                nums1[i] = nums2[n--];
            }
            i--;
        }

        while (n > -1) {
            nums1[i] = nums2[n--];
            i--;
        }
    }
};

int main88(int argc, char* argv[]) {
    vector<int> nums1{ 2, 0 };
    int m = 1;
    vector<int> nums2{ 1 };
    int n = 1;

    Solution sol = Solution();
    sol.merge(nums1, m, nums2, n);

    for (auto val : nums1) {
        cout << val << endl;
    }
    return 0;
}