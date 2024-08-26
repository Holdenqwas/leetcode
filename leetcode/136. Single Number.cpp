#include <vector>
#include <iostream>
#include <unordered_set>

// https://leetcode.com/problems/single-number/?envType=study-plan-v2&envId=top-interview-150%5C

using namespace std;

class Solution {
public:
    int singleNumber136(vector<int>& nums) {
        unordered_set<int> set;
        unordered_set<int>::iterator it;
        for (auto item : nums) {
            it = set.find(item);
            if (it == set.end()) {
                set.insert(item);
            }
            else {
                set.erase(it);
            }
        }
        return *set.begin();
    }
};

int main136(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> a{ 2,2,1 };
    cout << sol.singleNumber136(a) << endl;    
    
    vector<int> a2{ 4,1,2,1,2 };
    cout << sol.singleNumber136(a2) << endl;    

    vector<int> a3{ 1 };
    cout << sol.singleNumber136(a3) << endl;

    return 0;
}
