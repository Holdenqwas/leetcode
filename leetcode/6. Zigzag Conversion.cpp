#include <vector>
#include <iostream>

// https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    string convert6(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> list;
        list.reserve(numRows);
        string out = "";

        for (size_t i = 0; i < numRows; i++)
        {   
            list.push_back("");
        }

        int row = 0;
        bool increase = true;
        for (size_t i = 0; i < s.length(); i++)
        {
            list[row] += s[i];
            if (increase) row++;
            else row--;

            if (row == numRows) {
                row -= 2;
                increase = false;
            }
            else if (row == -1) {
                row+=2;
                increase = true;
            }
        }

        for (auto str : list) {
            out += str;
        }

        return out;
    }
};

int main6(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.convert6("PAYPALISHIRING", 3) << " || PAHNAPLSIIGYIR" << endl;
    cout << sol.convert6("PAYPALISHIRING", 4) << " || PINALSIGYAHRPI" << endl;
    cout << sol.convert6("A", 1) << " || A" << endl;
    cout << sol.convert6("AB", 1) << " || AB" << endl;

    return 0;
}
