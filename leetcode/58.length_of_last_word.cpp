#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int lengthOfLastWord58(string s) {
        int length = 0;
        bool bStartWord = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                bStartWord = true;
                length++;
            }
            else if (bStartWord) {
                break;
            }
        }

        return length;
    }
};

int main58(int argc, char* argv[]) {
    string Str{ "luffy is still joyboy" };

    Solution sol = Solution();
    cout << sol.lengthOfLastWord58(Str) << endl;

    return 0;
}