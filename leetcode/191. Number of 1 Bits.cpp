#include <vector>
#include <iostream>

// https://leetcode.com/problems/number-of-1-bits/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int hammingWeight189(int n) {
        int count = 0;
        while (n) {
            if (n & 0b01) count++;
            n = n >> 1;
        }
        return count;
    }
};

int main191(int argc, char* argv[]) {
    Solution sol = Solution();
    cout << sol.hammingWeight189(11) << endl;
    cout << sol.hammingWeight189(128) << endl;
    cout << sol.hammingWeight189(2147483645) << endl;

    return 0;
}
