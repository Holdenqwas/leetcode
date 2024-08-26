#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>
#include <stack>


// https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;


class Solution {
public:
    bool isPalindrome9(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        string temp = to_string(x);
        for (int i = 0; i < temp.size() / 2; i++) {
            if (temp[i] != temp[temp.size() - i - 1]) return false;
        }
        return true;
    }
};

int main9(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.isPalindrome9(121) << endl;
    cout << sol.isPalindrome9(-121) << endl;
    cout << sol.isPalindrome9(10) << endl;

    return 0;
}