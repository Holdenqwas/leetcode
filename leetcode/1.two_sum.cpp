#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>


// https://leetcode.com/problems/two-sum/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> answer;
        if (nums.size() == 2) {
            answer.push_back(0);
            answer.push_back(1);
            return answer;
        };

        int i, j;
        for (i = 0; i < nums.size(); i++) {
            for (j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                if ((nums[i] + nums[j]) == target) {
                    answer.push_back(i);
                    answer.push_back(j);

                    return answer;
                }
            }
        }
        return answer;
    }

    //vector<int> twoSum(vector<int>& nums, int target) {
    //    unordered_map<int, int> mp;
    //    for (int i = 0; i < nums.size(); i++) {
    //        if (mp.find(nums[i]) == mp.end()) {
    //            mp.insert({ nums[i], i });
    //        }
    //        if (mp.find(target - nums[i]) != mp.end()) {
    //            if (i != mp[target - nums[i]]) return { i, mp[target - nums[i]] };
    //        }
    //    }
    //    return {};
    //}
};

int main1(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> a{ 3,2,4 };
    int b = 6;

    vector<int> c =  sol.twoSum1(a, b);
    for (auto val : c) {
        cout << val << endl;
    }
    


    return 0;
}