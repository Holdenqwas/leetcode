#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isPalindrome125(string s) {
        if (s.size() == 1 && isspace(s[0])) return true;

        for (int i = 0, j = s.size() - 1; i < s.size() && j >= 0; i++) {
            char a = s[i];
            char b = s[j];

            if (isalpha(s[i]) || isdigit(s[i])) {
                while (isalpha(s[j]) == isdigit(s[j])) {

                    j--;
                    b = s[j];
                }

                if (j < 0) return true;

                if (tolower(s[i]) != tolower(s[j])) return false;
                j--;
            }

        }
        return true;
    }
};

int main125(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.isPalindrome125("0P") << endl;
    cout << sol.isPalindrome125("aa") << endl;
    cout << sol.isPalindrome125("A man, a plan, a canal : Panama") << endl;
    cout << sol.isPalindrome125("v' 5:UxU:5 v'") << endl;

    return 0;
}