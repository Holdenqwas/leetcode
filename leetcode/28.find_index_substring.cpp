#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int strStr28(string haystack, string needle) {
        int i, j = 0;
        for (i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[j]) {
                j++;
                if (j == needle.size()) {
                    return i - j + 1;
                }
            }
            else {
                if (j) {
                    i = i - j;
                    j = 0;
                }
            }
        }
        return -1;
    }
};

int main28(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.strStr28("ppi", "pi") << endl;

    return 0;
}