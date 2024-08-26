#include <vector>
#include <string>
#include <iostream>
#include <vector>


// https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;


class Solution {
public:
    vector<int> plusOne66(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 && (digits[i] + 1) == 10) {
            digits[i--] = 0;
        }
        if (i < 0) {
            digits.insert(digits.begin(), 1);
        }
        else {
            digits[i] = digits[i] + 1;
        }

        return digits;
    }
};

int main66(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int>a{ 9, 9, 9 };
    for (auto i : sol.plusOne66(a)) {
        cout << i;
    }

    return 0;
}