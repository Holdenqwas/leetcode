#include <vector>
#include <iostream>

// https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000

class Solution {
public:
    string intToRoman12(int num) {
        string ans = "";
        vector<char> vals{ 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
        int delimetr = 1000;
        int index = 0;
        
        while (num) {
            int cur_val = num / delimetr;

            if (cur_val == 4) {
                ans += vals[index];
                ans += vals[index - 1];
            }
            else if (cur_val == 9) {
                ans += vals[index];
                ans += vals[index - 2];
            }
            else if (cur_val == 5) {
                ans += vals[index - 1];
            }
            else if (cur_val < 4 && cur_val > 0) {
                ans.append(cur_val, vals[index]);
            }
            else if (cur_val > 5) {
                ans += vals[index - 1];
                ans.append(cur_val - 5, vals[index]);
            }
            num %= delimetr; 
            delimetr /= 10;
            index += 2;
        }
        return ans;
    }
};

int main12(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.intToRoman12(3749) << " MMMDCCXLIX" << endl;

    cout << sol.intToRoman12(58) << " LVIII" << endl;

    cout << sol.intToRoman12(1994) << " MCMXCIV" << endl;

    return 0;
}
