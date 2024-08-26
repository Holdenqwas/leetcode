#include <vector>
#include <string>
#include <iostream>

// https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int romanToInt13(string s) {
        int LastIndex = s.size() - 1;
        int Value = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i])
            {
            case 'I':
                if (i != LastIndex && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    Value -= 1;
                } else {
                    Value += 1;
                }
                break;
            case 'X':
                if (i != LastIndex && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    Value -= 10;
                }
                else {
                    Value += 10;
                }
                break;
            case 'C':
                if (i != LastIndex && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    Value -= 100;
                }
                else {
                    Value += 100;
                }
                break;
            case 'V':
                Value += 5;
                break;
            case 'L':
                Value += 50;
                break;
            case 'D':
                Value += 500;
                break;
            case 'M':
                Value += 1000;
                break;
            default:
                break;
            }
               
        }
        return Value;
    }
};

int main13(int argc, char* argv[]) {
    string Str{ "MCMXCIV" };

    Solution sol = Solution();
    cout << sol.romanToInt13(Str) << endl;

    return 0;
}