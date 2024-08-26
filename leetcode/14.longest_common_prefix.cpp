#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/longest-common-prefix/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    string longestCommonPrefix14(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string prefix = strs.back();
        strs.pop_back();
        int i;
        for (i = 0; i <= prefix.size(); i++) {
            for (auto word : strs) {
                if (prefix[i] != word[i]) return word.substr(0, i);
            }
        }
        return i >= prefix.size() ? prefix : "";
    }
};

int main14(int argc, char* argv[]) {
    vector<string> strs{ "flower","flower","flower","flower" };


    Solution sol = Solution();
    cout << sol.longestCommonPrefix14(strs) << endl;

    return 0;
}