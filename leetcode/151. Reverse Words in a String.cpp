#include <vector>
#include <iostream>

// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    string reverseWords151(string s) {
        string out = "";
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                if (temp.size()) {
                    out = temp + (out.size() ? " " : "") + out;
                    temp = "";
                }
                continue;
            }
                
            temp += c;
        }
        if (temp.size()) out = temp + (out.size() ? " " : "") + out;
        return out;
    }
};

int main151(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.reverseWords151("the sky is blue") << " || blue is sky the" << endl;
    cout << sol.reverseWords151("  hello world  ") << " || world hello" << endl;
    cout << sol.reverseWords151("a good   example") << " || example good a" << endl;
    cout << sol.reverseWords151("EPY2giL") << "||EPY2giL" << endl;

    return 0;
}
