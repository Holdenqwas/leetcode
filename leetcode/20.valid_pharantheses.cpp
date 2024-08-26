#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>


// https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isValid20(string s) {
        if (!s.size() || (s.size() % 2 != 0)) return false;
        stack<char> Stack;
        char temp;
        for (char& a : s) {
            if (a == '(' || a == '{' || a == '[') {
                Stack.push(a);
            }
            else {
                temp = Stack.top();
                if (a == ')' and temp == '(') Stack.pop();
                else if (a == '}' and temp == '{') Stack.pop();
                else if (a == ']' and temp == '[') Stack.pop();
                else {
                    return false;
                }
            }
        }

        return Stack.empty();
    }
};

int main20(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.isValid20("()") << endl;
    cout << sol.isValid20("(()[]{})") << endl;
    cout << sol.isValid20("{(]}") << endl;
    cout << sol.isValid20("]") << endl;

    return 0;
}