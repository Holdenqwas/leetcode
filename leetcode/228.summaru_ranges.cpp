#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>


// https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    vector<string> summaryRanges228(vector<int>& nums) {
        vector<string> out;
        if (!nums.size()) return out;
        string range = to_string(nums[0]);
        bool isNeedAdd = false;

        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - 1) != nums[i - 1]) {
                if (isNeedAdd) {
                    range += "->";
                    range += to_string(nums[i-1]);
                }
                out.push_back(range);
                range = to_string(nums[i]);
                isNeedAdd = false;
            }
            else {
                isNeedAdd = true;
            }
        }
        if (isNeedAdd) {
            range += "->";
            range += to_string(nums[nums.size() - 1]);
        }
        out.push_back(range);

        return out;
    }
};

int main228(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> t{ 0,1,2,4,5,7 };
    for (auto a : sol.summaryRanges228(t)) {
        cout << a << endl;
    }
    cout << "+++++++++++++++" << endl;
    t = vector<int>{ 0,2,3,4,6,8,9 };
    for (auto a : sol.summaryRanges228(t)) {
        cout << a << endl;
    }

    return 0;
}