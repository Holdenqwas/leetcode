#include <unordered_map>
#include <math.h>
#include <iostream>



// https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate219(vector<int>& nums, int k) {
        unordered_map<int, int> Dict;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            it = Dict.find(nums[i]);
            if (it == Dict.end()) {
                Dict.insert(make_pair(nums[i], i));
            }
            else {
                if (abs(i - it->second) <= k && (nums[i] == nums[it->second]))
                    return true;
                else {
                    it->second = i;
                }
            }
        }
        return false;
    }
};

int main219(int argc, char* argv[]) {
    Solution sol = Solution();

    vector<int> a{ 1,2,3,1 };
    cout << sol.containsNearbyDuplicate219(a, 3) << endl;   
    a = vector<int> { 1,0,1,1 };
    cout << sol.containsNearbyDuplicate219(a, 1) << endl;    
    a = vector<int> { 1,2,3,1,2,3 };
    cout << sol.containsNearbyDuplicate219(a, 2) << endl;

    return 0;
}