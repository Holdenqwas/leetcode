#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isSubsequence392(string s, string t) {
        if (!s.size()) return true;
        if (!t.size()) return false;
        int i, j = 0;
        for (i = 0; i < t.size() && j < s.size(); i++) {
            if (t[i] == s[j]) {
                j++;
            }
            if (j == s.size()) return true;
        }
        
        return false;
    }
};

int main392(int argc, char* argv[]) {
    Solution sol = Solution();
    //cout << sol.isSubsequence392("abc", "ahbgdc") << endl;
    cout << sol.isSubsequence392("axc", "ahbgdc") << endl;

    return 0;
}